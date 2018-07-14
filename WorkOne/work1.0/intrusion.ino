//入侵检测 红外传感器
void intrusionsetup() {
  // put your setup code here, to run once:
  pinMode(INTRUSION_SENSOR, INPUT);
  Serial.begin(9600);
}
void intrusion() {
  // put your main code here, to run repeatedly:
  int x = digitalRead(INTRUSION_SENSOR);
  Serial.println(x);
  if(!x)
    BT.print("alert!");
}
