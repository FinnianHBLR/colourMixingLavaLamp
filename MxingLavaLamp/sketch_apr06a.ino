//RED SENSE
const int brightnessDT1 = 7;
const int brightnessCLK1 = 6;
 int RotPosition1 = 0; 
 int rotation1;  
 int value1;
 boolean LeftRight1;


//////PINS FOR DIGITAL SENSE/////
//Blue
int blueSensePin = A0;
//Green
int greenSensePin = A1;

int redSense = 0;
int blueSense = 0;
int greenSense = 0;


////////INTS FOR SETTING//////
int brightness =0; 
int red = 0;
int blue = 0;
int green = 0;
////////INTS FOR SETTING//////

/////LED PIN OUTS///////
const int redLed = 11;
const int greenLed = 5;
const int blueLed = 3;  //WORKS

///////BTN SENSE///////

const int buttonPin = 8;

int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0; 
bool ledStatus;

/////LED PIN OUTS///////


bool lampState = false;

void setup() {

  Serial.begin(9600);
  

  //For RED.
  pinMode(brightnessDT1, INPUT);
  pinMode(brightnessCLK1, INPUT);
  rotation1 = digitalRead(brightnessCLK1);

//BLUE
  pinMode(blueSensePin, INPUT);

//GREEN
  pinMode(greenSensePin, INPUT);

pinMode(redLed, OUTPUT);
pinMode(greenLed, OUTPUT);
pinMode(blueLed, OUTPUT);

//BTN

pinMode(buttonPin, INPUT);


}

void loop() {


buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      
      Serial.println(buttonPushCounter);
      ledStatus = true;
   
    } else {
      // if the current state is LOW then the button went from on to off:
      buttonPushCounter++;
      ledStatus = true;
   
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }

//RESET counter wehn at 101 counts! (Don't want math getting too large)
if(buttonPushCounter == 101) {
  buttonPushCounter = 0;
  }

  
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;

   if(((buttonPushCounter /2) & 1) == 0) {
    red = calRed();
    green = analogRead(greenSensePin)/4 ;
    blue = analogRead(blueSensePin)/4 ;
    
    buttonState = digitalRead(buttonPin);
    
    analogWrite(redLed, red);
     analogWrite(greenLed, green);
     analogWrite(blueLed, blue);
  
    } else {
 
          
    if((buttonPushCounter & 1) == 0) {
      lamp();
      
     }
         
    }
  }

void lamp() {

  //Light sequence//
analogWrite(redLed, 255);
delay(1000);
analogWrite(blueLed, 255);
delay(1000);
analogWrite(greenLed, 255);
delay(3000);
analogWrite(redLed, 255);
analogWrite(blueLed, 0);
analogWrite(greenLed, 0);
delay(1000);
analogWrite(redLed, 0);
analogWrite(blueLed, 255);
analogWrite(greenLed, 0);
delay(1000);
analogWrite(greenLed, 0);
analogWrite(blueLed, 0);
analogWrite(greenLed, 255);
delay(1000);
analogWrite(greenLed, 0);
analogWrite(blueLed, 0);
analogWrite(greenLed, 0);
delay(300);
analogWrite(greenLed, 255);
delay(300);
analogWrite(blueLed, 255);
delay(300);
analogWrite(greenLed, 255);
delay(300);
//Light sequence//
      
int greenRand = random(0, 255);
int greenRandUp = random(0, 255);

int redRand = random(0, 255);
int redRandUp = random(0, 255);

int blueRand = random(0, 255);
int blueRandUp = random(0, 255);



//////////////////SMOOTH LIGHTING GENERATOR//////////////////
///////////////////////GREEN///////////////////////

while(true) {

  if(digitalRead(buttonPin) == LOW) {
  //Sets false to exit.  
  buttonPushCounter++;
  Serial.println(buttonPushCounter);
  //Breaks
  break;
  }
  //50 < 200
  if(greenRand < greenRandUp) {
    //Generate a new number if too low. NEEDS t count up to a random number

    greenRand++;
    //Serial.println(greenRand);

analogWrite(greenLed, greenRand);
    
    delay(5);
    if(greenRand == greenRandUp) {
      
      greenRandUp = random(0, 255);
      }
      //50 > 20
    } else if (greenRand > greenRandUp) {
      greenRand--;
      //Serial.println(greenRand);

analogWrite(greenLed, greenRand);
      delay(5);
      if(greenRand == greenRandUp) {
          greenRandUp = random(0, 255);
        
        }
      //Serial.println(greenRand);
      delay(100);

      
      }

///////////////////////GREEN///////////////////////
////////////////////////RED////////////////////////
  //50 < 200
  if(redRand < redRandUp) {
    //Generate a new number if too low. NEEDS t count up to a random number

    redRand++;
    //Serial.println(redRand);

analogWrite(redLed, redRand);
    
    delay(5);
    if(redRand == redRandUp) {
      
      redRandUp = random(0, 255);
      }
      //50 > 20
    } else if (redRand > redRandUp) {
      redRand--;
      //Serial.println(redRand);

analogWrite(redLed, redRand);
      delay(5);
      if(redRand == redRandUp) {
          redRandUp = random(0, 255);
        
        }
      //Serial.println(redRand);
      delay(100);

      
      }
////////////////////////RED/////////////////////////
////////////////////////BLUE////////////////////////

if(blueRand < blueRandUp) {
    //Generate a new number if too low. NEEDS t count up to a random number

    blueRand++;
    //Serial.println(blueRand);

analogWrite(blueLed, blueRand);
    
    delay(5);
    if(blueRand == blueRandUp) {
      
      blueRandUp = random(0, 255);
      }
      //50 > 20
    } else if (blueRand > blueRandUp) {
      blueRand--;
      //Serial.println(blueRand);

analogWrite(blueLed, blueRand);
      delay(5);
      if(blueRand == blueRandUp) {
          blueRandUp = random(0, 255);
        
        }
      //Serial.println(blueRand);
      delay(100);

 ////////////////////////BLUE////////////////////////
      }      
     }
    } 


  int calRed(){
  
    value1 = digitalRead(brightnessCLK1);
     if (value1 != rotation1){ // we use the DT pin to find out which way we turning.
     if (digitalRead(brightnessDT1) != value1) {  // Clockwise
       RotPosition1 = RotPosition1 + 15;
       LeftRight1 = true;
     } else { //Counterclockwise
       LeftRight1 = false;
       RotPosition1 = RotPosition1 - 15;
     }
    
    }
    if(RotPosition1 <= 0) {
      RotPosition1 = 0;
      
    } if (RotPosition1 >= 255) {
      RotPosition1 = 255;
      
    }
   
       rotation1 = value1;
  
  return RotPosition1;
  }
