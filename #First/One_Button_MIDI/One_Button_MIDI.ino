#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

//Choose an Arduino Pin (except the first one which we'll use for MIDI OUT circuit)
const int pinButton = 4;

int buttonstate = 0;
int lastbuttonstate = 0;

void setup() {
  
  //You Can choose which channel send the signal at
  //MIDI.begin(MIDI_CHANNEL_OMNI); 

  //MIDI Baud Rate 31250
  Serial.begin(31250);
  delay(100);
  

  pinMode(pinButton, INPUT_PULLUP);
}

void loop() {
  buttonstate = digitalRead(pinButton);
  
  if(buttonstate != lastbuttonstate) {
    if (buttonstate == LOW){ 
      //NoteOn Command (Note, Velocity, Channel)
      MIDI.sendNoteOn(36, 127, 1);
    }
     
    else {
     //NoteOff Command (Note, Velocity, Channel)
     MIDI.sendNoteOff(36, 0, 1);
     
  }
  }

  lastbuttonstate = buttonstate; 
}
