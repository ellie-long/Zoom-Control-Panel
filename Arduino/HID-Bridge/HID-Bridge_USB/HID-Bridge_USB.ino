/*hyx
 Copyright (c) 2014-2015 NicoHood
 See the readme for credit to other people.

 Serial HID-Bridge USB
 Select HoodLoader16u2 as board.

 After upload make sure the 16u2 sketch runs, not the HoodLoader2 bootloader.
 This example will type any serial data via keyboard.
*/

#include "Keyboard.h"
#include "HID.h"
char ctrlKey = KEY_LEFT_CTRL;
char altKey = KEY_LEFT_ALT;
char shiftKey = KEY_LEFT_SHIFT;
char returnKey = KEY_RETURN;
char f1Key = KEY_F1;
char f2Key = KEY_F2;
int gState = 0;
int delayTime = 150;


void setup() {
  // Start the Serial1 which is connected with the IO MCU.
  // Make sure both baud rates are the same
  // you can go up to 2000000 for very fast data transmission.
  Serial1.begin(115200);

  // Sends a clean report to the host. This is important on any Arduino type.
  Keyboard.begin();

  // Start the USB Serial for debugging
  Serial.begin(115200);
}

void loop() {
  // Check if any Serial data from the IO MCU was received
  char c = Serial1.read();
  if (c>0){
    Serial.print(c);
  }
//  Serial.print(c);

//  // If it's a character, print it!
//  if (c >= 'a' && c <= 'z') {
////    Serial.print(F("USB: "));
//    Serial.print(c);
//    Serial.print('\n');
////    Keyboard.print(c);
//  }

  if (c== 'a' or c=='m' or c=='v' or c=='s' or c=='t' or c=='c' or c=='p' or c=='n' or c=='q' or c=='h' or c=='u'){
    Keyboard.press(ctrlKey);
    Keyboard.press(altKey);
    Keyboard.press(shiftKey);
    delay(delayTime);
    Keyboard.releaseAll();
    Serial.print("USB: ALT+");
    Serial.print(c);
    Serial.print('\n');
    Keyboard.press(altKey);
    Keyboard.press(c);
    delay(delayTime);
    Keyboard.releaseAll();
    if (c=='q'){
      Keyboard.press(returnKey);
      delay(delayTime);
      Keyboard.releaseAll();
    }
  }

  if (c== 'g'){
    if (gState==0){
      Keyboard.press(ctrlKey);
      Keyboard.press(altKey);
      Keyboard.press(shiftKey);
      delay(delayTime);
      Keyboard.releaseAll();
      Serial.print("USB: ALT+F1");
      Serial.print('\n');
      Keyboard.press(altKey);
      Keyboard.press(f1Key);
      delay(delayTime);
      Keyboard.releaseAll();
      gState =1;
    }
    else if (gState==1){
      Keyboard.press(ctrlKey);
      Keyboard.press(altKey);
      Keyboard.press(shiftKey);
      delay(delayTime);
      Keyboard.releaseAll();
      Serial.print("USB: ALT+F2");
      Serial.print('\n');
      Keyboard.press(altKey);
      Keyboard.press(f2Key);
      delay(delayTime);
      Keyboard.releaseAll();
      gState =0;
    }
  }

}
