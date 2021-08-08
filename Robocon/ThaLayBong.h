void diemLayBong() {
  dung();
  delay(500);

  lui();
  delay(900);

  dung();
  delay(500);

  trai();
  delay(1200);

  dung();
  delay(500);

  tienCham();
  delay(150);
  TimeTemp = millis();
  while ((millis() - TimeTemp) < 50 ) {
    doc_CBT();
  }

  while (!(GTtien[3] || GTtien[4])) {
    tienCham();
    doc_CBT();
  }
  tienCham();
  delay(200);

  trai();
  for (int i = 0; i < 4; i++) {
    doc_CBT();
    doc_CBL();
    delay(200);
  }
  doc_CBT();
  doc_CBL();
  TimeTemp = millis();
  while ((millis() - TimeTemp) < 200 ) {
    doc_CBT();
    doc_CBL();
  }


  DK_Tien();
}
void veLine() {
  TimeTemp = millis();
  tien();
  for (int i = 0; i < 9; i++) {
    doc_CBT();
    delay(200);
  }


  dung();
  delay(500);

  phai();
  for (int i = 0; i < 18; i++) {
    doc_CBT();
    delay(200);
  }



  dung();
  delay(500);

  tienCham();
  for (int i = 0; i < 2; i++) {
    doc_CBT();
    delay(200);
  }
  TimeTemp = millis();
  while ((millis() - TimeTemp) < 50 ) {
    doc_CBT();
  }
  while (!(GTtien[3] || GTtien[4] )) {
    doc_CBT();
  }



  //  phai();
  // for (int i = 0; i < 2; i++) {
  //    doc_CBT();
  //    delay(200);
  //  }



  tienCham();
  for (int i = 0; i < 3; i++) {
    doc_CBT();
    delay(200);
  }
  TimeTemp = millis();
  while ((millis() - TimeTemp) < 200 ) {
    doc_CBT();
  }


  DK_Tien();
}
