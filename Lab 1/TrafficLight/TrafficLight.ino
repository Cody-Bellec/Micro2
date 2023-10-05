// TrafficLight.ino
// Joseph Taylor, Elizabeth Brown, Cody Bellec
// this code incorporates components of the Elegoo sample code, found at www.elegoo.com
// also incorporates code from https://www.instructables.com/Arduino-Timer-Interrupts/

// revision history:
// 9/8/21 jct - file init
// 9/13/21 jct - functional completion and cleanup
// 9/23/21 jct - minor format edit

// pin declarations
int button = 2;  // button; 10Kohm pulldown to GND, other end to +5V
int red = 3;     // red LED; through a 220ohm to GND
int yellow = 4;  // yellow LED; through a 220ohm to GND
int green = 5;   // green LED; through a 220ohm to GND
int buzzer = 13; // active buzzer; positive to pin 13, negative to GND

// pin declarations for 7-segment display
int data = 6;    // 74HC595 pin 14 DS
int latch = 7;   // 74HC595 pin 12 STCP
int clock = 8;   // 74HC595 pin 11 SHCP
int dig1 = 9;    // cathode for digit 1
int dig2 = 10;   // cathode for digit 2

// variable declarations
bool buttonFlag = false;
bool timerFlag = false;
unsigned int counter;
unsigned char sevenSegTable[]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00};

// ISR's for button and timer
ISR(TIMER1_COMPA_vect) { timerFlag = true; }
void buttonPress() { buttonFlag = true; }

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT);
  attachInterrupt(digitalPinToInterrupt(button), buttonPress, CHANGE);
  pinMode(buzzer, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(dig1, OUTPUT);
  pinMode(dig2, OUTPUT);

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

  // disable 7-segment output
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, HIGH);

  // flash red until button press
  int lightFlash = red;
  while(!buttonFlag){
    if (timerFlag){
      setLight(lightFlash *= -1);
      timerFlag = false;
    }
    delay(1);
  }
}

void Display(unsigned int num)
{
  // set shift register for first digit and flash for 5ms
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, sevenSegTable[num / 10]);
  digitalWrite(latch, HIGH);
  digitalWrite(dig1, LOW);
  delay(5);
  digitalWrite(dig1, HIGH);

  // set shift register for second digit and flash for 5ms
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, sevenSegTable[num % 10]);
  digitalWrite(latch, HIGH);
  digitalWrite(dig2, LOW);
  delay(5);
  digitalWrite(dig2, HIGH);
}

void setLight(int color) {
  digitalWrite(red, color == red);
  digitalWrite(yellow, color == yellow);
  digitalWrite(green, color == green);
}

void runDisplay() {
  if (timerFlag) {
      counter--;
      timerFlag = false;
    }
  digitalWrite(buzzer, counter <= 3);
  Display(counter);
}

void loop() {
  // state 1: red light
  setLight(red);
  counter = 20;
  while (counter > 0) runDisplay();

  // state 2: green light
  setLight(green);
  counter = 20;
  while (counter > 0) runDisplay();

  // state 3: yellow light
  setLight(yellow);
  counter = 3;
  while (counter > 0) runDisplay();
}
