//显示中英文字符程序
 
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
 
#define LOGO16_GLCD_HEIGHT 16 //定义显示高度
#define LOGO16_GLCD_WIDTH  16 //定义显示宽度
 int i = 5;
//中文：凌  （这就是存储点阵变量，str_1可以修改成自己喜欢的名称，用函数display.drawBitmap（）调用就可以了）
static const unsigned char PROGMEM str_1[] =
{ 
0x00,0x20,0x00,0x20,0x78,0x20,0x49,0x20,0x49,0x2C,0x49,0x34,0x49,0x64,0x4B,0xA4,
0x49,0x24,0x49,0x34,0x79,0x28,0x49,0x22,0x01,0x22,0x01,0x02,0x00,0xFE,0x00,0x00

  };
 
//中文：顺
static const unsigned char PROGMEM str_2[] =
{ 
0x00,0x00,0x3F,0xFC,0x20,0x04,0x20,0x04,0x3F,0xFC,0x20,0x80,0x24,0x90,0x22,0xA0,
0x20,0x80,0x3F,0xFC,0x21,0xC0,0x22,0xA0,0x24,0x90,0x48,0x88,0x50,0x86,0x80,0x80
  };
 
//中文：实
static const unsigned char PROGMEM str_3[] =
{ 
0x01,0x20,0x01,0x10,0x71,0x10,0x51,0x7E,0x57,0x80,0x51,0x04,0x51,0x44,0x51,0xC4,
0x51,0x24,0x53,0x24,0x75,0x28,0x51,0x28,0x01,0x08,0x01,0x10,0x05,0x7E,0x02,0x00
  };
 
//中文：验
static const unsigned char PROGMEM str_4[] =
{ 
0x08,0x80,0x08,0x80,0x08,0x80,0x11,0xFE,0x11,0x02,0x32,0x04,0x34,0x20,0x50,0x20,
0x91,0x28,0x11,0x24,0x12,0x24,0x12,0x22,0x14,0x22,0x10,0x20,0x10,0xA0,0x10,0x40
  };
 
//中文：室
static const unsigned char PROGMEM str_5[] =
{ 
0x00,0x00,0x0E,0xFC,0xEA,0x08,0xAA,0x08,0xAA,0xE8,0xAA,0xA8,0xAC,0xA8,0xAA,0xA8,
0xAA,0xA8,0xAA,0xA8,0xEA,0xE8,0xAA,0xA8,0x0C,0x08,0x08,0x08,0x08,0x28,0x08,0x10
  };

  static const unsigned char PROGMEM str_6[] =
{ 
0x00,0x00,0x23,0xF0,0x10,0x90,0x82,0x94,0x52,0x92,0x24,0x92,0xE1,0x10,0x22,0x50,
0x25,0x20,0x01,0x00,0xFF,0xFE,0x05,0x40,0x09,0x20,0x31,0x18,0xC1,0x06,0x01,0x00
  };

  static const unsigned char PROGMEM str_7[] =
{ 
0x04,0x40,0x04,0x40,0x04,0x40,0xFC,0x7E,0x04,0x40,0x04,0x40,0x04,0x40,0x7C,0x7C,
0x04,0x40,0x04,0x40,0x04,0x40,0x04,0x40,0xFC,0x7E,0x04,0x40,0x04,0x40,0x04,0x40
  };

  static const unsigned char PROGMEM str_8[] =
{ 
0x00,0x00,0x0F,0xE0,0x08,0x20,0x08,0x20,0x08,0x20,0x0A,0x20,0x09,0x20,0x08,0xA0,
0x08,0xA0,0x08,0x20,0x10,0x20,0x10,0x22,0x20,0x22,0x20,0x22,0x40,0x1E,0x80,0x00
  };

  static const unsigned char PROGMEM str_9[] =
{ 
0x08,0x20,0x08,0x20,0xFF,0xFE,0x08,0x20,0x08,0x20,0x0F,0xE0,0x08,0x20,0x08,0x20,
0x0F,0xE0,0x01,0x00,0xFF,0xFE,0x05,0x40,0x09,0x20,0x31,0x18,0xC1,0x06,0x01,0x00
  };
  
#if (SSD1306_LCDHEIGHT != 32)//64
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
 
