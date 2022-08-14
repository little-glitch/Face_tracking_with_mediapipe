#include<Servo.h>
Servo Myservo;
int pos = 90;
String data;
float data_1 = 0.5;

void setup() {
  Serial.begin(9600);
  Myservo.attach(12);
  pinMode(LED_BUILTIN, OUTPUT);
  Myservo.write(pos);

  

}
void loop() {
  if (Serial.available() > 0) {
    data = Serial.readStringUntil('\n');
    //Serial.print("hello world ");
    Serial.println(data);
    data_1 = data.toFloat();
  }

  if (data_1 < 0.4) { 
     if (pos < 180 && pos > 0){
       pos+=1;
     }
     if (pos == 180){ 
       pos = 178; 
     }
     Myservo.write(pos);
   }
  else if(data_1 > 0.6) {
     if (pos < 180 && pos > 0){
      pos-=1;
     }
     if (pos == 0){
      pos = 2; 
     }
     Myservo.write(pos);
  }

   // pos = map(data_1 * 100, 0, 100, 0, 180);
    delay(75);

}
