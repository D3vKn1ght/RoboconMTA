bool checkNgaBa()
{
  if ((GTtien[0] && GTtien[1]) || (GTtien[6] && GTtien[7]))
  {
    int demSoLineSang = 0;
    for (int i = 0; i <= 7; i++)
    {
      if (GTtien[i])
      {
        demSoLineSang++;
      }
    }
    if (demSoLineSang >= 4)
    {
      return true;
    }
  }
  return false;
}
bool checkNgaBaLui()
{
  if ((GTlui[0] && GTlui[1]) || (GTlui[6] && GTlui[7]))
  {
    int demSoLineSang = 0;
    for (int i = 0; i <= 7; i++)
    {
      if (GTlui[i])
      {
        demSoLineSang++;
      }
    }
    if (demSoLineSang >= 4)
    {
      return true;
    }
  }
  return false;
}
void KhoiDau()
{
  doc_CBT();
  while (!checkNgaBa()) {
    doc_CBT();
  }
  tien(70);
  delay(1000);
  dung();
  delay(1000);
  lui(80);
  delay(1500);
  dung();

  dung();
  delay(200);

  trai();
  delay(400);

  dung();
  delay(100);

  tienCham();
  delay(600);

  doc_CBT();

  tienCham();
  while (!(GTtien[3] || GTtien[4])) {
    doc_CBT();
    delay(10);
  }
  for (int i = 0; i < 10; i++) {
    doc_CBT();
    doc_CBL();
    delay(20);
  }
  trai();
  for (int i = 0; i < 3; i++) {
    doc_CBT();
    doc_CBL();
    delay(100);
  }
  for (int i = 0; i < 20; i++) {
    doc_CBT();
    doc_CBL();
    delay(10);
  }
  dung();
  delay(50);
  DK_Tien_Cham();

}
void switchRetry() {
  TimeTemp = millis();
  while (millis() - TimeTemp < timeWaitRetry)
  {
    for (int i = 0; i < 3; i++) {

      if (!digitalRead(defineLayBong[i])) {
        Serial.print("Lay Bong ");
        Serial.print(i + 1);
        Serial.print("--");
        viTriLayBong[i + 1] = true;
      }
      if (!digitalRead(defineThaBong[i])) {
        Serial.print("Tha Bong ");
        Serial.print(i + 1);
        Serial.print("--");
        viTriThaBong[i + 1] = true;
      }
    }
    Serial.print("\n");
    //      };
    //    Serial.println(digitalRead(congTacHanhTrinh));
    if (digitalRead(congTacHanhTrinh)) {
      Serial.println("Cong tac hanh trinh");
      return;
    }
    if (digitalRead(congTacNhanBong)) {
      Serial.println("Cong tac nhan bong");
    }
  }
  KhoiDau();
}
void vuotQuaChuZ()
{
  TimeTemp = millis();
  while (millis() - TimeTemp < timeZ)
  {
    doc_CBT();
    DK_Tien();
  }
}
