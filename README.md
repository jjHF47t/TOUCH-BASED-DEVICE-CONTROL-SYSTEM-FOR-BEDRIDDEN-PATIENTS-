# TOUCH-BASED-DEVICE-CONTROL-SYSTEM-FOR-BEDRIDDEN-PATIENTS

## Overview

This project implements a Password-Protected Touch-Based Device Control System for Bedridden Patients using the LPC2148 ARM7 Microcontroller. The system enables physically challenged or bedridden individuals to control household devices through a resistive touch screen interface after successful password authentication. Passwords are securely stored in EEPROM and can be modified when required. The system also includes an emergency alert feature using a buzzer, providing additional safety and convenience.

## Block Diagram
<p align="center">
<img width="927" height="566" alt="Block diagram" src="https://github.com/user-attachments/assets/e59a4e84-d018-4116-8abb-14d714489fe3" />

## Project Images and Videos

https://drive.google.com/drive/folders/1LTOgoQdOcuxj-susWcuXqCTDDselpIQq

## Features

* Password-protected system access
* EEPROM-based password storage
* Password validation using keypad input
* Password update and EEPROM write functionality
* Touch-screen based device control
* Device1 (LED1) ON/OFF control
* Device2 (LED2) ON/OFF control
* Emergency buzzer activation
* LCD status monitoring
* UART interrupt-based touch data reception
* SPI communication with EEPROM
* Secure and user-friendly operation

## Hardware Requirements

* LPC2148 ARM7 Microcontroller
* Resistive Touch Screen Module
* 16x2 LCD Display
* 4x4 Matrix Keypad
* AT25LC512 SPI EEPROM
* LED1 (Light Control)
* LED2 (Fan Control)
* Buzzer
* Power Supply

## Software Requirements

* Embedded C
* Keil µVision IDE
* Flash Magic
* Proteus (Optional)

## Working Principle

1. System initializes LCD, UART, SPI, Keypad, EEPROM, and Interrupt modules.
2. Stored password is read from EEPROM.
3. User enters a password through the keypad.
4. Password is validated against EEPROM data.
5. If authentication is successful:

   * Touch screen control is enabled.
   * Device1 (LED1) can be switched ON/OFF.
   * Device2 (LED2) can be switched ON/OFF.
   * Emergency buzzer can be activated.
   * Touch control can be disabled when not required.
6. Password can be modified securely.
7. Updated password is saved permanently in EEPROM.
8. LCD continuously displays device status and user feedback.


## Modules Used

### LCD Interface

Displays authentication messages, device status, and user instructions.

### Keypad Interface

Used for password entry and password modification.

### UART Communication

Receives touch-screen coordinate data through interrupt-driven communication.

### SPI EEPROM Interface

Stores and retrieves user passwords securely.

### Touch Screen Interface

Processes touch coordinates and maps them to control actions.

### Interrupt Handling

Handles touch-screen communication and password update operations efficiently.

### Device Control Module

Controls LEDs and buzzer based on touch-screen input.

## Applications

* Smart Hospital Rooms
* Bedridden Patient Assistance Systems
* Elderly Care Systems
* Assistive Healthcare Devices
* Smart Home Automation
* Rehabilitation Support Systems

## Future Enhancements

* IoT Integration: Enable remote monitoring and control of devices through a mobile app or web dashboard.
* Wi-Fi/Bluetooth Connectivity: Allow wireless communication with caregivers and healthcare staff.
* Cloud-Based Data Storage: Store patient activity and alert logs securely in the cloud.
* Patient Health Monitoring: Integrate sensors for heart rate, body temperature, SpO₂, and blood pressure monitoring.
* Multiple Device Control: Expand the system to control additional appliances such as fans, lights, TVs, and medical equipment.
  
## Technologies Used

* Embedded C
* LPC2148 ARM7
* UART Communication
* SPI Protocol
* EEPROM Interfacing
* LCD Interfacing
* Keypad Interfacing
* Touch Screen Interfacing
* Interrupt Programming

## Project Outcomes

* Developed a secure touch-based control system using LPC2148.
* Implemented password authentication with EEPROM storage.
* Integrated LCD, Keypad, EEPROM, Touch Screen, UART, and SPI modules.
* Designed interrupt-driven communication for efficient operation.
* Enabled independent device control for patients with limited mobility.
* Improved understanding of embedded system design and peripheral interfacing.
* Created a modular and scalable embedded application.

## Conclusion

The Touch-Based Device Control System for Bedridden Patients successfully provides a secure and accessible method for controlling devices using a touch interface. By integrating password authentication, EEPROM storage, UART communication, SPI interfacing, and interrupt-driven control, the system enhances patient independence and safety. The project serves as a strong foundation for future healthcare automation and smart assistive technologies.

