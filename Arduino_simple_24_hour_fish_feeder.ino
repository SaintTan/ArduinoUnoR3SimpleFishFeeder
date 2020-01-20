#include <Servo.h>

//innitialize all variables
Servo myservo;

unsigned long timenow;
unsigned long timebefore = 0;
const int buttonPin = 2;
const unsigned long feedtime = 86400000;
bool feedstart = false;

int buttonState = 0;

void setup() {
  // attaching servo to digital input/output 9
  myservo.attach(9);
  Serial.begin(9600);
  //button setup to reduce parts used for buttons
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop() {
  //read the state of the button
  buttonState = digitalRead(buttonPin);
  //dispense food when the button is pressed and start the timer for daily feeding
  if(buttonState == LOW){
    feedstart = true;
    myservo.write(90);
    delay(1500);
    delay(5000);
    myservo.write(0);
    delay(1500);
  }
  //dispense food when it reaches 24 hours
  else if(feedstart){
    timenow= millis();

    unsigned long timebetween = timenow - timebefore;
    if(timebetween >= feedtime){
      Serial.print(timebetween);
      timebefore = timenow;
      myservo.write(90);
      delay(1500);
      delay(5000);
      myservo.write(0);
      delay(1500);
    }
    //reseting timer if timenow goes more than 50 days in milli seconds
    else if (timebetween <= 0){
      timebefore = timenow;
    }
  }
  
}
