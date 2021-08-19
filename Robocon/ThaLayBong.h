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
  delay(800);

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
  for (int i = 0; i < 25; i++) {
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
  for (int i = 0; i < 20; i++) {
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
  for (int i = 0; i < 8; i++) {
    doc_CBT();
    delay(100);
    DK_Tien();
    delay(100);
  }

  dung();
  delay(500);

  phai();
  delay(3200);

  dung();
  delay(500);

  tienCham();
  delay(1900);
  for (int i = 0; i < 50; i++) {
    doc_CBT();
    delay(10);
  }
  while (!(GTtien[3] || GTtien[4] )) {
    doc_CBT();
    delay(10);
  }


  trai();
  for (int i = 0; i < 33; i++) {
    doc_CBT();
    delay(10);
  }

  DK_Tien();
}
