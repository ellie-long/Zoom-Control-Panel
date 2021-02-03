# Zoom Control Panel
 A push-button control panel for Zoom
 
 This repo contains files for building a push-button control panel for Zoom. It was made using Windows short cuts, but could easily be modified for Mac instead. 
 
 There are four major components to this build:
 * A 3D-printed case
 * Optional: Printing and installing button icons
 * Wiring buttons and Arduino Mega 2560
 * Programming Arduino
 
# Parts List
 In order to build this project, you will need:
 * Access to a 3D printer
 * An Arduino Mega 2560 board
   * An optional spare Arduino for uploading HoodLoader2 (https://github.com/NicoHood/HoodLoader2), which is required to use the Mega2560 as a keyboard input 
 * A 2560 Prototype Circuit Breakout Board PCB
 * Enough 2.54mm male header pins to mount the breakout board PCB to the Arduino
   * I used the full groupings of 1x10, 5 1x8, 2 1x18 in mine for stability, though you could get away with just the two 1x18 or a single 2x18
 * 12 rectangular LA128A push buttons rated at 12V
   * (If you find 5V ones, even better, though the 12V ones work just fine.) 
   * This design was made with the 16mm rectangular ones in mind, though others should work as well -- however, the button icons may need to be scaled to fit other sizes
   * As designed, I used the following, though you can update it to your own preference:
     * 4 Orange Latching Switches
     * 2 Orange Momentary Switches
     * 2 Red Latching Switches
     * 3 Green Momentary Switches
     * 1 Green Latching Switch
 * A red mushroom LAY37-11ZS push button
 * 13 10k Ohm Resistors
 * Various hook-up wires, preferably in multiple colors to keep track of wires
 * Optional: Glossy transparent printable sticker 'paper' for icons
 * 8 M3 nuts
 * 8 small M3 screws
 * Optional long USB-A or USB extension cable to connect panel to the computer
 * Small flathead screwdriver
     
 
# 3D Printed Case
 There are two files that need to be 3D printed to create the case. They are found in 3D Print/To Print, which contains these \*.stl files for the button panel and the main body.
 These files have been designed to not require supports when printing, though you may want to use a brim. I printed it on a Prusa Mk3S+ using PETG with 0.20mm layer heights.
 
 Once printed, M3 nuts can be pushed into place for each of the 8 screw-holes. If they fall out, you can use a small amount of superglue around the edge to hold them into place.

# Printing and Installing Button Icons
 * In the Icons folder you can find a \*.svg and \*.pdf of icons that can be printed onto transparent sticker 'paper', carefully cut out, and adhered to the push buttons.
 * Using a small flathead screwdriver, you can carefully remove the colored transparent window from the push buttons. 
 * Behind it sits a white rectangle, followed by a white piece of plastic that connects the button mechanism to the front part that is pressed. 
 * Carefully place the sticker onto the white rectangle, then reassemble the button
   * Make sure to check that the button pushes and released properly. If not, the button may have been inserted backwards. 
     * Try to keep track of which buttons each parts came from, as mixing them can lead to buttons sticking.

# Wiring and Assembly
* Before spending a lot of time wiring, first make sure to install HoodLoader2 on your Arduino so that you can use it as a keyboard. Follow the Hardware and Software Installations in their wiki before going further: https://github.com/NicoHood/HoodLoader2/wiki/Hardware-Installation
* Install each of the buttons onto the 3D printed Button Panel
  * I found it easiest to have the flat side of the buttons flush against the panel and to install the rubber o-rings on the back side before putting in the square washers and screwing them in place
* Solder the headers onto the PCB board
* For wiring the buttons, follow the wiring diagram in the folder Wiring and solder the buttons . It's provided in \*.pdf, \*.svg, and \*.png formats
  * The resistors can be soldered directly on each button between the negative side of the LED and the 'C' (common) pin of the switch
  * For the 5V-side, make sure that you use the 'NO' (Normally Open) pin of the switch
  * Don't forget to include the 10k Ohm resistor on the mushroom button, and make sure that it's wired to the 'green' side so that the switch is closed when the button is pressed. You can check that it's on the correct side using a multimeter.
* Once the wiring is complete, attach the PCB to the Arduino and place it inside of the panel. 
* Carefully place the bottom 4 M3 screws into position and screw them in. (if you can only get the front 2 in, that will also work fine)
* Gently push the button panel into place and attach it with the 4 remaining M3 screws. 

# Programming Arduino
* Before programming the Arduino, make sure that you have installed both the Arduino IDE (https://www.arduino.cc/en/software/) and HoodLoader2 on your Arduino so that you can use it as a keyboard. Follow the Hardware and Software Installations in their wiki before going further: https://github.com/NicoHood/HoodLoader2/wiki/Hardware-Installation
  * Hopefully HoodLoader was installed before you finished wiring, or else you'll need to pull the Arduino to install it following the instructions linked above
* The files needed to upload to the Arduino are located in the Arduino folder. There are three:
  * blankIno.ino is a blank Arduino file to upload when switching between the 16u and Mega 2560 chipset. After uploading to the 16u chip, I find uploading this twice to the Mega 2560 the easiest way to regain access to the Mega 2560 chip
  * controlBox.ino is the primary code that should be uploaded to the Mega 2560 chip -- NOT the 16u chip
    * It defines the pins of each button and sends serial commands to the 16u chip using the Serial1 commands
    * Make sure to upload this software each time before uploading HID-Bridge on the 16u.
    * If debugging, you can uncomment the Serial.print(allData) line and run the serial monitor to make sure your buttons are working correctly. This should only be done before uploading the HID-Bridge to the 16u, and make sure to comment that line and re-upload this code before uploading HID-Bridge or else some strange effects may occur by flooding the serial port with text
  * HID-Bridge_USB.ino allows the Arduino Mega 2560 to be used as a keyboard input device. This software can only be loaded if HoodLoader2 is installed, and should be uploaded to the 16u chip -- NOT the Mega 2560 chip
* Once the software is uploaded, you should be able to use your new Zoom Control Panel! If you run into issues, you can use the on-screen keyboard to make sure that the modifier keys are being input correctly, or open a Zoom channel to test out your new control box.
