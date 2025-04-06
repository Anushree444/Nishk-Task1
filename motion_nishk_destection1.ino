#define PIR_PIN 2   // PIR sensor output connected to D2
#define LED_PIN 7   // LED connected to D7

void setup() {
    pinMode(PIR_PIN, INPUT); 
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int motion = digitalRead(PIR_PIN); // Read PIR sensor

    if (motion == HIGH) {  
        digitalWrite(LED_PIN, HIGH); // Turn ON LED
        Serial.println("Motion Detected! LED ON");
    } else {
        digitalWrite(LED_PIN, LOW); // Turn OFF LED
        Serial.println("No Motion. LED OFF");
    }

    delay(500); // Short delay to stabilize
}
