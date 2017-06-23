# Hybrid SDVX Controller (DIY)
 
 
<div style='float: center'>
  <img style='width: 200px' src='http://sdvx-diy.pancakeapps.com/pics/pic021.png'></img>
</div>

<hr>

Check http://sdvx-diy.pancakeapps.com for full instructions.

CODE INSTRUCTIONS:

* Download and install ARDUINO IDE v1.8
https://www.arduino.cc/en/Main/OldSoftwareReleases#previous 

* Download and install Teensyduino
https://www.pjrc.com/teensy/td_download.html

* Add these lines to the C:\Program Files (x86)\Arduino\hardware\teensy\avr boards.txt file and save. 

teensy31.menu.usb.sdvx=SDVX controller

teensy31.menu.usb.sdvx.build.usbtype=USB_ARCADE

teensy31.menu.usb.sdvx.fake_serial=teensy_gateway

* Then add the 4 usb_arcade and usb_desc inside yout core/teensy3 folder and overwirte existing files.

*Alternatively download the whole set of folders and paste into Program Files.

* Open teensyduino and connect your PCB to the PC using a USB cable
* In Tools/USB Type choose SDVX Controller
* Open a blank Arduino IDE file (FIle - New) and click Verify to open the Teensyduino UI
* Hit the "Open HEX file" button and choose the file
* Click the hardware reset button on the Teensy PCB and it will upload.

Then you're done!

For the Leonardo CODE you'll need only Arduino IDE. Set the Arduino for a Leonardo and choose the right COM port.

<hr>

## Part List / Hardware

Things used to make this controller.
You can find links here: http://sdvx-diy.pancakeapps.com

* Teensy 3.2 PCB
* 2 Chinese Rotary encoders (600ppr)
* 4 60x60 SANWA buttons (white)
* 2 50x25 SANWA buttons (blue)
* 1 30x30 SANWA buton (blue)
* 2 Aluminum knobs 30x25mm
* 7 Microswitch (included with the buttons)
* 36 Crimp connectors
* 9 molex 2.54 4 pin wires with male and female connectors
* 5 molex 2.54 6 pin wires.
* 1 perfboard (60x40mm)
* 6 M3 bolts (for the encoders)
* 20 M5 bolts for the body
* 4 M6 bolts for the main plate
* 4 magnetic locks
* 1 super glue

Skills needed:
* Wood cutting
* Soldering
* Drilling
* Sanding

## Part List / Building Materials

**Main box**
Made out of 5mm MDF planks. You have to make the box 3mm narrower on each side to mount the 3mm black acrylic.

**Side plates**
Made out of black 3mm acrylic. See CAD file.

**Top plate**
Made out of laser cut clear 5mm acrylic. See CAD file.

**Other**
20xM5 bolts, 4xM6 bolts, 4xmagnetic locks

<hr>

**PIN DIAGRAM (teensy only)**
<table><thead>
<tr>
<th>Button</th>
<th style="text-align: center">Pin #</th>
<th style="text-align: center">Button #</th>
<th style="text-align: center">LED Pin #</th>
</tr>
</thead><tbody>
<tr>
<td>Start</td>
<td style="text-align: center">4</td>
<td style="text-align: center">Button 1</td>
<td style="text-align: center">-</td>
</tr>
<tr>
<td>BT-A</td>
<td style="text-align: center">5</td>
<td style="text-align: center">Button 2</td>
<td style="text-align: center">-</td>
</tr>
<tr>
<td>FX-L</td>
<td style="text-align: center">6</td>
<td style="text-align: center">Button 3</td>
<td style="text-align: center">-</td>
</tr>
<tr>
<td>BT-B</td>
<td style="text-align: center">7</td>
<td style="text-align: center">Button 4</td>
<td style="text-align: center">-</td>
</tr>
<tr>
<td>BT-C</td>
<td style="text-align: center">8</td>
<td style="text-align: center">Button 5</td>
<td style="text-align: center">-</td>
</tr>
<tr>
<td>FX-R</td>
<td style="text-align: center">9</td>
<td style="text-align: center">Button 6</td>
<td style="text-align: center">-</td>
</tr>
<tr>
<td>BT-D</td>
<td style="text-align: center">10</td>
<td style="text-align: center">Button 7</td>
<td style="text-align: center">-</td>
</tr>
</tbody></table>


