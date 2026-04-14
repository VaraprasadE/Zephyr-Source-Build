UART Flow Readme
################

Overview
********

This document explains the end-to-end UART flow used by
``APPS/uart_stream_processor`` on the NXP FRDM-MCXN947 board.

It covers:

* how Devicetree and Kconfig become generated C macros,
* how Zephyr creates and initializes the UART driver before ``main()``,
* how the UART API crosses from application code into the driver layer,
* how the MCXN947 LPUART hardware is touched at register level, and
* how bytes move through this application from the UART pins to the parser,
  queue, processing task, and back to the memory pool.

Toy Robot Story
***************

Think of Zephyr like building a toy robot.

* ``YAML`` is the label sheet.
   It tells Zephyr what a kind of part is supposed to look like.

* ``Binding`` is the rulebook.
   It tells Zephyr how to understand a hardware part described in Devicetree.

* ``DTS`` is the robot parts map.
   It says which real parts are on the board, like which UART exists and which
   pins it uses.

* ``Kconfig`` is the switch panel.
   It turns software features on or off, like serial support or UART
   interrupts.

* ``Driver API`` is the set of buttons the programmer presses.
   The app says things like "send a byte" or "enable UART RX interrupt".

* ``Driver`` is the helper inside the robot.
   It takes the API request and talks to the real hardware registers.

* ``App`` is your robot's behavior.
   In this project, the app receives UART bytes, builds frames, puts them into
   pool nodes, sends them to another task, and processes them.

Very short version:

* ``YAML / binding`` = rules
* ``DTS`` = board map
* ``Kconfig`` = on/off switches
* ``API`` = buttons for the programmer
* ``Driver`` = worker that controls hardware
* ``App`` = your logic

Simple Flow
===========

.. code-block:: text

    YAML/binding
         -> teaches Zephyr the rules
    DTS
         -> says what hardware is on the board
    Kconfig
         -> says what software features to build
    Driver
         -> gets created from that information
    API
         -> gives the app a clean way to ask for UART actions
    App
         -> uses UART to do useful work

Board And UART Selection
************************

This application uses:

* board: ``frdm_mcxn947/mcxn947/cpu0``
* UART node: ``DT_CHOSEN(zephyr_shell_uart)``
* chosen UART instance on this board: ``flexcomm4_lpuart4``

In the application source:

.. code-block:: c

   #define UART_DEVICE_NODE DT_CHOSEN(zephyr_shell_uart)
   static const struct device *const uart_dev = DEVICE_DT_GET(UART_DEVICE_NODE);

That means the app does not hard-code a peripheral base address. It asks
Zephyr for the UART chosen by the board's Devicetree.

Build-Time Configuration Flow
*****************************

Zephyr uses two parallel configuration pipelines.

1. Devicetree pipeline
======================

The board DTS files describe hardware instances, chosen devices, clocks,
interrupts, and pin routing.

For FRDM-MCXN947:

* ``frdm_mcxn947_mcxn947_cpu0.dtsi`` selects:

  .. code-block:: dts

     zephyr,console = &flexcomm4_lpuart4;
     zephyr,shell-uart = &flexcomm4_lpuart4;

* ``frdm_mcxn947.dtsi`` sets board-level UART properties:

  .. code-block:: dts

     &flexcomm4_lpuart4 {
         current-speed = <115200>;
         pinctrl-0 = <&pinmux_flexcomm4_lpuart>;
         pinctrl-names = "default";
     };

* ``frdm_mcxn947-pinctrl.dtsi`` maps UART signals to pins:

  .. code-block:: dts

     pinmux_flexcomm4_lpuart {
         group0 {
             pinmux = <FC4_P0_PIO1_8>,
                      <FC4_P1_PIO1_9>;
         };
     };

The Devicetree compiler and Zephyr scripts convert that into generated macros
inside the build directory, for example:

.. code-block:: c

   #define DT_CHOSEN_zephyr_shell_uart \
       DT_N_S_soc_S_peripheral_50000000_S_flexcomm_b4000_S_lpuart_b4000

So when the app writes ``DT_CHOSEN(zephyr_shell_uart)``, it ultimately becomes
the generated node identifier for ``flexcomm4_lpuart4``.

2. Kconfig pipeline
===================

Kconfig enables software features and driver support.

