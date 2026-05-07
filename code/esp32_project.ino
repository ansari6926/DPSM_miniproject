#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pin Definitions for ESP32
#define TRIG_PIN 5
#define ECHO_PIN 18
#define PIR_PIN 19
#define LED_GREEN 25
#define LED_YELLOW 26
#define LED_RED 27
#define BUZZER_PIN 14

// Thresholds for Crowd Density (Simulated based on proximity)
#define DISTANCE_MAX 200 // Maximum distance to consider for crowd tracking
#define CROWD_LOW 50
#define CROWD_MED 100
#define CROWD_HIGH 150

int simulatedCrowdCount = 0;
bool motionDetected = false;

void setup() {
  Serial.begin(115200);
  
  // Initialize Sensor Pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
  
  // Initialize Actuator Pins
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Initialize OLED Display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 10);
  display.println("Smart Railway System");
  display.println("Initializing...");
  display.display();
  delay(2000);
}

void loop() {
  // Read PIR sensor for motion
  motionDetected = digitalRead(PIR_PIN) == HIGH;
  
  // Read Ultrasonic distance to simulate crowd density
  long duration;
  float distance;
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout
  if (duration == 0) {
    distance = DISTANCE_MAX; // No object detected within range
  } else {
    distance = (duration * 0.0343) / 2;
  }
  
  // Crowd simulation logic based on ultrasonic distance
  // In a real scenario, this could be counting people passing or CV.
  // Here we use proximity to simulate crowd density factor.
  if (distance < 50) {
    simulatedCrowdCount = 180; // High crowd density
  } else if (distance < 150) {
    simulatedCrowdCount = 90;  // Medium crowd density
  } else {
    simulatedCrowdCount = 30;  // Low crowd density
  }

  // Output Analytics to Serial Monitor
  Serial.print("Motion: ");
  Serial.print(motionDetected ? "YES" : "NO");
  Serial.print(" | Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Estimated Crowd: ");
  Serial.println(simulatedCrowdCount);

  // Reset Indication Status
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  String statusStr = "";

  // Evaluate Safety Thresholds
  if (simulatedCrowdCount >= CROWD_HIGH) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(BUZZER_PIN, HIGH); // Alert for overcrowding
    statusStr = "DANGER: HIGH";
  } else if (simulatedCrowdCount >= CROWD_MED) {
    digitalWrite(LED_YELLOW, HIGH);
    statusStr = "WARNING: MEDIUM";
  } else {
    digitalWrite(LED_GREEN, HIGH);
    statusStr = "SAFE: LOW";
  }

  // Update OLED Display with Live Status
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Railway Crowd Status");
  
  display.drawLine(0, 10, 128, 10, SSD1306_WHITE);
  
  display.setCursor(0, 20);
  display.print("Crowd Level: ");
  display.println(simulatedCrowdCount);

  display.setCursor(0, 35);
  display.print("Motion: ");
  display.println(motionDetected ? "Detected" : "None");

  display.setCursor(0, 50);
  display.print("Status: ");
  display.println(statusStr);
  
  display.display();
  
  delay(500); // Delay for loop stability and readability
}