<table><thead>
<tr>
<th>ENCODERS</th>
<th style="text-align: center">DATA 1</th>
<th style="text-align: center">DATA 2</th>
</tr>
</thead><tbody>
<tr>
<td>Left knob (VOL-L)
<td style="text-align: center">0</td>
<td style="text-align: center">1</td>
</tr>
<tr>
<td>Right knob (VOL-R)
<td style="text-align: center">2</td>
<td style="text-align: center">3</td>
</tr>
</tbody></table>

**Also you have to connect the encoders to the VUSB pin to get the 5v input**

<hr>

**PIN LAYOUT (LEONARDO ARDUINO)**

<table><thead>
<tr>
<th>Button</th>
<th style="text-align: center">Pin #</th>
<th style="text-align: center">Button #</th>
<th style="text-align: center">LED Pin #</th>
</tr>
</thead><tbody>
<tr>
<td>Start</td>
<td style="text-align: center">13</td>
<td style="text-align: center">Button 1</td>
<td style="text-align: center">12</td>
</tr>
<tr>
<td>BT-A</td>
<td style="text-align: center">A5</td>
<td style="text-align: center">Button 2</td>
<td style="text-align: center">6</td>
</tr>
<tr>
<td>FX-L</td>
<td style="text-align: center">A4</td>
<td style="text-align: center">Button 3</td>
<td style="text-align: center">7</td>
</tr>
<tr>
<td>BT-B</td>
<td style="text-align: center">A3</td>
<td style="text-align: center">Button 4</td>
<td style="text-align: center">8</td>
</tr>
<tr>
<td>BT-C</td>
<td style="text-align: center">A2</td>
<td style="text-align: center">Button 5</td>
<td style="text-align: center">9</td>
</tr>
<tr>
<td>FX-R</td>
<td style="text-align: center">A1</td>
<td style="text-align: center">Button 6</td>
<td style="text-align: center">10</td>
</tr>
<tr>
<td>BT-D</td>
<td style="text-align: center">A0</td>
<td style="text-align: center">Button 7</td>
<td style="text-align: center">11</td>
</tr>
</tbody></table>


<table><thead>
<tr>
<th>ENCODERS</th>
<th style="text-align: center">DATA 1</th>
<th style="text-align: center">DATA 2</th>
</tr>
</thead><tbody>
<tr>
<td>Left knob (VOL-L)
<td style="text-align: center">0</td>
<td style="text-align: center">1</td>
</tr>
<tr>
<td>Right knob (VOL-R)
<td style="text-align: center">2</td>
<td style="text-align: center">3</td>
</tr>
</tbody></table>

>**Also you have to connect the encoders to the 5V pin for the 5v input**

<hr>

## Assembly / Building the controller

**Buttons**
Assembly every button in its place on the acrylic board. Use the plastic nut to keep them in place.
After that put the white plastic center in the button inserting it rotates 15° pushing and then locking it rotating it 15° back.
Don't forget to add your printed vynil bellow the clear acrylic before inserting the buttons.

**Encoders**
Mount the encoders using 3 small screws.

**Crimp Connectors**
Use crimp connectors in each wire of the 7 molex wires your gonna use. You should en up with 7 wires, each with 4 crimp connectors (1 LED, 1 DATA and 2 GROUND), and also 2 other wires for the encoders (1 DATA A, 1 DATA B, 1 5v input and 1 GROUND). 

**Perfboard**
Following this drawing (drawing pending) solder each male molex connector in the perfboard. Then using PCB wires solder each molex pin with another molex pin (For the DATA and LED pins) and solder all the grounds in a single line.

**Teensy**
Solder each corresponding molex wire to each hole in the PCB. You should end up with 3 6-pin wires.

Mount everything toghether connecting each molex wire to the perfboard and to the buttons.

>If a button doesn't work, try checking the solder to see if its connected properly. Also check the ground connections.

<hr>

## Gallery

[Step by step gallery](http://imgur.com/a/uVgB2)
