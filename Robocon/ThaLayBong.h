void dungNeuConBong() {
  while (true) {
    doc_CBT();
    doc_CBL();
    DK_Tien_Cham();
    if ((GTlui[2] || GTlui[3] || GTlui[4] || GTlui[5]) && (GTtien[3] || GTtien[4])) {
      delay(400);
      dung();
      delay(200);
      dem = 4;
      return;

    }
  }
}

void diemLayBong() {
  dung();
  delay(300);

  lui();
  delay(700);


  dung();
  delay(200);

  trai();
  delay(400);

  dung();
  delay(100);

  tienCham();
  delay(600);

  doc_CBT();

  tienCham();
  while (!(GTtien[3] || GTtien[4])) {
    doc_CBT();
    delay(10);
  }
  for (int i = 0; i < 10; i++) {
    doc_CBT();
    doc_CBL();
    delay(20);
  }

  trai();
  for (int i = 0; i < 3; i++) {
    doc_CBT();
    doc_CBL();
    delay(100);
  }
  for (int i = 0; i < 20; i++) {
    doc_CBT();
    doc_CBL();
    delay(10);
  }
  dung();
  delay(50);
  DK_Tien_Cham();
}
void veLine() {
  tien(100);
  delay(1000);
  while (true) {
    doc_CBT();
    doc_CBL();
    DK_Tien();
    if ((GTlui[1] || GTlui[2] || GTlui[3] || GTlui[4] || GTlui[5] || GTlui[6]) && (GTtien[3] || GTtien[4])) {
      break;
    }
  }

  dung();
  delay(200);

  phai();
  delay(1200);
  int temp = TocDoXoay;
  TocDoXoay = 150;
  while (true) {
    doc_CBT();
    phai();
    TocDoXoay = temp;
    delay(30);
    tien(100);
    delay(30);
    if (GTtien[1] || GTtien[2] || (GTtien[3] || GTtien[4] ) || GTtien[5] || GTtien[6] ) {
      break;
    }
  }
  tienCham();
  for (int i = 0; i < 20; i++) {
    doc_CBT();
    delay(10);
  }
  trai();
  for (int i = 0; i < 20; i++) {
    doc_CBT();
    delay(20);
  }

  DK_Tien();
}
