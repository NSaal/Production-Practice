float cm; //距离变量
float temp;
float dist[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int posi = 0;
int delaying = 0;
int numberofpeople = 0;
int stat = 0;
int tempb = 0;
void echosetup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}
int peoplemove() {
  int var;
  for (int i = posi; i < 10; i++) {
    if (i == 0) {
      var = dist[0] - dist[9];
    }
    else {
      var = dist[i] - dist[i - 1];
    }
    //Serial.println(var);
    if (tempb < 10) {
      tempb++;
      return 0;
    }
    if (var > 9 && delaying == 0) {
      numberofpeople--;
      return -1;
    }
    if (var < -9 && delaying == 0) {
      numberofpeople++;
      return 1;
    }
  }
  return 0;
}
int echo() {
  //给Trig发送一个低高低的短时间脉冲,触发测距
  digitalWrite(TRIG, LOW); //给Trig发送一个低电平
  delayMicroseconds(2);    //等待 2微妙
  digitalWrite(TRIG, HIGH); //给Trig发送一个高电平
  delayMicroseconds(10);    //等待 10微妙
  digitalWrite(TRIG, LOW); //给Trig发送一个低电平
  temp = float(pulseIn(ECHO, HIGH)); //存储回波等待时间,
  cm = (temp * 17 ) / 1000; //把回波时间换算成cm
  if (posi != 10) {
    dist[posi] = cm;
    posi++;
  }
  else {
    posi = 0;
    dist[posi] = cm;
    posi++;
  }
  if (delaying != 0 || stat != 0) {
    delaying++;
    if (delaying > 3) {
      delaying = 0;
    }
  }
  stat = peoplemove();
  Serial.print("Echo =");
  Serial.print(temp);//串口输出等待时间的原始数据
  Serial.print(" | | Distance = ");
  Serial.print(cm);//串口输出距离换算成cm的结果
  Serial.println("cm");
  Serial.print("IN OR OUT:");
  Serial.println(stat);
  Serial.print("people in:");
  Serial.println(numberofpeople);
  return numberofpeople;

}
