# Real-Time Adaptive Music Player (ESP32-S3 + FreeRTOS)

## Overview

A smart embedded audio system built on the ESP32-S3 using FreeRTOS. The device plays music in real time while concurrently handling multiple peripherals including a sound sensor, RFID authentication, IR remote input, and LCD status display. The system automatically adjusts playback volume based on ambient noise using signal smoothing and calibration.

## Key Features

* Dual-core FreeRTOS task scheduling for responsive, non-blocking operation
* Automatic volume control based on live microphone / sound sensor input
* RFID-based authentication for manual control access
* IR remote support for volume and song navigation
* 16x2 I2C LCD for live system status and song information
* Thread-safe shared state using mutexes and semaphores
* Event-driven architecture using queues and timers

## Hardware Components

* ESP32-S3
* Buzzer / speaker output
* Sound sensor (analog input)
* MFRC522 RFID reader
* IR receiver + remote
* 16x2 I2C LCD
* Power supply / USB

## Software Stack

* Arduino C++
* FreeRTOS
* ESP32 LEDC PWM audio output
* SPI / I2C / GPIO peripherals

## System Architecture

### Core Allocation

**Core 0**

* Sound sensor sampling task
* LCD display task
* IR decode task
* IR handler task
* RFID authentication task

**Core 1**

* Music playback task

### Synchronization Primitives

* Mutexes for shared volume/song state
* Queue for IR commands
* Timed task scheduling with `vTaskDelay()`

## Adaptive Volume Control

The system continuously samples ambient sound, calibrates quiet/loud baselines, and maps noise levels to playback volume.

Techniques used:

* Multi-sample averaging for noise reduction
* Calibration at startup
* Exponential smoothing to prevent abrupt jumps
* Real-time PWM duty-cycle control

## Example Results

* Smooth playback while handling multiple peripherals concurrently
* Responsive UI with no blocking between sensor reads and playback
* Stable volume adaptation under changing room noise

## Resume Highlights

* Built a dual-core FreeRTOS embedded system with concurrent peripherals
* Implemented queues, mutexes, and shared-state synchronization
* Designed adaptive control logic for real-time user experience

## Future Improvements

* Bluetooth audio streaming
* Mobile companion app
* SD card music library
* OLED spectrum visualizer
* Voice assistant integration

## How to Run

1. Connect all peripherals to ESP32-S3 pins.
2. Install required Arduino libraries:

   * LiquidCrystal_I2C
   * MFRC522
   * IRremoteESP8266
3. Flash firmware to ESP32-S3.
4. Power device and complete startup calibration.
5. Use RFID card + IR remote to control playback.

## Authors

* Feier Long
* Ruby Lee
