void checkSan() {
  if (IsSanTrai) {
    lostLineLeft = - 4;
    lostLineRight = 4;
  }
  else {
    lostLineLeft = 4;
    lostLineRight = -4;
  }
}
void calPosReverse() {
  for ( int i = 3; i >= 1; i--) {
    if (viTriThaBong[i] == true) {
      ViTriDaoNguoc = i;
      return;
    }
  }
}
bool checkNgaBaTien()
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
bool checkNgaBaTrai()
{
  if ((GTTrai[0] && GTTrai[1]) || (GTTrai[6] && GTTrai[7]))
  {
    int demSoLineSang = 0;
    for (int i = 0; i <= 7; i++)
    {
      if (GTTrai[i])
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
bool checkNgaBaPhai()
{
  if ((GTPhai[0] && GTPhai[1]) || (GTPhai[6] && GTPhai[7]))
  {
    int demSoLineSang = 0;
    for (int i = 0; i <= 7; i++)
    {
      if (GTPhai[i])
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
  while (!checkNgaBaTien()) {
    doc_CBT();
  }
  tien(TocDoCham);
  delay(500);
  TimeTemp = millis();
  while (millis() - TimeTemp < 600)
  {
    doc_CBT();
    xoayTrai(TocDoXoayCham);
  }
  doc_CBT();
  int temp = Errort;
  bool over = false;
  while (true) {
    temp = Errort;
    doc_CBT();
    xoayTrai(TocDoXoayCham);
    //check quay vuot line chinh
    if (over == false) {
      if (Errort >= temp) {
        continue;
      }
      else {
        over = true;
        //        delay(50);
      }
    }
    //cham line moi
    else {
      if (GTtien[2] || GTtien[3] || GTtien[4] || GTtien[5]) {
        break;
      }
    }
  }
  DK_Tien(TocDo);

}
void switchRetry() {
  TimeTemp = millis();
  while (millis() - TimeTemp < timeWaitRetry)
  {
    for (int i = 0; i < 3; i++) {

      if (!digitalRead(defineLayBong[i])) {
//        Serial.print("Lay Bong ");
//        Serial.print(i + 1);
//        Serial.print("--");
        viTriLayBong[i + 1] = true;
      }
      if (!digitalRead(defineThaBong[i])) {
//        Serial.print("Tha Bong ");
//        Serial.print(i + 1);
//        Serial.print("--");
        viTriThaBong[i + 1] = true;
      }
    }
    for (int i = 0; i < 4; i++) {
      if (!digitalRead(defineGatBong[i])) {
//        Serial.print("Gat Bong ");
//        Serial.print(i + 1);
//        Serial.print("--");
        viTriGatBong[i + 1] = true;
      }
      if (!digitalRead(defineThaBongDoiBan[i])) {
//        Serial.print("Tha Bong Doi Ban  ");
//        Serial.print(i + 1);
//        Serial.print("--");
        viTriThaBongDoiBan[i + 1] = true;
      }
    }
    if (!digitalRead(DaoNguoc)) {
      rev = REV_CHUA;
//      Serial.print("\nDao nguoc");
    }
    if (viTriThaBongDoiBan[4] == true) {
      viTriThaBongDoiBan[5] = true;
      viTriThaBongDoiBan[4] = false;
    }
    if (viTriGatBong[4] == true) {
      viTriGatBong[5] = true;
      viTriGatBong[4] = false;
    }
//    Serial.print("\n");
    if (digitalRead(congTacHanhTrinh)) {
//      Serial.println("Cong tac hanh trinh");
      return;
    }
//    if (digitalRead(congTacNhanBong)) {
//      Serial.println("Cong tac nhan bong");
//    }
  }
  KhoiDau();
}
void vuotQuaChuZ()
{
  TimeTemp = millis();
  while (millis() - TimeTemp < timeZ)
  {
    doc_CBT();
    DK_Tien(TocDo);
  }
}
