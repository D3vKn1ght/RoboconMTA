void diemLayBong() {
  dung();
  delay(500);

  lui();
  delay(100);
  for (int i = 0; i < 4; i++) {
    doc_CBL();
    DK_Lui();
    delay(200);
  }

  dung();
  delay(500);

  trai();
  delay(1200);

  dung();
  delay(500);

  tienCham();
  delay(200);

  doc_CBT();

  tienCham();
  while (!(GTtien[3] || GTtien[4])) {
    doc_CBT();
    delay(10);
  }
  delay(200);

  trai();
  for (int i = 0; i < 5; i++) {
    doc_CBT();
    doc_CBL();
    delay(200);
  }
  for (int i = 0; i < 20; i++) {
    doc_CBT();
    doc_CBL();
    delay(10);
  }

  DK_Tien();
}
void veLine() {
  tien();
  for (int i = 0; i < 9; i++) {
    doc_CBT();
    delay(100);
    DK_Tien();
    delay(100);
  }

  dung();
  delay(500);

  phai();
  delay(3600);

  dung();
  delay(500);

  tienCham();
  for (int i = 0; i < 2; i++) {
    doc_CBT();
    delay(200);
  }
  for (int i = 0; i < 5; i++) {
    doc_CBT();
    delay(10);
  }
  while (!(GTtien[3] || GTtien[4] )) {
    doc_CBT();
    delay(10);
  }


  tienCham();
  for (int i = 0; i < 3; i++) {
    doc_CBT();
    delay(200);
  }
  for (int i = 0; i < 20; i++) {
    doc_CBT();
    delay(10);
  }

  DK_Tien();
}
