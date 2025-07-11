#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD setup: 16x2 screen using common I2C address
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin assignments
const int trigPin = 12;     // Ultrasonic trigger pin
const int echoPin = 13;     // Ultrasonic echo pin
const int ledPin = 7;       // Green LED to indicate detection
const int buzzerPin = 4;    // Buzzer to give audio feedback

Servo gateServo;            // Servo controlling the mini gate as object

// Gate positions in degrees
const int closedPos = 180;  // Fully closed position
const int openPos = 90;     // Fully open position

const int threshold = 20;   // Distance (in cm) from object to trigger gate opening

// Display an animated "Awaiting Entry..." message on the LCD
void displayEntryMessage() {
  lcd.clear();
  lcd.setCursor(0, 0);
  String message = "Awaiting Entry...";
  for (int i = 0; i < message.length(); i++) {
    lcd.print(message[i]);
    delay(150); // Typing animation effect
  }
}

// Smoothly moves servo from startAngle to endAngle (forward or reverse) 
void smoothMove(Servo &servo, int startAngle, int endAngle, int stepDelay = 10) {
  int step = (startAngle < endAngle) ? 1 : -1;
  for (int pos = startAngle; pos != endAngle; pos += step) {
    servo.write(pos);
    delay(stepDelay);
  }
  servo.write(endAngle); 
}

void setup() {
  // Setup pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Initialize and set servo to closed
  gateServo.attach(9);
  gateServo.write(closedPos);

  // LCD init
  lcd.init();
  lcd.backlight();
  displayEntryMessage();

  // Start serial for (debugging purposes only)
  Serial.begin(9600);
  delay(1000); // Small startup delay
}

// Measures distance using the ultrasonic sensor
long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // 30 ms timeout
  long distance = duration * 0.034 / 2; // Convert to cm
  return distance;
}

void loop() {
  long distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < threshold) {
    // Object detected in range
    digitalWrite(ledPin, HIGH);// Turn on LED
    tone(buzzerPin, 1000);// Beep
    delay(200);
    noTone(buzzerPin);

    // Greet user
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Welcome, Enjoy!");

    // Open then close the gate with a pause
    smoothMove(gateServo, closedPos, openPos, 5);
    delay(2000); // Gate stays open for 2 seconds
    smoothMove(gateServo, openPos, closedPos, 5);

    digitalWrite(ledPin, LOW); // Turn off LED after motion
    displayEntryMessage(); // Reset welcome message
  } else {
    // No object detected
    digitalWrite(ledPin, LOW);
  }

  delay(200); // Debounce and reduce serial noise
}