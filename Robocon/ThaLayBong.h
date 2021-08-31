void diemLayBong() {
  dung();
  delay(500);

  lui();
  delay(100);
  for (int i = 0; i < 3; i++) {
    doc_CBL();
    DK_Lui();
    delay(200);
  }

  dung();
  delay(500);

  trai();
  delay(700);

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
  for (int i = 0; i < 29; i++) {
    doc_CBT();
    doc_CBL();
    delay(20);
  }


  trai();
  for (int i = 0; i < 5; i++) {
    doc_CBT();
    doc_CBL();
    delay(200);
  }
  for (int i = 0; i < 30; i++) {
    doc_CBT();
    doc_CBL();
    delay(10);
  }

  DK_Tien();
}
void veLine() {
  tienCham();
  delay(400);

  doc_CBT();
  tien();
  for (int i = 0; i < 6; i++) {
    doc_CBT();
    delay(100);
    DK_Tien();
    delay(100);
  }

  dung();
  delay(500);

  phai();
  delay(3050);

  dung();
  delay(500);

  tienCham();
  delay(500);
  for (int i = 0; i < 50; i++) {
    doc_CBT();
    delay(10);
  }
  while (!(GTtien[3] || GTtien[4] )) {
    doc_CBT();
    delay(10);
  }


  trai();
  for (int i = 0; i < 70; i++) {
    doc_CBT();
    delay(10);
  }

  DK_Tien();
}
