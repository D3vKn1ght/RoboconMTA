
void doc_CBT()
{
  Tien[0]  = analogRead(camBienTien1);
  Tien[1]  = analogRead(camBienTien2);
  Tien[2]  = analogRead(camBienTien3);
  Tien[3]  = analogRead(camBienTien4);
  Tien[4]  = analogRead(camBienTien5);
  Tien[5]  = analogRead(camBienTien6);
  Tien[6]  = analogRead(camBienTien7);
  Tien[7]  = analogRead(camBienTien8);

  for (it = 0; it <= 7; it++)
  {
    if (Tien[it] > tb)
    {
      GTtien[it] = 0;
    }
    else
    {
      GTtien[it] = 1;
    }
  }
  if (GTtien[3] == 1 || GTtien[4] == 1)
  {
    Errort = 0;
  }
  else if (GTtien[2] == 1)
  {
    Errort = 1;
  }
  else if (GTtien[5] == 1)
  {
    Errort = -1;
  }
  else if (GTtien[1] == 1)
  {
    Errort = 2;
  }
  else if (GTtien[6] == 1)
  {
    Errort = -2;
  }
  else if (GTtien[0] == 1)
  {
    Errort = 3;
  }
  else if (GTtien[7] == 1)
  {
    Errort = -3;
  }
  //  Serial.println(Errort);
  //  Serial.print("\t");
  Pt = Errort;
  It = It + previous_It;
  Dt = Errort - previous_Errort;

  PID_value_Tien = (Kp * Pt) + (Ki * It) + (Kd * Dt);
  previous_Errort = Errort;
}

void DK_Tien()
{
  SetTocDo = 110;
  LSpeed = SetTocDo  + PID_value_Tien;
  RSpeed = SetTocDo - PID_value_Tien;
  LSpeed = constrain(LSpeed, 0, 255);
  RSpeed = constrain(RSpeed, 0, 255);

  tien();

  //  Serial.println();
  //  Serial.print(PID_value_Tien);
  //  Serial.print("\t\t");
  //  Serial.print("\t");
  //  Serial.print(LSpeed);
  //
  //  Serial.print("\t");
  //  Serial.print(RSpeed);
  //  Serial.print("\n");

}
void DK_Tien_Cham()
{
  SetTocDo = 90;
  LSpeed = SetTocDo  + PID_value_Tien;
  RSpeed = SetTocDo - PID_value_Tien;
  LSpeed = constrain(LSpeed, 0, 255);
  RSpeed = constrain(RSpeed, 0, 255);

  tien();

  //  Serial.println();
  //  Serial.print(PID_value_Tien);
  //  Serial.print("\t\t");
  //  Serial.print("\t");
  //  Serial.print(LSpeed);
  //
  //  Serial.print("\t");
  //  Serial.print(RSpeed);
  //  Serial.print("\n");

}