This application sets in ``prj.conf``:

.. code-block:: cfg

   CONFIG_SERIAL=y
   CONFIG_UART_INTERRUPT_DRIVEN=y

During the build, Zephyr merges:

* board defaults,
* SoC defaults,
* driver defaults,
* kernel defaults,
* application ``prj.conf``

into:

* ``build/zephyr/.config``
* ``build/zephyr/include/generated/zephyr/autoconf.h``

Example generated results:

.. code-block:: c

   #define CONFIG_SERIAL 1
   #define CONFIG_UART_INTERRUPT_DRIVEN 1
   #define CONFIG_SERIAL_INIT_PRIORITY 50

These Kconfig macros control which UART APIs are enabled and when the driver is
initialized.

Important Difference
====================

Devicetree describes the hardware instance.
Kconfig enables the software support around that hardware.

You need both:

* DTS says which UART exists and how it is wired.
* Kconfig says whether the serial driver and interrupt API are compiled in.

Driver Creation Before main()
*****************************

The NXP MCUX LPUART driver is implemented in:

* ``ZWS/zephyr/drivers/serial/uart_mcux_lpuart.c``

That driver declares:

.. code-block:: c

   #define DT_DRV_COMPAT nxp_lpuart

At the bottom of the file, Zephyr creates one device instance for each enabled
``nxp,lpuart`` Devicetree node:

.. code-block:: c

   DEVICE_DT_INST_DEFINE(n,
                         mcux_lpuart_init,
                         NULL,
                         &mcux_lpuart_##n##_data,
                         &mcux_lpuart_##n##_config,
                         PRE_KERNEL_1,
                         CONFIG_SERIAL_INIT_PRIORITY,
                         &mcux_lpuart_driver_api);

   DT_INST_FOREACH_STATUS_OKAY(LPUART_MCUX_INIT)

This is the key boot-time step.

It means:

* Zephyr scans all enabled ``nxp,lpuart`` nodes.
* It creates a ``struct device`` for each one.
* It runs ``mcux_lpuart_init()`` before ``main()``.
* It stores the device API table so calls like ``uart_poll_out()`` can reach
  the correct driver implementation.

During ``mcux_lpuart_init()``
=============================

The driver:

* copies the DT-derived UART settings into Zephyr runtime structures,
* configures the clock source,
* enables the UART clock,
* reads the clock frequency,
* calls ``LPUART_Init(...)`` from the NXP HAL,
* applies pinctrl state for the selected UART pins,
* installs the ISR configuration, and
* leaves the UART ready before the application begins.

So by the time ``main()`` runs, ``uart_dev`` already points to an initialized
driver-backed UART device.

Application Setup Flow
**********************

When this application starts, ``main()`` performs the app-specific setup:

1. Check that the chosen UART device is ready.
2. Initialize the circular RX buffer.
3. Initialize the static memory pool.
4. Reset frame parsing state.
5. Create the parser thread.
6. Create the processing thread.
7. Register ``serial_cb`` as the UART interrupt callback.
8. Enable UART RX interrupts.

At that point the application-specific data path is live.

The API Boundary: App To Driver
*******************************

The public UART API lives in ``include/zephyr/drivers/uart.h``.

There are two important categories of calls used by this app.

Syscall-style API
=================

Examples:

* ``uart_poll_out()``
* ``uart_irq_rx_enable()``
* ``uart_irq_update()``

These are declared with ``__syscall`` in the public header.

In a userspace-enabled Zephyr build, the call path is conceptually:

.. code-block:: text

   Application thread
      -> generated syscall wrapper
      -> argument and object validation
      -> privilege transition to kernel mode
      -> driver API table dispatch
      -> concrete driver implementation

For this specific application build, however:

.. code-block:: text

   CONFIG_USERSPACE is not set

So there is no real user-mode to kernel-mode privilege switch at runtime in the
current build. The API still uses the syscall abstraction, but this app is
executing in supervisor mode.

Inline driver-dispatch API
==========================

Some UART APIs used here are ``static inline`` helpers, such as:

* ``uart_fifo_read()``
* ``uart_irq_callback_user_data_set()``

These typically dispatch through the device's driver API table directly.

This matters for interrupt-driven UART operation because FIFO functions are
expected to be used inside ISR context.

