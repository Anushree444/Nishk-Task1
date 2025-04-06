#include <Servo.h>

Servo myServo;

int ldrLeft = A0;
int ldrRight = A1;
int pos = 90; // Start in middle

void setup() {
  myServo.attach(9);  // Servo signal on D9
  myServo.write(pos);
  Serial.begin(9600);
}

void loop() {
  int leftValue = analogRead(ldrLeft);
  int rightValue = analogRead(ldrRight);

  Serial.print("LDR Left: ");
  Serial.print(leftValue);
  Serial.print(" | LDR Right: ");
  Serial.println(rightValue);

  int diff = leftValue - rightValue;
  
  if (abs(diff) > 50) { // Threshold to avoid unnecessary jitter
  if (diff > 0 && pos < 180) pos++;
  else if (diff < 0 && pos > 0) pos--;
  myServo.write(pos);
  delay(15);  // Smooth movement
}


  if (abs(diff) > 50) { // Adjust sensitivity
    if (diff > 0 && pos < 180) {
      pos++;
    } else if (diff < 0 && pos > 0) {
      pos--;
    }
    myServo.write(pos);
  }

  delay(100); // Smooth movement
}
