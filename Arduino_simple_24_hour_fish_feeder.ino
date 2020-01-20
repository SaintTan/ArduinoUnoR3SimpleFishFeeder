#include <Servo.h>

Servo myservo;

unsigned long timenow;
unsigned long timebefore = 0;
const int buttonPin = 2;
const unsigned long feedtime = 86400000;
bool feedstart = false;

int buttonState = 0; 
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if(buttonState == LOW){
    feedstart = true;
    myservo.write(180);
    delay(1500);
    delay(5000);
    myservo.write(0);
    delay(1500);
  }
  else if(feedstart){
    timenow= millis();

    unsigned long timebetween = timenow - timebefore;
    if(timebetween >= feedtime){
      Serial.print(timebetween);
      timebefore = timenow;
      myservo.write(180);
      delay(1500);
      delay(5000);
      myservo.write(0);
      delay(1500);
    }
    else if (timebetween <= 0){
      timebefore = timenow;
    }
  }
  
}
