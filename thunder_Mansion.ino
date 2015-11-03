// Simple WAV file player example
//
// Requires the audio shield:
//   http://www.pjrc.com/store/teensy3_audio.html
//
// Data files to put on your SD card can be downloaded here:
//   http://www.pjrc.com/teensy/td_libs_AudioDataFiles.html
//
// This example code is in the public domain.


#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
//#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlaySdWav           playSdWav2;     //xy=188,589
AudioPlaySdWav           playSdWav1;     //xy=209,516
AudioMixer4              mixer1;         //xy=417,526
AudioOutputI2S           i2s1;           //xy=579,501
AudioConnection          patchCord1(playSdWav2, 0, mixer1, 2);
AudioConnection          patchCord2(playSdWav2, 1, mixer1, 3);
AudioConnection          patchCord3(playSdWav1, 0, mixer1, 0);
AudioConnection          patchCord4(playSdWav1, 1, mixer1, 1);
AudioConnection          patchCord5(mixer1, 0, i2s1, 0);
AudioConnection          patchCord6(mixer1, 0, i2s1, 1);

// GUItool: end automatically generated code
AudioControlSGTL5000     sgtl5000_1;     //xy=240,153


const int firstFloor = 1;   //first floor lights (pin to mosfet)
const int secondFloor = 3;  //second floor lights
const int thirdFloor = 2;  //third floor lights
const int fourthFloor = 4;  //fourth floor lights

const int shake = 0;         // this is the house shaker (the saber saw)



int n = 4;
int lightDelay = 250;

