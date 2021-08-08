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
  delay(200);
  doc_CBT();
  doc_CBL();
  delay(200);
  doc_CBT();
  doc_CBL();
  delay(200);
  doc_CBT();
  doc_CBL();
  delay(200);
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
  delay(200);
  doc_CBT();
  delay(200);
  doc_CBT();
  delay(100);
  doc_CBT();

  dung();
  delay(500);

  phai();
  delay(200);
  doc_CBT();
  delay(200);
  doc_CBT();
  delay(200);
  doc_CBT();
  delay(200);
  doc_CBT();

  dung();
  delay(500);

  tienCham();
  delay(50);
  TimeTemp = millis();
  while ((millis() - TimeTemp) < 150 ) {
    doc_CBT();
  }

  tienCham();
  while (!(GTtien[3] || GTtien[4] )) {
    doc_CBT();
  }



  phai();
  delay(200);
  doc_CBT();
  delay(200);
  doc_CBT();
  TimeTemp = millis();
  while ((millis() - TimeTemp) < 200 ) {
    doc_CBT();
  }


  DK_Tien();
}
