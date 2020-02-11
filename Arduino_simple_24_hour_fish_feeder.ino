#include <Servo.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/io.h>

//innitialize all variables
Servo myservo;

unsigned long timenow = 0;
unsigned long timebefore = 0;
unsigned long timebetween = 0;
const int buttonPin = 2;

const int servoDelay = 1500;
const int feedDelay = 3000;
const unsigned long dayTime = 86400000;
const unsigned long feedTime = 17000 -(2*servoDelay) - feedDelay; 
const unsigned long feedCycle = (feedTime/8000)+1;
bool feedstart = false;

int buttonState = 0;
unsigned long nbr_remaining = 0 ;

ISR(WDT_vect){
  wdt_reset();
}

void setup() {
  // attaching servo to digital input/output 9
  myservo.attach(9);
  myservo.write(0);
  Serial.begin(9600);
  //button setup 
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  configure_wdt();
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if(buttonState == LOW){
    feedstart = true;
  }
  if(feedstart){
    dispenseFood();
    Serial.println("starto");
    Serial.flush();
    sleepControl(feedCycle);
  }
}

void configure_wdt(){
  cli();
  MCUSR = 0;
  WDTCSR |= 0b00011000;
  WDTCSR = 0b01000000 | 0b100001;
  sei();
}

void sleepControl(unsigned long ncycles){
  nbr_remaining = ncycles;
  
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  power_adc_disable();
  while (nbr_remaining > 0){
    sleep_mode();
    sleep_disable();
    nbr_remaining = nbr_remaining - 1;
  }
  power_all_enable();
}

void dispenseFood(){
  myservo.write(90);
  delay(servoDelay);
  delay(feedDelay);
  myservo.write(0);
  delay(servoDelay);
}
