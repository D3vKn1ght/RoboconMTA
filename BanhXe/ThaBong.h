void ThaBong() {
  delay(2000);
  while ((millis() - TimeTemp) < 700 ) {
    lui();
    doc_CBT();
    doc_CBL();
  }
}
