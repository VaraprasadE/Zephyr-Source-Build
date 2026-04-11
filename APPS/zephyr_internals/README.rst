Zephyr Internals Demo
#####################

Overview
********

This application demonstrates Zephyr kernel internals on
``frdm_mcxn947/mcxn947/cpu0`` using the FRDM-MCXN947 on-board P3T1755DP
temperature sensor and two application threads.

The demo includes:

#. A producer thread that reads live temperature values from the on-board
   P3T1755DP sensor through Zephyr's sensor API
#. A message queue used to pass samples between threads
#. A semaphore used to wake the consumer when data is ready
#. A mutex used to protect shared state and terminal output
#. A consumer thread that reads from the queue and prints the received data

Board Sensor Path
*****************

The FRDM-MCXN947 board DTS already enables ``i3c1``. This application overlay
adds the on-board P3T1755DP sensor under that controller and binds the app to
the ``ambient-temp0`` alias.

Building and Running
********************

Use a pristine rebuild so the previous I2C-based overlay does not remain in the
generated devicetree:

.. zephyr-app-commands::
   :zephyr-app: apps/Zephyr_Internals
   :board: frdm_mcxn947/mcxn947/cpu0
   :goals: build flash
   :compact:

Equivalent command line:

.. code-block:: console

   west build -b frdm_mcxn947/mcxn947/cpu0 -p always

After flashing, open the serial console and verify that:

* the application starts without the earlier I2C detection failure
* ``sensor_thread`` prints live temperature samples
* ``queue_thread`` prints the same samples after removing them from the queue

If the sensor still does not respond after a pristine rebuild, the remaining
issue is no longer the old I2C overlay. At that point the next step is to check
the exact I3C device identity from the board schematic or with a low-level bus
scan.Zephyr Internals Demo
#####################

Overview
********

This application demonstrates Zephyr kernel internals on
``frdm_mcxn947/mcxn947/cpu0`` using the board's on-board P3T1755DP temperature
sensor and two application threads.

The demo includes:

#. A producer thread that probes the enabled FRDM-MCXN947 I2C buses for the
   on-board P3T1755DP at address ``0x48`` and then reads live temperature data
#. A message queue used to pass samples between threads
#. A semaphore used to wake the consumer when data is ready
#. A mutex used to protect shared state and terminal output
#. A consumer thread that reads from the queue and prints the received data

Why this approach
*****************

The FRDM-MCXN947 product page lists an on-board ``P3T1755`` temperature sensor,
but the Zephyr board DTS in this checkout does not model that device yet.

To avoid binding the sensor to the wrong bus, this sample probes the board's
enabled I2C controllers at runtime and selects the bus that responds at
``0x48``.

Building and Running
********************

Build and flash the sample with:

.. zephyr-app-commands::
   :zephyr-app: apps/Zephyr_Internals
   :board: frdm_mcxn947/mcxn947/cpu0
   :goals: build flash
   :compact:

After flashing, open the serial console and verify that:

* the startup line reports which I2C bus the P3T1755DP was found on
* ``sensor_thread`` prints live temperature samples
* ``queue_thread`` prints the same samples after removing them from the queue

If the application reports that no on-board P3T1755DP was detected, the board's
sensor may be wired through a controller path not represented by the enabled
Zephyr board DTS yet. In that case the next step is to map the exact board
connection from the schematic and add the correct bus node.Zephyr Internals Demo
#####################

Overview
********

This application demonstrates Zephyr kernel internals on
``frdm_mcxn947/mcxn947/cpu0`` using a real temperature sensor source and two
application threads.

The demo includes:

#. A producer thread that reads temperature values from a P3T1755DP sensor
#. A message queue used to pass samples between threads
#. A semaphore used to wake the consumer when data is ready
#. A mutex used to protect shared state and terminal output
#. A consumer thread that reads from the queue and prints the received data

The sample keeps the threading model simple while replacing mock data with a
Zephyr sensor driver.

Hardware Assumption
*******************

The application overlay enables a ``nxp,p3t1755`` device at address ``0x48`` on
the FRDM-MCXN947 Arduino I2C bus. This matches Zephyr's P3T1755DP Arduino I2C
shield wiring pattern.

If your hardware uses a different bus or address, update
``boards/frdm_mcxn947_mcxn947_cpu0.overlay`` before building.

Requirements
************

You need:

#. A Zephyr tree with ``frdm_mcxn947`` board support
#. A P3T1755DP temperature sensor connected on the Arduino I2C header
#. A serial terminal connected to the board console

Building and Running
********************

Build and flash the sample with:

.. zephyr-app-commands::
   :zephyr-app: apps/Zephyr_Internals
   :board: frdm_mcxn947/mcxn947/cpu0
   :goals: build flash
   :compact:

After flashing, open the serial console and verify that:

* ``sensor_thread`` prints real temperature samples from the P3T1755DP sensor
* ``queue_thread`` prints the same samples after removing them from the queue
* queue-full messages appear if the producer outruns the consumer

