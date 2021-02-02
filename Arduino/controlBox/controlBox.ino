

const int offBtn = 28;
const int chatBtn = 30;
const int partBtn = 32;
const int galleryBtn = 34;
const int resetBtn = 36;
const int recordBtn = 38;
const int recPauseBtn = 40;
const int screenBtn = 42;
const int scPauseBtn = 44;
const int videoBtn = 46;
const int cameraBtn = 48;
const int muteMeBtn = 50;
const int muteAllBtn = 52;

const int chatLED = 31;
const int partLED = 33;
const int galleryLED = 35;
const int resetLED = 37;
const int recordLED = 39;
const int recPauseLED = 41;
const int screenLED = 43;
const int scPauseLED = 45;
const int videoLED = 47;
const int cameraLED = 49;
const int muteMeLED = 51;
const int muteAllLED = 53;

int muteMeState = 0;
int muteAllState = 0;
int videoState = 0;
int camState = 0;
int screenState = 0;
int scPauseState = 0;
int recordState = 0;
int recPauseState = 0;
int galleryState = 0;
int resetState = 0;
int chatState = 0;
int partState = 0;
int offState = 0;
int boxReset = 0;

int lastMuteMe = 0;
int lastMuteAll = 0;
int lastVideo = 0;
int lastScreen = 0;
int lastScPause = 0;
int lastRecord = 0;
int lastRecPause = 0;

String offStr = "";
String muteMeStr = "";
String muteAllStr = "";
String videoStr = "";
String camStr = "";
String screenStr = "";
String scPauseStr = "";
String recStr = "";
String recPauseStr = "";
String galleryStr = "";
String chatStr = "";
String resetStr = "";
String partStr = "";
String newData = "-------------------------------------\n";
String allData = "";

int stateChange = 1;
int firstRun = 1;

int delayTime = 500;
void setup()
{
  // Buttons
  pinMode(offBtn, INPUT);
  pinMode(chatBtn, INPUT);
  pinMode(partBtn, INPUT);
  pinMode(galleryBtn, INPUT);
  pinMode(resetBtn, INPUT);
  pinMode(recordBtn, INPUT);
  pinMode(recPauseBtn, INPUT);
  pinMode(screenBtn, INPUT);
  pinMode(scPauseBtn, INPUT);
  pinMode(videoBtn, INPUT);
  pinMode(cameraBtn, INPUT);
  pinMode(muteMeBtn, INPUT);
  pinMode(muteAllBtn, INPUT);
  // LEDs
  pinMode(chatLED, OUTPUT);
  pinMode(partLED, OUTPUT);
  pinMode(galleryLED, OUTPUT);
  pinMode(resetLED, OUTPUT);
  pinMode(recordLED, OUTPUT);
  pinMode(recPauseLED, OUTPUT);
  pinMode(screenLED, OUTPUT);
  pinMode(scPauseLED, OUTPUT);
  pinMode(videoLED, OUTPUT);
  pinMode(cameraLED, OUTPUT);
  pinMode(muteMeLED, OUTPUT);
  pinMode(muteAllLED, OUTPUT);
  Serial.begin(115200);

}