void setup() {
  
Serial.begin(9600);
pinMode(secondFloor, OUTPUT);
pinMode(thirdFloor, OUTPUT);
pinMode(firstFloor, OUTPUT);
pinMode(fourthFloor, OUTPUT);
pinMode(shake, OUTPUT);

  
pinMode(21, INPUT);    //this is for the button if used
digitalWrite(21, HIGH);     


  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(5);

  sgtl5000_1.enable();
  sgtl5000_1.volume(.6);   //   THIS IS THE VOLUME CONTROL!!!!! 1 is crazy loud

  SPI.setMOSI(7);
  SPI.setSCK(14);
  if (!(SD.begin(10))) {
    // stop here, but print a message repetitively
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
}


///  This function is called from MAIN and plays the main audio file (raining and thunder) stored on a the SD card

void playFile(const char *filename)
{
  Serial.print("Playing file: ");
  Serial.println(filename);

  playSdWav1.play(filename);

  // A brief delay for the library read WAV info
  delay(5);

  while (playSdWav1.isPlaying()) {   /// While playing the MAIN sound track, screams are layered ontop of the sound track every 6-25 seconds

       delay(random(6000,25000));  

        n = random(0,19);  // this selects one of 19 screams to play
       
       Serial.println(n);
       blinkLightsLong();
        switch(n) {


        case 0:
        playSdWav2.play("s1.wav");   // SCREAM 1 WAV file stored on the SD card
        digitalWrite(shake, HIGH);   
        blinkLightsLong();
        delay(500);                  
        digitalWrite(shake, LOW);    

          while (playSdWav2.isPlaying()) {
           blinkLights();           
          }
        
        break;
        
        case 1:

        playSdWav2.play("s2.wav");   // SCREAM 2 WAV file stored on the SD card
        digitalWrite(shake, HIGH);    
        blinkLightsLong();
        delay(500);                    
        digitalWrite(shake, LOW);     
                    blinkLights();
          while (playSdWav2.isPlaying()) {
           blinkLights();
          }
        
        break;
        
        case 2:

        playSdWav2.play("s3.wav");             // SCREAM 3 WAV file stored on the SD card
        digitalWrite(shake, HIGH);    
        blinkLightsLong();
        delay(500);                   
        digitalWrite(shake, LOW);     
          
          while (playSdWav2.isPlaying()) {
           blinkLights();
          }
        
        break;
        
        case 3:

        playSdWav2.play("s4.wav");
        digitalWrite(shake, HIGH);   // set the LED on
        blinkLightsLong();
        delay(500);                  // wait for a second
        digitalWrite(shake, LOW);    // set the LED off
          
          while (playSdWav2.isPlaying()) {
           blinkLights();
          }
        
        break;
        
        case 4:

        playSdWav2.play("s5.wav");
        digitalWrite(shake, HIGH);   // set the LED on
        blinkLightsLong();
        delay(500);                  // wait for a second
        digitalWrite(shake, LOW);    // set the LED off
          
          while (playSdWav2.isPlaying()) {
           blinkLights();
          }
        
        break;
        
        case 5:

        playSdWav2.play("s6.wav");
        digitalWrite(shake, HIGH);   // set the LED on
        blinkLightsLong();
        delay(500);                  // wait for a second
        digitalWrite(shake, LOW);    // set the LED off
          
          while (playSdWav2.isPlaying()) {
           blinkLights();
          }
        
        break;
        
        case 6:

        playSdWav2.play("s7.wav");
        digitalWrite(shake, HIGH);   // set the LED on
        blinkLightsLong();
        delay(500);                  // wait for a second
        digitalWrite(shake, LOW);    // set the LED off
          
          while (playSdWav2.isPlaying()) {
           blinkLights();
          }
        
        break;
        
        case 7:

        playSdWav2.play("s8.wav");
        delay(lightDelay);
          
          while (playSdWav2.isPlaying()) {
           blinkLights();
          }
        
        break;
        
        case 8:

        playSdWav2.play("s9.wav");
        delay(lightDelay);
          
          while (playSdWav2.isPlaying()) {
           blinkLights();
          }
        
        break;
        
        case 9:

        playSdWav2.play("s10.wav");
        delay(lightDelay);
          
          while (playSdWav2.isPlaying()) {
           blinkLights();
          }
        
        break;
        
        case 10:

        playSdWav2.play("s11.wav");
        delay(lightDelay);
          
          while (playSdWav2.isPlaying()) {
           blinkLights();
          }
        
        break;
        
        case 11:

        playSdWav2.play("s12.wav");
        delay(lightDelay);
          
          while (playSdWav2.isPlaying()) {
           blinkLights(); 
          }
        
        break;

        case 12:
        playSdWav2.play("t1.wav");
        digitalWrite(shake, HIGH);   // set the LED on
        blinkLights();
        delay(500);                  // wait for a second
        digitalWrite(shake, LOW);    // set the LED off
        while (playSdWav2.isPlaying()) {
        blinkLights();
          }
        
        break;


        case 13:
        playSdWav2.play("t1.wav");
        digitalWrite(shake, HIGH);   // set the LED on
        blinkLights();
        delay(500);                  // wait for a second
        digitalWrite(shake, LOW);    // set the LED off
        while (playSdWav2.isPlaying()) {
        blinkLights();
          }
        
        break;
        
        case 14:
        playSdWav2.play("t1.wav");
        digitalWrite(shake, HIGH);   // set the LED on
        blinkLights();
        delay(500);                  // wait for a second
        digitalWrite(shake, LOW);    // set the LED off
        while (playSdWav2.isPlaying()) {
        blinkLights();
          }
        
        break;

        case 15:
        playSdWav2.play("t1.wav");
        digitalWrite(shake, HIGH);   // set the LED on
        blinkLights();
        delay(500);                  // wait for a second
        digitalWrite(shake, LOW);    // set the LED off
        while (playSdWav2.isPlaying()) {
        blinkLights();
          }
        
        break;

        case 16:
        playSdWav2.play("t1.wav");
        digitalWrite(shake, HIGH);   // set the LED on
        blinkLights();
        delay(500);                  // wait for a second
        digitalWrite(shake, LOW);    // set the LED off
        while (playSdWav2.isPlaying()) {
        blinkLights();
          }
        
        break;

        case 17:
        playSdWav2.play("t1.wav");
        digitalWrite(shake, HIGH);   // set the LED on
        blinkLights();
        delay(500);                  // wait for a second
        digitalWrite(shake, LOW);    // set the LED off
        while (playSdWav2.isPlaying()) {
        blinkLights();
          }
        
        break;

        case 18:
        playSdWav2.play("t1.wav");
        digitalWrite(shake, HIGH);   // set the LED on
        blinkLights();
        delay(500);                  // wait for a second
        digitalWrite(shake, LOW);    // set the LED off
        while (playSdWav2.isPlaying()) {
        blinkLights();
          }
        
        break;
        
  }
  }
}


/////////////////////////////////////////     BEGIN MAIN LOOP

void loop() {
  playSdWav2.play("s2.wav"); ///  This is a scream WAV file on the SD CARD
  delay(500);
  /////  next we blink a bunch of lights for a few seconds
  digitalWrite(fourthFloor, HIGH);    
  delay(random(20,300));                   
  digitalWrite(fourthFloor, LOW);     
  delay(random(20,300)); 
  digitalWrite(fourthFloor, HIGH);    
  delay(random(20,300));                  
  digitalWrite(fourthFloor, LOW);     
  delay(random(20,300)); 
  digitalWrite(fourthFloor, HIGH);    
  delay(random(20,300));                   
  digitalWrite(fourthFloor, LOW);     
  delay(random(20,300)); 
  digitalWrite(fourthFloor, HIGH);    
  delay(random(20,300));                   
  digitalWrite(fourthFloor, LOW);     
  delay(random(20,300)); 
  digitalWrite(fourthFloor, HIGH);   
  delay(random(20,300));                   
  digitalWrite(fourthFloor, LOW);     
  delay(random(20,300)); 
  digitalWrite(fourthFloor, HIGH);  
  delay(random(20,300));                   
  digitalWrite(fourthFloor, LOW);     
  delay(random(20,300));     
  //// next we shake the house for 1/2 second
  digitalWrite(shake, HIGH);   
  delay(500);                  
  digitalWrite(shake, LOW);    

  playFile("r1.WAV");  // this is the main sound track stored on the SD card... its about 2 minutes long


/*   This code uses the button to trigger the house ON for ~2 minutes at a time
  if (digitalRead(21) == HIGH) {
    //Serial.println("Button is not pressed...");

  } else {

    Serial.println("Button pressed!!!");
          playFile("r1.WAV");
  }
*/
}

//////////////////////////////////////////// END Of MAIN LOOP




void blinkLightsLong() {     //This blinks the lights lights randomly on ONE of the FOUR floors
  int light = random(0,4);


  switch(light){
    case 0:
  digitalWrite(firstFloor, HIGH);   // set the LED on
  delay(random(500,3000));                  // wait for a second
  digitalWrite(firstFloor, LOW);    // set the LED off
  delay(random(20,300)); 

  break;
  case 1:

    digitalWrite(secondFloor, HIGH);   // set the LED on
  delay(random(1000,3000));                 // wait for a second
  digitalWrite(secondFloor, LOW);    // set the LED off
  delay(random(20,300)); 

  break;

  case 2:

    digitalWrite(thirdFloor, HIGH);   // set the LED on
  delay(random(1000,3000));                  // wait for a second
  digitalWrite(thirdFloor, LOW);    // set the LED off


  break;
  case 3:

    digitalWrite(fourthFloor, HIGH);   // set the LED on
  delay(random(1000,3000));                 // wait for a second
  digitalWrite(fourthFloor, LOW);    // set the LED off
  delay(random(20,300)); 

  break;
  }
}



void blinkLights() {      //This function blinks the lights lights randomly on ONE of the FOUR floors between 20ms and 300ms
  int light = random(0,4);
  int timeOn = random(20,300);

  switch(light){
    case 0:
  digitalWrite(firstFloor, HIGH);   // set the LED on
  delay(timeOn);                  // wait for a second
  digitalWrite(firstFloor, LOW);    // set the LED off


  break;
  case 1:

    digitalWrite(secondFloor, HIGH);   // set the LED on
  delay(timeOn);                      // wait for a second
  digitalWrite(secondFloor, LOW);    // set the LED off


  break;

  case 2:

    digitalWrite(thirdFloor, HIGH);   // set the LED on
  delay(timeOn);                     // wait for a second
  digitalWrite(thirdFloor, LOW);    // set the LED off


  break;
  case 3:

    digitalWrite(fourthFloor, HIGH);   // set the LED on
  delay(timeOn);                      // wait for a second
  digitalWrite(fourthFloor, LOW);    // set the LED off


  break;
}}


