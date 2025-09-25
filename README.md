# hello_cat
Hello-cat project
The "Hello Cat" project is based on Arduino, specifically using the Atmega328P microcontroller. The project represents automatic feeding machine for cats/dogs. The circuit includes the following components:

- HC-05 Bluetooth module
- 220 ohm resistor
- 22k ohm resistor
- 10k ohm resistor
- MG995 servo
- Limit switch
- Green LED
- ON/OFF switch

A schematic of the circuit can be found in the folder containing this file. In the diagram, the Arduino’s 5V pin is connected in series to the limit switch. When the switch is pressed, current flows to the LED resistor and then to the HC-05 Bluetooth module. The GND connection from the HC-05 module is routed through a black wire that passes through a 22k ohm resistor and finally to the Arduino’s ground.

A voltage divider made from the 22k ohm and 10k ohm resistors reduces the voltage to 1.56V, which is then supplied to the HC-05 module. The Arduino’s pin 10 is connected to the TXD pin of the Bluetooth module, while pin 11 is connected to the voltage divider, which then leads to the RXD pin of the HC-05.

The servo is connected to pin 8 on the Arduino, and the limit switch is connected to pin 2. The servo’s power and ground are supplied by a separate 5V, 1000A power supply.

This project demonstrates the use of an Arduino to control a servo and communicate wirelessly via Bluetooth, with additional safety and signaling components included in the circuit.

<div style="align-items: center;">
<p>I created app in Android Studio to manage feeding schedule of Cat. Something like this:</p>

<img width="383" height="687" alt="image" src="https://github.com/user-attachments/assets/5a59b48f-08d8-4230-892e-76080338b5c7" />
</div>
