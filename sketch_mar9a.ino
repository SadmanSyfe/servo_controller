#include <Servo.h>

Servo myservo1; 
Servo myservo2; 


int stopSpeed = 1500;   
int forwardSpeed = 1600; 
int reverseSpeed = 1400; 
int nudgeTime = 150;     

void setup() {
  Serial.begin(9600);
  
  
  myservo1.attach(6, 500, 2500);
  myservo2.attach(5, 500, 2500);
  
  myservo1.writeMicroseconds(stopSpeed);
  myservo2.writeMicroseconds(stopSpeed);
  
  Serial.println("Camera Arm Ready!");
  Serial.println("Use 'w' (Up), 's' (Down), 'a' (Left), 'd' (Right).");
}

void loop() {
  if (Serial.available() > 0) {
    char a = Serial.read();
    
    
    if (a == 'a') {
      Serial.println("Moving Left...");
      myservo1.writeMicroseconds(forwardSpeed); 
      delay(nudgeTime);                       
      myservo1.writeMicroseconds(stopSpeed); 
    } 
    
    else if (a == 'd') {
      Serial.println("Moving Right...");
      myservo1.writeMicroseconds(reverseSpeed); 
      delay(nudgeTime);                       
      myservo1.writeMicroseconds(stopSpeed); 
    }
    else if (a == 's') {
      Serial.println("Moving Down...");
      myservo2.writeMicroseconds(forwardSpeed); 
      delay(nudgeTime);                       
      myservo2.writeMicroseconds(stopSpeed); 
    } 
    else if (a == 'w') {
      Serial.println("Moving Up...");
      myservo2.writeMicroseconds(reverseSpeed); 
      delay(nudgeTime);                       
      myservo2.writeMicroseconds(stopSpeed); 
    }
  }
}