Interrupt Receive Path In This App
**********************************

The receive flow for this application is:

.. code-block:: text

   Physical RX pin
      -> MCXN947 LPUART peripheral
      -> hardware status flag / interrupt
      -> Zephyr UART driver ISR
      -> application callback serial_cb()
      -> circular buffer
      -> semaphore wakeup
      -> parser thread
      -> static memory pool node
      -> message queue
      -> processing thread
      -> node returned to pool

Step-by-step
============

1. Byte arrives on the UART RX pin.
2. The MCXN947 LPUART hardware shifts in the serial bits and sets RX-ready
   status.
3. Because ``uart_irq_rx_enable(uart_dev)`` was called, an interrupt is raised.
4. Zephyr's MCUX UART driver ISR runs.
5. The ISR calls the callback registered by
   ``uart_irq_callback_user_data_set(uart_dev, serial_cb, NULL)``.
6. ``serial_cb()`` calls ``uart_irq_update(dev)``.
7. ``serial_cb()`` checks ``uart_irq_rx_ready(dev)``.
8. ``serial_cb()`` drains bytes using ``uart_fifo_read(dev, &c, 1)``.
9. Each byte is pushed into the circular buffer.
10. The semaphore wakes the parser thread.
11. The parser thread reconstructs frames.
12. When a complete frame is found, it acquires a node from the static pool.
13. The frame is copied into the node and sent through the message queue.
14. The processing thread receives the node.
15. The processing thread handles the frame and returns the node to the pool.

Why The ISR Stays Short
=======================

The ISR does only the time-sensitive work:

* acknowledge the interrupt path,
* read bytes from UART hardware,
* push bytes into the circular buffer,
* wake a thread.

It does not do frame parsing, queue management, or packet processing. That is a
good RTOS design because it keeps interrupt latency under control.

Driver ISR To Application Callback
**********************************

The driver ISR is ``mcux_lpuart_isr()``.

For interrupt-driven operation, it eventually calls:

.. code-block:: c

   if (data->callback) {
       data->callback(dev, data->cb_data);
   }

That callback is your application's ``serial_cb()``.

So the handoff is:

.. code-block:: text

   MCXN947 IRQ
      -> mcux_lpuart_isr()
      -> registered callback pointer
      -> serial_cb()

This is the exact point where the generic Zephyr driver layer transfers control
into your application logic.

How Hardware Registers Are Manipulated
**************************************

The Zephyr driver does not usually write raw numeric addresses directly in the
application-facing code. Instead it uses the NXP MCUX HAL.

Examples from the driver:

* ``LPUART_Init(config->base, &uart_config, clock_freq)``
* ``LPUART_EnableInterrupts(config->base, mask)``
* ``LPUART_DisableInterrupts(config->base, mask)``
* ``LPUART_GetStatusFlags(config->base)``
* ``LPUART_ReadByte(config->base)``
* ``LPUART_WriteByte(config->base, c)``

Here, ``config->base`` is the memory-mapped base address for the specific UART
instance, taken from Devicetree:

.. code-block:: c

   .base = (LPUART_Type *) DT_INST_REG_ADDR(n)

That means the driver instance for ``flexcomm4_lpuart4`` gets a typed pointer
to the MCXN947 UART register block.

Example: Transmit Path
======================

When the app calls:

.. code-block:: c

   uart_poll_out(uart_dev, byte);

the driver eventually reaches ``mcux_lpuart_poll_out()``.

That function:

1. polls the TX-ready status flag,
2. waits until the transmit data register is empty,
3. calls ``LPUART_WriteByte(config->base, c)``,
4. which writes the byte into the UART transmit register.

After that, the hardware serializer shifts the bits out on the TX pin.

Example: Receive Path
=====================

When the app ISR calls:

.. code-block:: c

   uart_fifo_read(dev, &c, 1);

the driver reaches ``mcux_lpuart_fifo_read()``.

That function loops while the RX data-ready flag is set and performs:

.. code-block:: c

   rx_data[num_rx++] = LPUART_ReadByte(config->base);

That is the point where one byte is physically copied from the MCU UART data
register into RAM owned by the application.

How Pins Actually Toggle
************************

There are two distinct stages.

1. Pin mux setup
================

During initialization, ``pinctrl_apply_state(...)`` selects the alternate pin
function for the UART pins.

