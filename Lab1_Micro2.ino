// components are linked to destination pins on adurino can be changed
int redLed = 13;
int yellowLed = 12;
int greenLed = 11;
int button = 10;
int buzzer = 9;
int constState = 0;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(button); //reads if button is pressed and if so turns onstate flag
  if (buttonState == HIGH)
    constState = 1;

   if (constState){
      digitalWrite(redLed, HIGH);
      delay(15000); //delay for light
      tone(buzzer, 1000);
      delay(2000); //delay for buzzer
      noTone(buzzer);
      digitalWrite(redLed, LOW);

      digitalWrite(greenLed, HIGH);
      delay(15000);
      tone(buzzer, 1000); 
      delay(2000);        
      noTone(buzzer);     
      digitalWrite(greenLed, LOW);

      digitalWrite(yellowLed, HIGH);
      delay(3000);
      tone(buzzer, 1000);
      delay(1000);
      noTone(buzzer);
      digitalWrite(yellowLed, LOW);
   }
      else{ //no button pressed
      digitalWrite(redLed, HIGH);
      delay(500);
      digitalWrite(redLed, LOW);
      delay(500);
   }
}
