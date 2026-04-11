UART Stream Processor
#####################

Overview
********

``uart_stream_processor`` is a Zephyr application intended for real-time UART
data ingestion and staged processing. The project is structured around an
interrupt-driven receive path, a deterministic memory model, and multiple
threads that separate parsing, processing, and output responsibilities.

The current repository still contains an early interrupt-driven UART example in
``src/main.c``. This document captures the target project plan and the intended
runtime architecture for the full application.

Project Pipeline
****************

The planned data path is shown below:

.. code-block:: text

   UART Interrupt (ISR)
      |
      v
   Circular Buffer (ISR -> Task Bridge)
      |
      v
   Semaphore Signal (Data Ready)
      |
      v
   Parser Task (Thread 1)
      |
      v
   Memory Pool Allocation (Static Linked List)
      |
      v
   Message Queue (Inter-Task Communication)
      |
      v
   Processing Task (Thread 2)
      |
      v
   Logging / Display Task (Thread 3)

Detailed Flow
*************

UART Interrupt (ISR)
====================

* Receives incoming serial data byte-by-byte.
* Pushes bytes into a circular buffer.
* Signals data availability through a semaphore.

Circular Buffer
===============

* Acts as the bridge between ISR context and thread context.
* Keeps the receive path non-blocking and real-time safe.
* Supports bursty UART traffic without forcing work inside the ISR.

Semaphore Signaling
===================

* Wakes the parser task when new UART data is available.
* Avoids polling loops and unnecessary CPU usage.
* Keeps synchronization between interrupt and thread contexts explicit.

Parser Task
===========

* Reads bytes from the circular buffer.
* Detects frame boundaries and assembles complete packets.
* Requests packet storage from a static memory pool.

Memory Pool
===========

* Stores parsed packets in pre-allocated linked-list nodes.
* Avoids heap allocation and runtime fragmentation.
* Preserves deterministic behavior under sustained load.

Message Queue
=============

* Transfers packet pointers from the parser task to the processing task.
* Decouples packet production from packet consumption.
* Allows each thread to run at its own bounded pace.

Processing Task
===============

* Validates packets before use.
* Performs operations such as checksum validation, filtering, or packet
  classification.
* Prepares processed results for downstream reporting.

Logging / Display Task
======================

* Consumes processed output as the final stage in the pipeline.
* Sends data to a console, storage backend, or UI layer.
* Centralizes visibility and debugging output away from time-critical stages.

RTOS Components
***************

The planned Zephyr primitives are:

* Threads for parser, processing, and logging stages.
* UART RX interrupt for byte capture.
* Semaphore for ISR-to-task signaling.
* Message queue for inter-task communication.
* Mutex protection for shared resources when required.
* Static memory pool for deterministic packet storage.

Key Design Goals
****************

* Interrupt-driven receive path for responsive serial handling.
* Lock-free or minimal-lock buffering between ISR and threads.
* Deterministic memory usage through static allocation.
* Scalable multi-threaded structure for future feature growth.
* Robust behavior under high-speed serial traffic.

Implementation Notes
********************

The design intentionally separates responsibilities so that:

* the ISR stays short and predictable,
* parsing is isolated from downstream processing,
* ownership of packet buffers is explicit, and
* final output does not block time-sensitive receive logic.

This makes the application easier to extend with protocol decoding, packet
validation, telemetry, and alternate output backends.

Building and Running
********************

Build and flash the application as follows, replacing
``frdm_mcxn947/mcxn947/cpu0`` with your target board:

.. zephyr-app-commands::
   :zephyr-app: APPS/uart_stream_processor
   :board: frdm_mcxn947/mcxn947/cpu0
   :goals: build flash
   :compact:

At the moment, the checked-in implementation is still a simple UART interrupt
sample. As the pipeline is implemented, this README should be kept aligned with
the concrete thread layout, buffer sizes, frame format, and queue depth used by
the application.
