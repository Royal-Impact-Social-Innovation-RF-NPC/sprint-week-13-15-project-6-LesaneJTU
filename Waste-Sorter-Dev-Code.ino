#include <WiFi.h>
#include <esp_now.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Servo binServo;
Servo gateServo;

#define SERVO_PIN 14
#define GATE_SERVO_PIN 4
#define METAL_LED 15
#define PLASTIC_LED 13
#define PAPER_LED 16

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

String material = "";
bool gotData = false;
void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingData, int len);
//void showOLED(String line1, String line2 = "");

typedef struct struct_message {
  char material[32];
} struct_message;

void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingData, int len) {
  struct_message data;
  memcpy(&data, incomingData, sizeof(data));
  material = String(data.material);
  material.trim();
  gotData = true;
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  esp_now_init();
  // Initialising ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    digitalWrite(METAL_LED, HIGH);
    digitalWrite(PLASTIC_LED, HIGH);
    digitalWrite(PAPER_LED, HIGH);
    delay(2000);
    return;
  }
  esp_now_register_recv_cb(OnDataRecv);

  /*ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);*/

  binServo.setPeriodHertz(50);
  gateServo.setPeriodHertz(50);

  binServo.attach(SERVO_PIN);
  gateServo.attach(GATE_SERVO_PIN);
  binServo.write(90);
  gateServo.write(90);

  
  pinMode(METAL_LED, OUTPUT);
  pinMode(PLASTIC_LED, OUTPUT);
  pinMode(PAPER_LED, OUTPUT);
  digitalWrite(METAL_LED, LOW);
  digitalWrite(PLASTIC_LED, LOW);
  digitalWrite(PAPER_LED, LOW);

  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("ESP32 SORTER");
  display.println("Waiting...");
  display.display();
}

void loop() {

  if (gotData) {
    Serial.println("Received: " + material);
    
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Detected:");
    display.println(material);
    display.display();

    
    if (material == "Metal") {
      digitalWrite(METAL_LED, HIGH);
      digitalWrite(PLASTIC_LED, LOW);
      digitalWrite(PAPER_LED, LOW);
      binServo.write(45);
      delay(2000);
      gateServo.write(0);
      delay(2000);
      gateServo.write(90);
      delay(2000);
    }
    else if (material == "Plastic") {
      digitalWrite(METAL_LED, LOW);
      digitalWrite(PLASTIC_LED, HIGH);
      digitalWrite(PAPER_LED, LOW);
      binServo.write(90);
      delay(2000);
      gateServo.write(0);
      delay(2000);
      gateServo.write(90);
      delay(2000);
    }
    else if (material == "Paper") {
      digitalWrite(METAL_LED, LOW);
      digitalWrite(PLASTIC_LED, LOW);
      digitalWrite(PAPER_LED, HIGH);
      binServo.write(135);
      delay(2000);
      gateServo.write(0);
      delay(2000);
      gateServo.write(90);
      delay(2000);
    }
    else {
      
      digitalWrite(METAL_LED, LOW);
      digitalWrite(PLASTIC_LED, LOW);
      digitalWrite(PAPER_LED, LOW);
    }

    delay(2000);

    
    digitalWrite(METAL_LED, LOW);
    digitalWrite(PLASTIC_LED, LOW);
    digitalWrite(PAPER_LED, LOW);
    gotData = false;
    material = "";

    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Waiting...");
    display.display();
  }
}
