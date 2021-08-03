void diemThaBong() {
  TimeTemp = millis();
  while ((millis() - TimeTemp) < 500 ) {
    dung();
  }
  TimeTemp = millis();

  while ((millis() - TimeTemp) < 700 ) {
    lui();
  }
  TimeTemp = millis();
  
  while ((millis() - TimeTemp) < 500 ) {
    dung();
  }
  TimeTemp = millis();
  while ((millis() - TimeTemp) < 500 ) {
    trai();
  }
  TimeTemp = millis();
  while ((millis() - TimeTemp) < 500 ) {
    dung();
  }
  while ((millis() - TimeTemp) < 100 ) {
    tienCham();
    doc_CBT();
  }
  doc_CBT();
  while (!(GTtien[3] || GTtien[4]|| GTtien[6])) {
    tienCham();
    doc_CBT();
  }
  TimeTemp = millis();
  while ((millis() - TimeTemp) < 400 ) {
    trai();
    doc_CBT();
  }
  DK_Tien();
}
void luiVeLine() {

}
