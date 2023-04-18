#include <Servo.h>
#include <Stepper.h>
///////// servc moves from  right to left
double angle1 = 130;
double  angle2 = 130 -20 ;
double angle3 = 130 + 40 ;
double angle4 = 130 + 45 ;
const int RELAY_PIN = 7;
// Define the number of steps per revolution for the stepper motor
const int stepsPerRevolution = 200;

// Create a new Stepper object with the number of steps and the pins used for the motor coils
Stepper motor(stepsPerRevolution, 8, 9, 10, 11);
Servo myservo;

double an = 1.9634 * 1e-5;   // replace 0.0 with the desired value of an
double ab = 3.848 * 1e-3;   // replace 0.0 with the desired value of ab
double g = 9.81;   // gravitational acceleration (m/s^2)    // replace 0.0 with the desired value of t

 // Define the number of milliseconds to run the motor
 // 7 seconds
  double R1= 0.90;
  double h=0.59;
  double y1= (R1*R1)/(4*h)+0.17;
  ///Serial.println(yr);
  double L1=0.57-y1;
  double v=  0.0058;
  double T1= (L1)/v;
  const unsigned long motorRunTime1 = T1*1000 ;
  /////////////////////////
  double R2= 0.53;
  double w2 = (-an/ab)*sqrt(2*g)*3+(2*sqrt(h));
  double h2 = (w2*((-an/ab)*sqrt(2*g)*3+(2*sqrt(h))))/ 4; 
  double y2= (R2*R2)/(4*h2)+0.17;

  double L2=y1-y2;
  double T2= (L2)/v;
  
  const unsigned long motorRunTime2 = T2*1000 ;
  double R3= 0.36;
  double w3 = (-an/ab)*sqrt(2*g)*6+(2*sqrt(h));
  double h3 = (w3*((-an/ab)*sqrt(2*g)*6+(2*sqrt(h))))/ 4; 
  double y3= (R3*R3)/(4*h3)+0.17;
  ///Serial.println(yr);
  double L3=y2-y3;
  double T3= (L3)/v;
  const unsigned long motorRunTime3 = T3*1000 ;
  double R4= 0.29;
  double w4 = (-an/ab)*sqrt(2*g)*9+(2*sqrt(h));
  double h4 = (w4*((-an/ab)*sqrt(2*g)*9+(2*sqrt(h))))/ 4;   
  double y4= (R4*R4)/(4*h4)+0.17;
  ///Serial.println(yr);
  double L4=y3-y4;
  double T4= (L4)/v;
  const unsigned long motorRunTime4 = T4*1000 ;
// Define the start time of the motor
unsigned long motorStartTime1;
unsigned long motorStartTime2;
unsigned long motorStartTime3;
unsigned long motorStartTime4;
 
void setup() {
  // Set the speed of the motor in RPM (revolutions per minute)
  motor.setSpeed(120);
  // Set the initial start time of the motor
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
  myservo.attach(6);
   Serial.begin(9600);
     Serial.println(y1);

}

void loop() {

  // Check if the motor has been running for the desired time
   motorStartTime1 = millis();
    
  while (millis() - motorStartTime1 < motorRunTime1) {
    motor.step(120);
    
  }
  myservo.write(angle1);
digitalWrite(RELAY_PIN, LOW);
delay(3000);
digitalWrite(RELAY_PIN, HIGH);
delay(1000);
motorStartTime2 = millis();
 
  
while (millis() - motorStartTime2 < motorRunTime2) {
    motor.step(120);
  }
  myservo.write(angle2);
digitalWrite(RELAY_PIN, LOW);
delay(3000);
digitalWrite(RELAY_PIN, HIGH);
delay(1000);
  
   motorStartTime3 = millis();
  myservo.write(angle3);
  while (millis() - motorStartTime3 < motorRunTime3) {
    motor.step(120);
     
  }
digitalWrite(RELAY_PIN, LOW);
delay(3000);
digitalWrite(RELAY_PIN, HIGH);
delay(1000);
motorStartTime4 = millis();
 
while (millis() - motorStartTime4 < motorRunTime4) {
    motor.step(120);
 
  }
   myservo.write(angle4);
digitalWrite(RELAY_PIN, LOW);
delay(3000);
digitalWrite(RELAY_PIN, HIGH);
delay(1000);
}
