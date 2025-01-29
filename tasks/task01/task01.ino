// constants won't change. Used here to set a pin number:
const int ledPin1 =  3;// the number of the LED pin
const int ledPin2 =  5;
const int ledPin3 =  6;
const int ledPin4 =  9;
const int ledPin5 =  10;

// Variables will change:
int ledState1 = LOW;             // ledState used to set the LED
int ledState2 = LOW;
int ledState3 = LOW;
int ledState4 = LOW;
int ledState5 = LOW;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis1 = 0; // will store last time LED was updated
unsigned long previousMillis2 = 0; // will store last time LED was updated

unsigned long previousMicros3 = 0;
unsigned long previousMicros4 = 0;
unsigned long previousMicros5 = 0;

// constants won't change:
const long interval1 = 10;// interval at which to blink (milliseconds)
const long interval2 = 1;
const long interval3 = 500;
const long interval4 = 100;
const long interval5 = 50;

void setup() {
  // set the digital pin as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();
  unsigned long currentMicros = micros();

  if (currentMillis - previousMillis1 >= interval1) {
    // save the last time you blinked the LED
    previousMillis1 = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState1 == LOW) {
      ledState1 = HIGH;
    } else {
      ledState1 = LOW;
    }
  }
  if (currentMillis - previousMillis2 >= interval2) {
    // save the last time you blinked the LED
    previousMillis2 = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState2 == LOW) {
      ledState2 = HIGH;
    } else {
      ledState2 = LOW;
    }
  }
  if (currentMicros - previousMicros3 >= interval3) {
    // save the last time you blinked the LED
    previousMicros3 = currentMicros;

    // if the LED is off turn it on and vice-versa:
    if (ledState3 == LOW) {
      ledState3 = HIGH;
    } else {
      ledState3 = LOW;
    }
  }
  if (currentMicros - previousMicros4 >= interval4) {
    // save the last time you blinked the LED
    previousMicros4 = currentMicros;

    // if the LED is off turn it on and vice-versa:
    if (ledState4 == LOW) {
      ledState4 = HIGH;
    } else {
      ledState4 = LOW;
    }
  }
  if (currentMicros - previousMicros5 >= interval5) {
    // save the last time you blinked the LED
    previousMicros5 = currentMicros;

    // if the LED is off turn it on and vice-versa:
    if (ledState5 == LOW) {
      ledState5 = HIGH;
    } else {
      ledState5 = LOW;
    }
  }
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin1, ledState1);
    digitalWrite(ledPin2, ledState2);
    digitalWrite(ledPin3, ledState3);
    digitalWrite(ledPin4, ledState4);
    digitalWrite(ledPin5, ledState5);
    
  
}
