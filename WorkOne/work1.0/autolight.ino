//自动开灯
#include <clockshow.h> 读时间
  int val;
  int movetime= 0,nowtime=11;
  int timea=0;
void autolightsetup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  nowtime = readtime();
  movetime = nowtime-11;
}
void autolight() {
  // put your main code here, to run repeatedly:
  val=analogRead(LIGHT_A);
  Serial.print("light now:");
  Serial.println(val);
  if(readtime()-movetime>5){//10分钟
   if (val>355){
     digitalWrite(LIGHT, HIGH);
     movetime = readtime();//读取当前时间
   }
   else{
     digitalWrite(LIGHT, LOW);
     movetime = readtime();//读取当前时间
    }
  }
 
}
