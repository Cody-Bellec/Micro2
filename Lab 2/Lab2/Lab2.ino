#include<Wire.h>

int xVal, yVal, inByte = 0;
const int xInPin = A0;
const int yInPin = A1;
const int buzzerPin = 4;
const int MPU_addr=0x68;
int16_t xAc,yAc,zAc,Tmp,xGy,yGy,zGy;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  pinMode(xInPin, INPUT);
  pinMode(yInPin, INPUT);
}

void loop() {
  noTone(buzzerPin);
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  
  xAc=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  yAc=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  zAc=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  xGy=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  yGy=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  zGy=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  // handle joystick input
  xVal = analogRead(xInPin);
  yVal = analogRead(yInPin);
  if (xVal < 128) Serial.print("D");
  if (xVal > 896) Serial.print("A");
  if (yVal < 128) Serial.print("W");
  if (yVal > 896) Serial.print("S");

  // handle gyro input if gyro isn't facing downward
  if (zAc > 0) {
    if (xAc < -8000) Serial.print("S");
    if (xAc > 8000) Serial.print("W");
    if (yAc < -8000) Serial.print("D");
    if (yAc > 8000) Serial.print("A");
  }

  // detect shake of accelerometer
  if (xGy > 17000 || xGy < -17000) Serial.print("B");
  if (yGy > 17000 || yGy < -17000) Serial.print("B");
  if (zGy > 17000 || zGy < -17000) Serial.print("B");
  
  // data available
  if (Serial.available() > 0) inByte = Serial.read();

  if (inByte == 'E'){
    tone(buzzerPin, 1000); // Send 1KHz sound signal...
    inByte = 0;
  }

  delay(100); // don't refresh too quick
}
