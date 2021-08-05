void diemLayBong() {
  dung();
  delay(500);

  lui();
  delay(900);

  dung();
  delay(500);

  trai();
  delay(600);

  dung();
  delay(500);

  TimeTemp = millis();
  tienCham();
  while ((millis() - TimeTemp) < 150 ) {
    doc_CBT();
  }

  while (!(GTtien[3] || GTtien[4] || GTtien[6])) {
    tienCham();
    doc_CBT();
    doc_CBL();
  }

  TimeTemp = millis();
  trai();
  while ((millis() - TimeTemp) < 400 ) {
    doc_CBT();
    doc_CBL();
  }

  DK_Tien();
}
void veLine() {
  TimeTemp = millis();
  tien();
  while ((millis() - TimeTemp) < 500 ) {
    doc_CBT();
    doc_CBL();
  }

  dung();
  delay(500);

  TimeTemp = millis();
  phai();
  while ((millis() - TimeTemp) < 900 ) {
    doc_CBT();
    doc_CBL();
  }

  dung();
  delay(500);

  TimeTemp = millis();
  tienCham();
  while ((millis() - TimeTemp) < 100 ) {
    doc_CBT();
  }

  tienCham();
  while (!(GTtien[3] || GTtien[4] || GTtien[6] || GTtien[1])) {
    doc_CBT();
    doc_CBL();
  }

  TimeTemp = millis();
  phai();
  while ((millis() - TimeTemp) < 400 ) {
    doc_CBT();
    doc_CBL();
  }
  DK_Tien();
}
