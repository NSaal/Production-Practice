//数字端
#define TRIG 4 //超声波引脚Trig 连接 IO D2
#define ECHO 5 //超声波引脚Echo 连接 IO D3 
#define Steering gear
#define INTRUSION_SENSOR 10//红外传感器
#define LIGHT_D 11//光感数字输入端
#define LIGHT 13//LED
//模拟端
#define LIGHT_A 3 //光感模拟输入端
#define OLED_RESET 4
#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3);  //新建对象，接收脚为2，发送脚为3
#include <autolight.h>
#include <clockshow.h>
#include <intrusion.h>
#include <echo.h>
//#include <inandout.c>
//#include <phone.c>
//#include <window.c>

void setup() {
  // put your setup code here, to run once:
  BT.begin(9600);  //设置波特率
  autolightsetup();
  clockshowsetup();
  echosetup();
  windowsetup();
}
void loop() {
  // put your main code here, to run repeatedly:
  autolight();//智能灯
  delay(400);
  clockshow();//电子表
  if (echo()) {//人员进出
    digitalWrite(LIGHT, LOW);
  }
  intrusion();//防盗
  window();//关窗
  //phone();
}