void setup()   {                
  Serial.begin(9600);
 
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  
  display.clearDisplay();
 /*
  //英文字符显示
  display.setTextSize(1);             //设置字体大小
  display.setTextColor(WHITE);        //设置字体颜色白色
  display.setCursor(0,0);             //设置字体的起始位置
  display.println("Hello, world!");   //输出字符并换行
  
  display.setTextColor(BLACK, WHITE); //设置字体黑色，字体背景白色 
  display.println(3.141592);          //输出数字并换行
  
  display.setTextSize(2);             //设置字体大小
  display.setTextColor(WHITE);        //设置字体白色
  display.print("0x");                //输出字符
  display.println(0xDEADBEEF, HEX);   //输出为ASCII编码的十六进制
  //display.display();                  //显示以上
  */
  //中文字符显示
  display.drawBitmap(15,0, str_1, 16, 16, 1); //在坐标X:26  Y:16的位置显示中文字符凌
  display.drawBitmap(55,0,str_2, 16, 16, 1); //在坐标X:42  Y:16的位置显示中文字符顺
  display.drawBitmap(95,0, str_3, 16, 16, 1);
  //display.drawBitmap(75+i,0, str_4, 16, 16, 1);
  //display.drawBitmap(100+i,0, str_5, 16, 16, 1);
  display.drawBitmap(15,16,str_6, 16, 16, 1); //在坐标X:42  Y:16的位置显示中文字符顺
  display.drawBitmap(55,16, str_7, 16, 16, 1);
  display.drawBitmap(95,16, str_8, 16, 16, 1);
  //display.drawBitmap(100,16, str_9, 16, 16, 1);
  display.display();                  //把缓存的都显示
}
 
void loop() {
 
}

/*
* 16X16点阵显示 取模方式 阴码+逐行式+顺向
**/
/*
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//#define OLED_RESET 4
//Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
int r,xo,yo,a,z;//动画变量不能用char型变量无法计算
int sec;//动画变量不能用char型变量无法计算
void setup()   {                
  Serial.begin(115200);
  delay(500);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64) 
}

void loop() {
     
    sec++;
   if(sec==60)sec=0; 
  //1.检测全屏显示(看看有没有大面积坏点)
  display.fillScreen(WHITE);//检测全屏显示(看看有没有大面积坏点)
  display.clearDisplay();   // clears the screen and buffer

//14.显示数字变量 
  display.setTextSize(3);//设置字体大小  
  display.setTextColor(WHITE);//设置字体不反白
  display.setCursor(0,20);// 列127  行63    坐标
  display.println(sec/10);
  display.setCursor(22,20);//  列127  行63    坐标
  display.println(sec%10);
    //6.画空心圆
display.drawCircle(xo,yo,25,WHITE);//(控制圆心位置列0/127   控制圆心位置行0/63  )(控制大小=0+x ) 
  
  //不能用char型变量无法计算
  r=16;//指针半径
  xo=70;//圆心坐标
  yo=28;//圆心坐标
// a=6;//圆角度 
  z=180;//圆 
  a=sec*6;//圆角度
  //3. 画线 从(0,0)到(50,50
  if(sec==0 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==1 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==2 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==3 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==4 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==5 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==6 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==7 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==8 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==9 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
   
  if(sec==10 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==11 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==12 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==13 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==14 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==15 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==16 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==17 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==18 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==19 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  
  if(sec==20 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==21 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==22 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==23 ){ ;display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==24 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==25 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==26 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==27 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==28 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00   
  if(sec==29 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  
  if(sec==30 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==31 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==32 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==33 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==34 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==35 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==36 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==37 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==38 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00   
  if(sec==39 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  
  if(sec==40 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==41 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==42 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==43 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==44 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==45 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==46 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==47 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==48 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00   
  if(sec==49 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  
  if(sec==50 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==51 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==52 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==53 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==54 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==55 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==56 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==57 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==58 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  if(sec==59 ){ display.drawLine((xo+(r*cos(a*3.14/z))),(yo+(r*sin(a*3.14/z))),xo,yo, WHITE);}//(开始列127  开始行63)( 结束列127 结束行63) /////00 
  
   //13.显示英文
  display.setTextSize(1);//设置字体大小
  display.setTextColor(WHITE);//设置字体不反白
  display.setCursor(xo-5,yo-22);//列127 行63     坐标
  display.println("12");
  display.setCursor(xo+18,yo-5);//列127 行63     坐标
  display.println("3");
  display.setCursor(xo-2,yo+15);//列127 行63     坐标
  display.println("6");
  display.setCursor(xo-22,yo-5);//列127 行63     坐标
  display.println("9");
  
  display.display();
  //delay(2000);

    
}  */

