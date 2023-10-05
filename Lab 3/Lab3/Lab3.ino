// Micro 2 Lab 3
// Fall 2021
// Joseph Taylor, Elizabeth Brown, Cody Bellec
// November 2, 2021
// the following resource was used to help get the ds1307 working:
// https://create.arduino.cc/projecthub/electropeak/interfacing-ds1307-rtc-module-with-arduino-make-a-reminder-08cb61

// todo:
// add LCD functionality
// add IT receiver functionality
// verify compliance with spec
// cleanup

#include<Wire.h>
#include "RTClib.h" // note: need to copy RTClib/ to "Arduino/libraries/"
RTC_DS1307 rtc; // establish ds1307 object

// pin declarations
const int buttonPin = 2;
const int motorEnable = 3;
const int motorDirA = 4;
const int motorDirB = 5;

// variable declarations
bool buttonFlag = false; // used for button ISR
bool timerFlag = false; // used for timer ISR
int fanDirection = 1;

// ISR's for button and timer
ISR(TIMER1_COMPA_vect) { timerFlag = true; }
void buttonPress() { buttonFlag = true; }

void setup(){
  Serial.begin(9600);
  Wire.begin(); // establish I2C bus
  rtc.begin();
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // only needed once

  pinMode(motorEnable, OUTPUT);
  pinMode(motorDirA, OUTPUT);
  pinMode(motorDirB, OUTPUT);
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPress, RISING);

  cli(); // disable interrupts

  // set timer1 interrupt at 1Hz
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; // initialize counter value to 0
  OCR1A = 15624; // frequency set, = (16*10^6) / (1hz*1024) - 1 (must be <65536)
  TCCR1B |= (1 << WGM12); // turn on CTC mode
  TCCR1B |= (1 << CS12) | (1 << CS10); // Set CS10 and CS12 bits for 1024 prescaler
  TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt
  
  sei(); // enable interrupts
}

void loop() {
  digitalWrite(motorDirA, (fanDirection == 1));
  digitalWrite(motorDirB, (fanDirection == -1));
  
  if (buttonFlag) {
    Serial.println("Button was pressed.");
    fanDirection *= -1; // reverse direction
    while (digitalRead(buttonPin)) delay(10); // wait for button release
    buttonFlag = false;
  }

  if (timerFlag) {
    DateTime now = rtc.now();
    // print time to serial monitor
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    // if at the beginning of a minute, turn fan on for 30 seconds
    if (now.second() == 0) { analogWrite(motorEnable, 255); }
    if (now.second() == 30) { analogWrite(motorEnable, LOW); }
    
    timerFlag = false;
  }
  delay(10);
}
