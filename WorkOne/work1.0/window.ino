#include <Servo.h>;
Servo myservo;
int lightness;
int d = 0;
void windowsetup() {
  Serial.begin(9600);//设置波特率为9600，这里要跟软件设置相一致。
  myservo.attach(9);
  myservo.write(0);
}
void window() {
  //Serial.println(d);
  lightness = analogRead(LIGHT_A);
  if (d == 0 && lightness < 355)
    myservo.write(d = d + 180);
  else if (lightness > 355 && d == 180)
    myservo.write(d = d - 180);
}