void loop()
{
  if (firstRun == 1){
    digitalWrite(chatLED, HIGH);
    digitalWrite(partLED, HIGH);
    digitalWrite(galleryLED, HIGH);
    digitalWrite(resetLED, HIGH);
    digitalWrite(cameraLED, HIGH);
    firstRun = 0;
    boxReset = 1;
  }
  
  // Momentary Buttons
  offState = digitalRead(offBtn);
  camState = digitalRead(cameraBtn);
  galleryState = digitalRead(galleryBtn);
  resetState = digitalRead(resetBtn);
  chatState = digitalRead(chatBtn);
  partState = digitalRead(partBtn);

  if (offState == HIGH){
    stateChange = 1;
    Serial.write('q');
    delay(delayTime);
  }
  if (camState == HIGH){
    stateChange = 1;
    Serial.write('n');
    delay(delayTime);
  }
  if (galleryState == HIGH){
    stateChange = 1;
    Serial.write('g');
    delay(delayTime);
  }
//  if (resetState == HIGH){
//    Serial.write('r');
//    delay(delayTime);
//  }
  if (chatState == HIGH){
    stateChange = 1;
    Serial.write('h');
    delay(delayTime);
  }
  if (partState == HIGH){
    stateChange = 1;
    Serial.write('u');
    delay(delayTime);
  }
  if (resetState == HIGH){
    stateChange = 1;
    if (boxReset == 0){
      digitalWrite(chatLED, HIGH);
      digitalWrite(partLED, HIGH);
      digitalWrite(galleryLED, HIGH);
      digitalWrite(resetLED, HIGH);
      digitalWrite(cameraLED, HIGH);
      boxReset = 1;
    }
    else if (boxReset == 1){
      digitalWrite(chatLED, LOW);
      digitalWrite(partLED, LOW);
      digitalWrite(galleryLED, LOW);
      digitalWrite(resetLED, LOW);
      digitalWrite(cameraLED, LOW);
      boxReset = 0;    
    }
//    Serial.write('q');
    delay(delayTime);
  }

  // Latching Buttons
  muteMeState = digitalRead(muteMeBtn);
  if (muteMeBtn == HIGH){
    muteMeState = 1;
  }
  else{
    muteMeState = 0;
  }
  if (muteMeState != lastMuteMe){
    stateChange = 1;
    if (muteMeState == 1)
    {
      digitalWrite(muteMeLED, HIGH);
      lastMuteMe = 1;
      Serial.write('a');
    } 
    else if (muteMeState == 0){
      digitalWrite(muteMeLED, LOW);
      lastMuteMe = 0;
      Serial.write('a');
    }
  }

  muteAllState = digitalRead(muteAllBtn);
  if (muteAllState != lastMuteAll){
    stateChange = 1;
    if (muteAllState == HIGH)
    {
      digitalWrite(muteAllLED, HIGH);
      lastMuteAll = 1;
//      Serial.write('m');
      Serial.write('a');
    } 
    else{
      digitalWrite(muteAllLED, LOW);
      lastMuteAll = 0;
//      Serial.write('m');
      Serial.write('a');
    }  
  }
  
  
  videoState = digitalRead(videoBtn);
  if (videoState != lastVideo){
    stateChange = 1;
    if (videoState == HIGH)
    {
      digitalWrite(videoLED, HIGH);
      lastVideo = 1;
      Serial.write('v');
    } 
    else{
      digitalWrite(videoLED, LOW);
      lastVideo = 0;
      Serial.write('v');
    }
  }


  screenState = digitalRead(screenBtn);
  if (screenState != lastScreen){
    stateChange = 1;
    if (screenState == HIGH)
    {
      digitalWrite(screenLED, HIGH);
      lastScreen = HIGH;
      Serial.write('s');
    } 
    else{
      digitalWrite(screenLED, LOW);
      lastScreen = 0;
      Serial.write('s');
    }
  }

  
  scPauseState = digitalRead(scPauseBtn);
  if (scPauseState != lastScPause){
    stateChange = 1;
    if (scPauseState == HIGH)
    {
      digitalWrite(scPauseLED, HIGH);
      lastScPause = 1;
      Serial.write('t');
    } 
    else if (scPauseState == LOW){
      digitalWrite(scPauseLED, LOW);
      lastScPause = 0;
      Serial.write('t');
    }
  }
  
  recordState = digitalRead(recordBtn);
  if (recordState != lastRecord){
    stateChange = 1;
    if (recordState == HIGH)
    {
      digitalWrite(recordLED, HIGH);
      lastRecord = 1;
      Serial.write('c');
    } 
    else{
      digitalWrite(recordLED, LOW);
      lastRecord = 0;
      Serial.write('c');
    }    
  }

  recPauseState = digitalRead(recPauseBtn);
  if (recPauseState != lastRecPause){
    stateChange = 1;
    if (recPauseState == HIGH)
    {
      digitalWrite(recPauseLED, HIGH);
      lastRecPause = 1;
      Serial.write('p');
    } 
    else{
      digitalWrite(recPauseLED, LOW);
      lastRecPause = 0;
      Serial.write('p');
    }   
  }

  if (stateChange == 1){
    offStr = "OFF = " + String(offState) + "\n";
    muteMeStr = "MUTEME = " + String(muteMeState) + "\n";
    muteAllStr = "MUTEALL = " + String(muteAllState) + "\n";
    videoStr = "VIDEO = " + String(videoState) + "\n";
    camStr = "CAMERA = " + String(camState) + "\n";
    screenStr = "SCREEN = " + String(screenState) + "\n";
    scPauseStr = "SCPAUSE = " + String(scPauseState) + "\n";
    recStr = "RECORD = " + String(recordState) + "\n";
    recPauseStr = "RECPAUSE = " + String(recPauseState) + "\n";
    galleryStr = "GALLERY = " + String(galleryState) + "\n";
    chatStr = "CHAT = " + String(chatState) + "\n";
    resetStr = "RESET = " + String(resetState) + "\n";
    partStr = "PART = " + String(partState) + "\n";
    allData = offStr + muteMeStr + muteAllStr + videoStr + camStr + screenStr + scPauseStr + recStr + recPauseStr + galleryStr + chatStr + resetStr + partStr + newData;    
//    Serial.print(allData);
    stateChange = 0; 
    delay(delayTime);
  }

  
  
  
  
  
}
