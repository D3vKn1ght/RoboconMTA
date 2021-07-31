
void doc_CBL()
{

  SetTocDo = 80;
  LSpeed = SetTocDo;
  RSpeed = SetTocDo;
  SSLui[0]  = analogRead(camBienLui1);
  SSLui[1]  = analogRead(camBienLui2);
  SSLui[2]  = analogRead(camBienLui3);
  SSLui[3]  = analogRead(camBienLui4);
  SSLui[4]  = analogRead(camBienLui5);
  SSLui[5]  = analogRead(camBienLui6);
  SSLui[6]  = analogRead(camBienLui7);
  SSLui[7]  = analogRead(camBienLui8);

  for (iLui = 0; iLui <= 7; iLui++)
  {
    if (SSLui[iLui] < tb)
    {
      GTlui[iLui] = 0;
    }
    else
    {
      GTlui[iLui] = 1;

    }
  }
  if (GTlui[3] == 1 || GTlui[4] == 1)
  {
    Errorl = 0;
  }
  else if (GTlui[2] == 1)
  {
    Errorl = 1;
  }
  else if (GTlui[5] == 1)
  {
    Errorl = -1;
  }
  else if (GTlui[1] == 1)
  {
    Errorl = 2;
  }
  else if (GTlui[6] == 1)
  {
    Errorl = -2;
  }
  else if (GTlui[0] == 1)
  {
    Errorl = 3;
  }
  else if (GTlui[7] == 1)
  {
    Errorl = -3;
  }
  Pl = Errorl;
  Il = Il + previous_Il;
  Dl = Errorl - previous_Errorl;

  PID_value_Lui = (Kp2 * Pl) + (Ki2 * Il) + (Kd2 * Dl);
  previous_Errorl = Errorl;
}

void DK_Lui()
{
  dung();
  LSpeed = SetTocDo  - PID_value_Tien;
  RSpeed = SetTocDo + PID_value_Tien;
  LSpeed = constrain(LSpeed, 0, 255);
  RSpeed = constrain(RSpeed, 0, 255);

  LSpeed = constrain(LSpeed, 25, 255);
  RSpeed = constrain(RSpeed, 25, 255);

  lui();
  //  Serial.println();
  //  Serial.print(PID_value_Lui);
  //  Serial.print("\t\t");
  //  Serial.print("\t");
  //  Serial.print(LSpeed);
  //
  //  Serial.print("\t");
  //  Serial.print(RSpeed);
  //  Serial.print("\n");
}
