#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>
Adafruit_SSD1306 display(OLED_RESET);
#define LOGO16_GLCD_HEIGHT 64 //定义显示高度
#define LOGO16_GLCD_WIDTH  128 //定义显示宽度
#if (SSD1306_LCDHEIGHT != 32)//64
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

int inval;
int tt = 0;
int i;
int j = 0;
int t1, t2, t3, t4;
void number(int i) {
  switch (i)  {
    case (0):            //设置字体大小
      display.print(0);//设置字体颜色白色
      break;
    case 1:              //设置字体大小
      display.print(1);
      break;
    case 2:              //设置字体大小
      display.print(2);
      break;
    case 3:              //设置字体大小
      display.print(3);
      break;
    case 4:          //设置字体大小
      display.print(4);
      break;
    case 5:             //设置字体大小
      display.print(5);
      break;
    case 6:            //设置字体大小
      display.print(6);
      break;
    case 7:          //设置字体大小
      display.print(7);
      break;
    case 8:         //设置字体大小
      display.print(8);
      break;
    case 9:           //设置字体大小
      display.print(9);
      break;
  }
}
void coursor(int m, int i) {
  switch (m)  {
    case 1: display.setCursor(20, 8); number(i); break;
    case 2: display.setCursor(40, 8); number(i); break;
    case 3: display.setCursor(80, 8); number(i) ; break;
    case 4: display.setCursor(100, 8); number(i) ; break;
  }
}
int readtime(){
  return t4+10*t3;
}
void clockshowsetup()   {
  Serial.begin(9600);   //与电脑的串口连接
  Serial.println("BT is ready!");

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.setTextSize(3);             //设置字体大小
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.display();
  //显示以上
}
void clockshow() {
  //如果接收到蓝牙模块的数据，输出到屏幕
  display.clearDisplay();
  if (BT.available()) {
    if (inval = BT.parseInt()) {
      tt = 0;
    }
    Serial.println(inval);
    t1 = (int)inval / 1000;
    t2 = (int)(inval - 1000 * t1) / 100;
    t3 = (int)(inval - 1000 * t1 - 100 * t2) / 10;
    t4 = (int)inval - t1 * 1000 - t2 * 100 - t3 * 10;
    Serial.println(t1);
    Serial.println(t2);
    Serial.println(t3);
    Serial.println(t4);
  }
  display.setCursor(58, -2);  display.print(".");
  display.setCursor(58, 6);  display.print(".");
  coursor(1, t1);  coursor(2, t2);  coursor(3, t3);  coursor(4, t4);
  if (tt == 60) {
    tt=0;
    if (t4 == 9) {
      t4 = 0;
      t3++;
      display.clearDisplay();
      coursor(1, t1);  coursor(2, t2);  coursor(3, t3);  coursor(4, t4);
      if (t3 == 6) {
        t3 = 0;
        t2++;
        display.clearDisplay();
        coursor(1, t1);  coursor(2, t2);  coursor(3, t3);  coursor(4, t4);
        if (t2 == 9) {
          t2 = 0;
          t1++;
          display.clearDisplay();
          coursor(1, t1);  coursor(2, t2);  coursor(3, t3);  coursor(4, t4);
        }
      }
    }
    else if (t1 == 2 && t2 == 4 && t3 == 5 && t4 == 9)
    {
      t1 = 0; t2 = 0; t3 = 0; t4 = 0;
      display.clearDisplay();
      coursor(1, t1);  coursor(2, t2);  coursor(3, t3);  coursor(4, t4);
    }
    else
    {
      t4++;
      display.clearDisplay();
      coursor(1, t1);  coursor(2, t2);  coursor(3, t3);  coursor(4, t4);
    }
    //设置字体的起始位置
  }
  tt++;
  Serial.print("second:");
  Serial.println(tt);
  display.display();                  //显示以上
}
