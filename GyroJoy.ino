#include<Wire.h>

int XVal;
int YVal;
int16_t AccelX;
int16_t AccelY;
int16_t AccelZ;
int16_t Temp;
int16_t GyroX;
int16_t GyroY;
int16_t GyroZ;

int setting = 0;
int incomingByte = 0;
const int x_axis = A0;
const int y_axis = A1;
const int buzzer = 2;
const int MPU_addr = 0x68;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  pinMode(x_axis, INPUT);
  pinMode(y_axis, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  noTone(buzzer);
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 12, true);
  
  XVal = analogRead(x_axis);
  YVal = analogRead(y_axis);

  AccelX = Wire.read() << 8 | Wire.read();
  AccelY = Wire.read() << 8 | Wire.read();
  AccelZ = Wire.read() << 8 | Wire.read();
  GyroX = Wire.read() << 8 | Wire.read();
  GyroY = Wire.read() << 8 | Wire.read();
  GyroZ = Wire.read() << 8 | Wire.read();

  if (setting == 0) {
    Serial.print(XVal);
    Serial.print(',');
    Serial.println(YVal);
  }

  if (setting == 1) {
    Serial.print(GyroX);
    Serial.print(',');
    Serial.println(GyroY);
  }

  if (Serial.available() > 0){
    incomingByte = Serial.read();
  }

  if (incomingByte == 'E'){
    tone(buzzer, 1000); 
    incomingByte = 0;
  }
  
  delay(300);
}
