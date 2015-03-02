#include <AcceleroMMA7361.h>
#include <Servo.h> 

AcceleroMMA7361 accelero;
Servo myservo; 

int x = 0,
 xMap = 0;

void setup()
{
 Serial.begin(9600);
 accelero.begin(13, 12, 11, 10, A0, A1, A2);
 accelero.setARefVoltage(5); //sets the AREF voltage to 3.3V
 accelero.setSensitivity(LOW); //sets the sensitivity to +/-6G
 accelero.calibrate();
 
 myservo.attach(9); 
}
void loop()
{
 x = accelero.getXAccel();

 //Serial.print("\nx: ");
 //Serial.print(x);
 
 xMap = map(x, -200, 200, 0, 180); //map(x, -300, 300, 0, 180);
 xMap = constrain(xMap, 0, 180); 
 Serial.print(xMap);
 Serial.println();
  
 myservo.write(xMap);
 delay(100); //make it readable
}
