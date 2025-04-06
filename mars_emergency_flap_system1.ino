#include <Servo.h>

const int tempInput = A0;
const int ledPin = 7;
const int servoPin = 9;

Servo flapServo;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  flapServo.attach(servoPin);
  flapServo.write(0); // Start with flap closed
}

void loop() {
  int analogVal = analogRead(tempInput);
  
  // Simulate temperature between -50°C to 100°C (you can map differently if needed)
  float temperature = map(analogVal, 0, 1023, -50, 100);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  if (temperature < 5 || temperature > 40) {
    digitalWrite(ledPin, HIGH);     // Warning LED
    flapServo.write(90);            // Flap deploy
  } else {
    digitalWrite(ledPin, LOW);
    flapServo.write(0);             // Flap closed
  }

  delay(1000);
}