On this board, the pinctrl file maps:

* TX to ``FC4_P0_PIO1_8``
* RX to ``FC4_P1_PIO1_9``

This tells the SoC pin multiplexing hardware to connect those package pins to
the Flexcomm4 LPUART peripheral instead of plain GPIO.

2. Peripheral-driven signal changes
===================================

After pin muxing is applied, the UART peripheral owns the pin behavior.

When software writes a byte using ``LPUART_WriteByte(...)``:

* the byte enters the transmit register,
* the UART hardware shifts start bit, data bits, optional parity, and stop bit,
* the TX pin is toggled electrically by the peripheral hardware.

The CPU does not bit-bang the pin directly. The CPU configures the peripheral,
then the peripheral toggles the pin according to UART timing.

Complete End-To-End Lifecycle For One Packet
********************************************

For this application, one incoming frame follows this lifecycle:

.. code-block:: text

   External sender
      -> FRDM-MCXN947 UART RX pin
      -> flexcomm4_lpuart4 peripheral
      -> RX interrupt
      -> Zephyr MCUX LPUART ISR
      -> serial_cb()
      -> circular buffer
      -> parser thread
      -> frame assembly
      -> static_memory_pool_acquire()
      -> copy frame into node
      -> k_msgq_put()
      -> processing thread
      -> print / process frame
      -> static_memory_pool_release()

This is the actual architecture implemented by the current
``uart_stream_processor`` application.

What Belongs To Zephyr vs What Belongs To The App
*************************************************

Zephyr platform responsibilities:

* parse Devicetree,
* generate macros,
* merge Kconfig,
* instantiate the UART device,
* initialize clocks and pinctrl,
* provide UART APIs,
* handle driver ISR dispatch.

Application responsibilities:

* define frame format,
* buffer received bytes,
* parse complete frames,
* allocate and release pool nodes,
* queue packets between tasks,
* process and print the result.

Current Build Caveat
********************

This explanation includes the conceptual user-space syscall boundary because
that is part of Zephyr's design.

However, in the current build:

* ``CONFIG_USERSPACE`` is disabled,

so this app is running in supervisor mode. The UART API still follows the same
driver model, but there is no actual user-to-kernel privilege transition at
runtime.

Useful Files To Read Next
*************************

If you want to trace the flow in code, these are the main files:

* ``src/main.c``
* ``lib/include/circular_buffer.h``
* ``lib/include/static_memory_pool.h``
* ``lib/src/static_memory_pool.c``
* ``ZWS/zephyr/include/zephyr/drivers/uart.h``
* ``ZWS/zephyr/drivers/serial/uart_mcux_lpuart.c``
* ``ZWS/zephyr/boards/nxp/frdm_mcxn947/frdm_mcxn947_mcxn947_cpu0.dtsi``
* ``ZWS/zephyr/boards/nxp/frdm_mcxn947/frdm_mcxn947.dtsi``
* ``ZWS/zephyr/boards/nxp/frdm_mcxn947/frdm_mcxn947-pinctrl.dtsi``

Zephyr RTOS Primitives Cheat Sheet
**********************************

This section gives a short and simple overview of common Zephyr RTOS building
blocks used in applications like this one.

Thread Creation
***************

Zephyr threads are like workers. Each worker runs its own function.

Common pieces:

* ``K_THREAD_STACK_DEFINE(name, size)``
  Reserve memory for a thread stack.

* ``struct k_thread thread_data;``
  Holds the thread control data.

* ``k_thread_create(...)``
  Starts a thread at runtime.

Example:

.. code-block:: c

   K_THREAD_STACK_DEFINE(parser_stack, 1024);
   static struct k_thread parser_thread_data;

   static void parser_thread(void *arg1, void *arg2, void *arg3)
   {
       while (1) {
       }
   }

   k_thread_create(&parser_thread_data,
                   parser_stack,
                   K_THREAD_STACK_SIZEOF(parser_stack),
                   parser_thread,
                   NULL, NULL, NULL,
                   5,
                   0,
                   K_NO_WAIT);

There is also a shortcut macro:

* ``K_THREAD_DEFINE(...)``
  Define and start a thread in one step.

Stack
*****

Each thread needs its own stack.

