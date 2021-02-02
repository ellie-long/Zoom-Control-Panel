# Zoom Control Panel
 A push-button control panel for Zoom
 
 This repo contains files for building a push-button control panel for Zoom. It was made using Windows short cuts, but could easily be modified for Mac instead. 
 
 There are four major components to this build:
 * A 3D-printed case
 * Wiring buttons and Arduino Mega 2560
 * Printing button icons
 * Programming Arduino to use as an HID
 
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
 * Glossy transparent printable sticker 'paper'
 * Optional long USB-A or USB extension cable to connect panel to the computer
     
 
# 3D Printed Case
 There are two files that need to be 3D printed to create the case. They are found in 3D Print/To Print, which contains these \*.stl files for the button panel and the main body.
 These files have been designed to not require supports when printing, though you may want to use a brim. I printed it on a Prusa Mk3S+ using PETG with 0.20mm layer heights.

