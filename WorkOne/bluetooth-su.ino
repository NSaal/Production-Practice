/*
 Name:    Bluetooth.ino
 Created: 2016/7/30 13:26:47
 Author:  Fing
*/
#include <SoftwareSerial.h>
//使用软件串口，能讲数字口模拟成串口
SoftwareSerial BT(2, 3);  //新建对象，接收脚为8，发送脚为9
char val;  //存储接收的变量
char inval;
int i=0;
void setup() {
  Serial.begin(9600);   //与电脑的串口连接
  Serial.println("BT is ready!");
  BT.begin(9600);  //设置波特率
}

void loop() {
  //如果串口接收到数据，就输出到蓝牙串口
  if (Serial.available()) {
    val =(char) Serial.read();
    BT.print(val);
  }

  //如果接收到蓝牙模块的数据，输出到屏幕

  if (BT.available()) {
    inval = (char)BT.read();
    Serial.print(inval);
    i++;
    if(i==1){
      Serial.println();
      i=0;
    }
  }
}  