Think of a stack as the worker's desk space.
If the desk is too small, the worker crashes.

Common macros:

* ``K_THREAD_STACK_DEFINE(name, size)``
* ``K_THREAD_STACK_SIZEOF(name)``

Message Queue
*************

Message queues are mailboxes.
One thread puts messages in, another thread takes them out.

Common APIs:

* ``K_MSGQ_DEFINE(name, msg_size, max_msgs, align)``
* ``k_msgq_put(&msgq, &item, timeout)``
* ``k_msgq_get(&msgq, &item, timeout)``

Example:

.. code-block:: c

   K_MSGQ_DEFINE(frame_queue, sizeof(static_pool_node *), 8, 4);

   static_pool_node *node;
   k_msgq_put(&frame_queue, &node, K_NO_WAIT);
   k_msgq_get(&frame_queue, &node, K_FOREVER);

Useful queue-like objects:

* ``k_msgq`` for fixed-size messages
* ``k_fifo`` for pointer-based FIFO passing
* ``k_queue`` for general-purpose queued data

Semaphore
*********

Semaphores are door signals.
One context says, "work is ready", and another context wakes up.

Common APIs:

* ``K_SEM_DEFINE(name, initial_count, limit)``
* ``k_sem_give(&sem)``
* ``k_sem_take(&sem, timeout)``

Example:

.. code-block:: c

   K_SEM_DEFINE(uart_data_ready, 0, 16);

   k_sem_give(&uart_data_ready);
   k_sem_take(&uart_data_ready, K_FOREVER);

Semaphores are often used between ISR and thread.

Mutex
*****

Mutexes protect shared data.
If two threads try to change the same thing at once, a mutex makes them take
turns.

Common APIs:

* ``K_MUTEX_DEFINE(name)``
* ``k_mutex_lock(&mutex, timeout)``
* ``k_mutex_unlock(&mutex)``

Example:

.. code-block:: c

   K_MUTEX_DEFINE(shared_lock);

   k_mutex_lock(&shared_lock, K_FOREVER);
   /* change shared data */
   k_mutex_unlock(&shared_lock);

Important rule:

* do not use a mutex from ISR context.

Queue vs Semaphore vs Mutex
***************************

Use:

* ``k_msgq`` when you want to send data
* ``k_sem`` when you want to send a signal
* ``k_mutex`` when you want to protect shared data

Preemptive vs Cooperative Threads
*********************************

Zephyr has two main thread scheduling styles.

Preemptive thread
=================

A preemptive thread can be interrupted by a higher-priority ready thread.

In Zephyr:

* priority ``0`` or positive value means preemptive

Examples:

* ``0``
* ``1``
* ``5``

In this app, a priority like ``5`` is preemptive.

Cooperative thread
==================

A cooperative thread keeps running until it:

* sleeps,
* blocks,
* yields,
* or finishes.

In Zephyr:

* negative priority means cooperative

Examples:

* ``-1``
* ``-2``

How To Change A Thread From Preemptive To Cooperative
=====================================================

Just change the priority from positive to negative.

Example:

.. code-block:: c

   #define PARSER_THREAD_PRIORITY 5

becomes:

.. code-block:: c

   #define PARSER_THREAD_PRIORITY -1

That changes the thread from preemptive to cooperative.

Simple rule:

* negative priority = cooperative
* zero or positive priority = preemptive

When To Use Which
=================

Use preemptive threads when:

* you want normal RTOS behavior,
* higher-priority work must interrupt lower-priority work.

Use cooperative threads when:

* you want a thread to run until it willingly gives up the CPU,
* you want very controlled scheduling.

Be careful with cooperative threads because a bad loop can starve other work.

Helpful Time Macros
*******************

Zephyr uses timeout helpers like:

* ``K_NO_WAIT``
* ``K_FOREVER``
* ``K_MSEC(x)``
* ``K_USEC(x)``
* ``K_SECONDS(x)``

These are used in thread sleeps, semaphore waits, queue waits, and mutex locks.

Quick Memory Trick
******************

You can remember the main tools like this:

* thread = worker
* stack = worker desk
* queue = mailbox
* semaphore = bell or signal
* mutex = lock on a shared box
* cooperative = polite worker who keeps going until it chooses to stop
* preemptive = worker who can be interrupted by a more important worker
