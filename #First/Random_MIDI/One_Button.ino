// Arduino pin assignments
#define midiChannel (byte)0

// Start of code
void setup() {
   //  Setup serial. MIDI speed
   Serial.begin(31250);    

}

//********************* MAIN LOOP ***********************************

void loop() {
  int val;
  val = random(20,100);
    noteSend(0x90, val, 127);
    delay(200);
    noteSend(0x80, val, 127);
    delay(800);
    } // end loop function
    
//********************* Functions ***********************************


//  plays a MIDI note
 void noteSend(char cmd, char data1, char data2) {
  cmd = cmd | char(midiChannel);  // merge channel number
  Serial.write(cmd);
  Serial.write(data1);
  Serial.write(data2);
}
