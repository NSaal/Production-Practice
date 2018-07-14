//自动开灯
#define LIGHT_A 3
#define LIGHT_D 11
#define LIGHT 13
//#include xxxx 读时间
  int val;
  int movetime= 0,nowtime=11;
  int timea=0;
  int readtime(){
    timea++;
    return timea;
  }
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  nowtime = readtime();
  movetime = nowtime-11;
}

void loop() {
  // put your main code here, to run repeatedly:
  val=analogRead(LIGHT_A);
  Serial.print("a:");
  Serial.print(val);
  //Serial.print(", d:");
  //val=digitalRead(LIGHT_D);
  //Serial.println(val);
  if(readtime()-movetime>10){//10分钟
   if (val>255){
     digitalWrite(LIGHT, HIGH);
     movetime = readtime();//读取当前时间
   }
   else{
     digitalWrite(LIGHT, LOW);
     movetime = readtime();//读取当前时间
    }
  }
  delay(1000);
}
