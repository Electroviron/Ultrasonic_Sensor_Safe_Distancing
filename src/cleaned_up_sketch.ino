// =======================
// Ultrasonic Distance Alert System
// HC-SR04 + LEDs + Buzzer
// =======================

// ---------- Pin Definitions ----------
const int buzzerPin = 9;

const int greenLED  = 6;
const int redLED    = 3;

const int trigPin   = 11;
const int echoPin   = 10;

// ---------- Constants ----------
const float SPEED_OF_SOUND = 0.034;   // cm/µs
const int SAFE_DISTANCE = 40;          // cm
const unsigned long ECHO_TIMEOUT = 30000; // µs (~5m)

// ---------- Setup ----------
void setup() {
  pinMode(buzzerPin, OUTPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

// ---------- Helper Functions ----------
void ledControl(int ledPin, bool state) {
  digitalWrite(ledPin, state);
}

void buzz(bool state) {
  digitalWrite(buzzerPin, state);
}

// ---------- Main Loop ----------
void loop() {

  // Send trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo duration
  long duration = pulseIn(echoPin, HIGH, ECHO_TIMEOUT);

  if (duration == 0) {
    Serial.println("Out of range!");
    ledControl(greenLED, LOW);
    ledControl(redLED, LOW);
    buzz(LOW);
  } 
  else {
    // Calculate distance
    float distance = (duration * SPEED_OF_SOUND) / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Decision logic
    if (distance >= SAFE_DISTANCE) {
      ledControl(greenLED, HIGH);
      ledControl(redLED, LOW);
      buzz(LOW);
    } else {
      ledControl(greenLED, LOW);
      ledControl(redLED, HIGH);
      buzz(HIGH);
    }
  }

  delay(500);
}
