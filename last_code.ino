#include <LiquidCrystal.h>  // Include the LiquidCrystal library to control the LCD display

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Set the pins for the LCD screen (RS, EN, D4, D5, D6, D7)
const int trigPin = 17;  // Define the trigPin connected to the ultrasonic sensor
const int echoPin = 16;  // Define the echoPin connected to the ultrasonic sensor

long duration;  // Variable to store the time it takes for the ultrasonic pulse to travel
int distance;    // Variable to store the calculated distance

void setup() {
  pinMode(trigPin, OUTPUT);  // Set the trigPin as an Output to trigger the ultrasonic pulse
  pinMode(echoPin, INPUT);   // Set the echoPin as an Input to read the echo signal
  pinMode(13, OUTPUT);       // Pin 13 is configured as a VDD for the sensor (if needed)

  Serial.begin(9600);        // Start serial communication at 9600 baud rate
  lcd.begin(16, 2);          // Initialize the LCD screen with 16 columns and 2 rows
  lcd.print("Optic Wizards"); // Display the project name on the LCD for 5 seconds
  delay(5000);               // Wait for 5 seconds
  lcd.clear();               // Clear the LCD screen to prepare for the next display
}

void loop() {
  // Clears the trigPin before triggering the pulse
  digitalWrite(13, HIGH);     // Set pin 13 high to power the sensor (if applicable)
  digitalWrite(trigPin, LOW); // Ensure the trigPin is low
  delayMicroseconds(2);       // Wait for a very short time to ensure pulse starts from 0

  // Send the 10-microsecond pulse to the trigPin to trigger the ultrasonic sensor
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);      
  digitalWrite(trigPin, LOW); 

  // Measure the time it takes for the ultrasonic pulse to return
  duration = pulseIn(echoPin, HIGH); 

  // Calculate the distance based on the time duration of the pulse travel
  distance = duration * 0.034 / 2;  // Speed of sound is 0.034 cm/µs. Divide by 2 because the pulse travels forward and back.

  // Display the distance on the Serial Monitor for debugging purposes
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance != 0) {  // Only print the distance if it’s a valid reading
    lcd.print("Distance: ");   // Display "Distance" on the LCD
    lcd.print(distance);       // Display the measured distance value
    delay(1000);               // Wait for 1 second
    lcd.clear();               // Clear the LCD screen before the next reading
  }
}
