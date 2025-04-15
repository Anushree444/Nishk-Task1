//project 3: mars emergency flap with potentiometer and push button
#include <Servo.h>

const int tempInput = A0;       // temp sensor simulating temperature
const int ledPin = 7;           // Warning LED
const int servoPin = 9;         // Servo motor
const int buttonPin = 4;        // Push button for manual emergency flap

Servo flapServo;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Configure button with pull-up
  flapServo.attach(servoPin);
  flapServo.write(0); // Start with flap closed
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  int analogVal = analogRead(tempInput);
  
  // Simulate temperature between -50°C to 100°C
  float temperature = map(analogVal, 0, 1023, -50, 100);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  // Button pressed = emergency mode
  if (buttonState == LOW) {
    Serial.println("Manual Emergency Triggered!");
    digitalWrite(ledPin, HIGH);
    flapServo.write(90);
  }
  // Automatic temperature check
  else if (temperature < 5 || temperature > 40) {
    digitalWrite(ledPin, HIGH);
    flapServo.write(90);
  } else {
    digitalWrite(ledPin, LOW);
    flapServo.write(0);
  }

  delay(1000);
}
