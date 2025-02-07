/*  
Project: DC-motor boat
Author: Gaston Sandegård
Controlls two DC-motors that propel a boat by powering on and off the motors. 
Button 1 and 2 turn on and off the DC-motors while button 3 reverses the direction of both motors
*/

// Define constants
const int motor1Pin1 = 3;  
const int motor1Pin2 = 4;  
const int motor2Pin1 = 5;  
const int motor2Pin2 = 6;  

// Define button pins for controlling the motors  
const int button1Pin = 7;  // Button to control Motor 1  
const int button2Pin = 8;  // Button to control Motor 2  
const int button3Pin = 9;  // Button to toggle motor direction  

// Variable to track motor rotation direction  
bool motorDirection = true;  // true for forward, false for reverse  

void setup() {  
  // Set motor pins as outputs  
  pinMode(motor1Pin1, OUTPUT);  
  pinMode(motor1Pin2, OUTPUT);  
  pinMode(motor2Pin1, OUTPUT);  
  pinMode(motor2Pin2, OUTPUT);  

  // Set button pins as inputs with pull-up resistors  
  pinMode(button1Pin, INPUT_PULLUP);  
  pinMode(button2Pin, INPUT_PULLUP);  
  pinMode(button3Pin, INPUT_PULLUP);  
}

void loop() {  
  // Read button states and invert logic due to pull-up resistors  
  bool button1State = !digitalRead(button1Pin);  
  bool button2State = !digitalRead(button2Pin);  
  bool button3State = !digitalRead(button3Pin);  

  // Toggle motor direction when button 3 is pressed  
  if (button3State) {  
    motorDirection = !motorDirection;  
    delay(300);  // Debounce delay to avoid multiple triggers  
  }

  // Control Motor 1 based on button 1 state  
  if (button1State) {  
    driveMotor(motor1Pin1, motor1Pin2, motorDirection);  
  } else {  
    stopMotor(motor1Pin1, motor1Pin2);  
  }

  // Control Motor 2 based on button 2 state  
  if (button2State) {  
    driveMotor(motor2Pin1, motor2Pin2, motorDirection);  
  } else {  
    stopMotor(motor2Pin1, motor2Pin2);  
  }  
}

// Function to drive a motor in a specific direction  
void driveMotor(int pin1, int pin2, bool direction) {  
  if (direction) {  
    digitalWrite(pin1, HIGH);  
    digitalWrite(pin2, LOW);  // Forward  
  } else {  
    digitalWrite(pin1, LOW);  
    digitalWrite(pin2, HIGH);  // Reverse  
  }  
}

// Function that sets both motor pins to low (off)
// Returns void  
void stopMotor(int pin1, int pin2) {  
  digitalWrite(pin1, LOW);  
  digitalWrite(pin2, LOW);  
}