Implementation Notes
********************

The implementation uses :c:func:`sensor_sample_fetch`,
:c:func:`sensor_channel_get`, :c:func:`k_thread_create`,
:c:func:`k_msgq_put`, :c:func:`k_msgq_get`, :c:func:`k_sem_give`,
:c:func:`k_sem_take`, and :c:func:`k_mutex_lock` /
:c:func:`k_mutex_unlock` in one application.Zephyr Internals Demo
#####################

Overview
********

This application demonstrates Zephyr kernel internals on
``frdm_mcxn947/mcxn947/cpu0`` using two application threads.

The demo includes:

#. A producer thread that generates mock sensor samples
#. A message queue used to pass samples between threads
#. A semaphore used to wake the consumer when data is ready
#. A mutex used to protect shared state and terminal output
#. A consumer thread that reads from the queue and prints the received data

This keeps the example focused on thread communication and synchronization
without depending on a real sensor driver.

You will see producer messages, consumer messages, and queue-full messages on
the terminal when the producer outpaces the consumer.

Requirements
************

You need:

#. A Zephyr tree with ``frdm_mcxn947`` board support
#. A serial terminal connected to the board console

Building and Running
********************

Build and flash the sample with:

.. zephyr-app-commands::
   :zephyr-app: apps/Zephyr_Internals
   :board: frdm_mcxn947/mcxn947/cpu0
   :goals: build flash
   :compact:

After flashing, open the serial console and verify that both threads are
printing. The producer prints generated mock sensor samples, and the consumer
prints the same samples after removing them from the queue.

Implementation Notes
********************

The implementation uses :c:func:`k_thread_create`, :c:func:`k_msgq_put`,
:c:func:`k_msgq_get`, :c:func:`k_sem_give`, :c:func:`k_sem_take`, and
:c:func:`k_mutex_lock` / :c:func:`k_mutex_unlock` to demonstrate the requested
kernel primitives in one application.

You can later replace the mock sensor generator with a real ADC or sensor read
path while keeping the same queue and synchronization structure... zephyr:code-sample:: blinky
   :name: Blinky
   :relevant-api: gpio_interface

   Blink an LED forever using the GPIO API.

Overview
********

The Blinky sample blinks an LED forever using the :ref:`GPIO API <gpio_api>`.

The source code shows how to:

#. Get a pin specification from the :ref:`devicetree <dt-guide>` as a
   :c:struct:`gpio_dt_spec`
#. Configure the GPIO pin as an output
#. Toggle the pin forever

See :zephyr:code-sample:`pwm-blinky` for a similar sample that uses the PWM API instead.

.. _blinky-sample-requirements:

Requirements
************

Your board must:

#. Have an LED connected via a GPIO pin (these are called "User LEDs" on many of
   Zephyr's :ref:`boards`).
#. Have the LED configured using the ``led0`` devicetree alias.

Building and Running
********************

Build and flash Blinky as follows, changing ``reel_board`` for your board:

.. zephyr-app-commands::
   :zephyr-app: samples/basic/blinky
   :board: reel_board
   :goals: build flash
   :compact:

After flashing, the LED starts to blink and messages with the current LED state
are printed on the console. If a runtime error occurs, the sample exits without
printing to the console.

Build errors
************

You will see a build error at the source code line defining the ``struct
gpio_dt_spec led`` variable if you try to build Blinky for an unsupported
board.

On GCC-based toolchains, the error looks like this:

.. code-block:: none

   error: '__device_dts_ord_DT_N_ALIAS_led_P_gpios_IDX_0_PH_ORD' undeclared here (not in a function)

Adding board support
********************

To add support for your board, add something like this to your devicetree:

.. code-block:: DTS

   / {
   	aliases {
   		led0 = &myled0;
   	};

   	leds {
   		compatible = "gpio-leds";
   		myled0: led_0 {
   			gpios = <&gpio0 13 GPIO_ACTIVE_LOW>;
                };
   	};
   };

The above sets your board's ``led0`` alias to use pin 13 on GPIO controller
``gpio0``. The pin flags :c:macro:`GPIO_ACTIVE_LOW` mean the LED is on when
the pin is set to its low state, and off when the pin is in its high state.

Tips:

- See :dtcompatible:`gpio-leds` for more information on defining GPIO-based LEDs
  in devicetree.

- If you're not sure what to do, check the devicetrees for supported boards which
  use the same SoC as your target. See :ref:`get-devicetree-outputs` for details.

- See :zephyr_file:`include/zephyr/dt-bindings/gpio/gpio.h` for the flags you can use
  in devicetree.

- If the LED is built in to your board hardware, the alias should be defined in
  your :ref:`BOARD.dts file <devicetree-in-out-files>`. Otherwise, you can
  define one in a :ref:`devicetree overlay <set-devicetree-overlays>`.
