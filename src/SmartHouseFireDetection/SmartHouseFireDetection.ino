
#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// -------- PIN CONFIGURATION --------
const byte FLAME_PIN  = 2;
const byte DHT_PIN    = 4;
const byte BUZZER_PIN = 8;
const byte LED_PIN    = 9;
const byte SERVO_PIN  = 10;

// -------- SENSOR CONFIGURATION --------
#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo switchServo;

// Change these if your tested switch positions differ
const int OFF_ANGLE = 60;
const int ON_ANGLE = 125;

// Your flame sensor was tested as active LOW
const byte FLAME_ACTIVE = LOW;

// Alarm state
bool fireDetected = false;
bool previousFireDetected = false;

// DHT11 reading schedule
unsigned long lastDHTRead = 0;
const unsigned long DHT_INTERVAL = 2000;

float temperature = 0;
float humidity = 0;
bool dhtValid = false;

// -------- BUZZER CONTROL --------
void alarmOn() {
  digitalWrite(LED_PIN, HIGH);
  tone(BUZZER_PIN, 2000);
}

void alarmOff() {
  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);
}

void setup() {
  Serial.begin(9600);

  pinMode(FLAME_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  alarmOff();

  // LCD initialization
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Smart House");
  lcd.setCursor(0, 1);
  lcd.print("Fire Detection");
  delay(1500);

  // DHT11 initialization
  dht.begin();

  // Servo starts with switch in OFF position
  switchServo.attach(SERVO_PIN);
  switchServo.write(OFF_ANGLE);
  delay(800);

  lcd.clear();

  Serial.println("Smart House Fire System Ready");
  Serial.println("Flame sensor active LOW");
}

void loop() {
  // 1. Read flame sensor
  int flameValue = digitalRead(FLAME_PIN);
  fireDetected = (flameValue == FLAME_ACTIVE);

  // 2. Respond only when alarm state changes
  if (fireDetected != previousFireDetected) {
    if (fireDetected) {
      Serial.println("ALERT: Flame detection signal!");

      alarmOn();

      // Move servo to operate the low-voltage rocker switch
      switchServo.write(ON_ANGLE);
    } else {
      Serial.println("Detection signal cleared");

      alarmOff();

      // Return switch to OFF position
      switchServo.write(OFF_ANGLE);
    }

    previousFireDetected = fireDetected;
  }

  // 3. Read DHT11 every two seconds
  if (millis() - lastDHTRead >= DHT_INTERVAL) {
    lastDHTRead = millis();

    float newHumidity = dht.readHumidity();
    float newTemperature = dht.readTemperature();

    if (!isnan(newHumidity) && !isnan(newTemperature)) {
      humidity = newHumidity;
      temperature = newTemperature;
      dhtValid = true;

      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.print(" C | Humidity: ");
      Serial.print(humidity);
      Serial.println(" %");
    } else {
      Serial.println("DHT11 reading failed");
    }
  }

  // 4. LCD first row: temperature and humidity
  lcd.setCursor(0, 0);

  if (dhtValid) {
    lcd.print("T:");
    lcd.print(temperature, 1);
    lcd.write((byte)223);
    lcd.print("C H:");
    lcd.print(humidity, 0);
    lcd.print("%   ");
  } else {
    lcd.print("Reading DHT11... ");
  }

  // 5. LCD second row: alarm status
  lcd.setCursor(0, 1);

  if (fireDetected) {
    lcd.print("FIRE DETECTED!  ");
  } else {
    lcd.print("Status: Normal  ");
  }

  delay(100);
}
