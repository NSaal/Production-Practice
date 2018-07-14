

float cm; //距离变量
float temp; //
float dist[10], distt[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int reset = 0;
int disttu = 0, disttd = 0;
int signall = 0;
int numberofp = 0;
void echosetup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
}
/*int judge() {
  for (int h = 0; h < 9; h++)  {
    if (dist[h]>10&&dist[h] < 50) {
      distt[h] = dist[h + 1] - dist[h];
      if (distt[h] < 0)
        disttu++;
      else
        disttd++;
    }
  }
  //Serial.println(disttu-disttd);
  if (disttu - disttd > 3)
    return 1;//有人靠近
  else if (disttu - disttd < -3)
    return -1;//有人远离
  else
    return 0;
}*/
int numberofpeople() {

}
void echo() {
  reset++;
  //给Trig发送一个低高低的短时间脉冲,触发测距
  digitalWrite(Trig, LOW); //给Trig发送一个低电平
  delayMicroseconds(2);    //等待 2微妙
  digitalWrite(Trig, HIGH); //给Trig发送一个高电平
  delayMicroseconds(10);    //等待 10微妙
  digitalWrite(Trig, LOW); //给Trig发送一个低电平
  temp = float(pulseIn(Echo, HIGH)); //存储回波等待时间,
  cm = (temp * 17 ) / 1000; //把回波时间换算成cm
  dist[reset] = cm;
  Serial.print("Echo =");
  Serial.print(temp);//串口输出等待时间的原始数据
  Serial.print(" | | Distance = ");
  Serial.print(cm);//串口输出距离换算成cm的结果
  Serial.println("cm");
  if (reset == 10) {
    Serial.println(judge());
    for (int i = 0; i < 9; i++)
      distt[i] = 0;
      disttu=0; disttd=0;
    reset = 0;
  }
}
