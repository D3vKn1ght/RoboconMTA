void ThaBong() {
  delay(500);
  gServo2.write(135);
  delay(500);
  gServo1.write(230);
  delay(1000);
  gServo1.write(135);
  gServo2.write(230);
  //
  //  //      gServo1.write(135);
  //  delay(1000);
  //  gServo2.write(135);
  //  delay(1000);
  //  soBong--;
  //  if (soBong < 0) {
  //    soBong = 0;
  //  }
  //  delay(2000);
}

void ThaBong4() {
  lui(80);
  delay(100);
  int temp = TocDoXoay;
  TocDoXoay = 150;
  dung();
  delay(500);
  trai();
  delay(500);

  doc_CBT();

  while (GTtien[3] == 0 || GTtien[4] == 0) {
    doc_CBT();
    doc_CBL();
    trai();
    delay(10);
  }

  TimeTemp = millis();
  doc_CBL();
  while ((GTlui[3] == 0 || GTlui[4] == 0 ) || checkNgaBaLui() == 1) {
    DK_Tien_Cham();
    //    tien(80);
    doc_CBT();
    doc_CBL();
    if (millis() - TimeTemp < 4000) {
      break;
    }
  }
  for ( int i = 0; i < 40; i++) {
    doc_CBT();
    DK_Tien_Cham();
    delay(50);
    int demSoLineSang = 0;
    for (int i = 0; i <= 7; i++)
    {
      if (GTtien[i])
      {
        demSoLineSang++;
      }
    }
    if (demSoLineSang == 0) {
      break;
    }
  }

  //  dung();
  //  delay(1000);
  while (!digitalRead(congTacHanhTrinh)) {
    doc_CBL();
    if (checkNgaBaLui()) {
      Errorl = 0;
    }
    DK_Lui(60);
  }
  dung();
  TocDoXoay = temp;
  ThaBong();
  return;
}
