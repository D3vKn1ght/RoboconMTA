void CanChinhGatBong() {
  bool tempSan = IsSanTrai;
  IsSanTrai = true;
  if (!digitalRead(camBienGatBong)) {
    while (digitalRead(camBienGatBong)) {
      xoayPhaiTren(TocDoCham);
    }
  }
  else {
    while (!digitalRead(camBienGatBong)) {
      xoayTraiTren(TocDoCham);
    }
  }
  dung();
  IsSanTrai = tempSan;
}
void HaTayGat(int goc, int timeDelay) {

  digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < goc; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  //  delay(timeDelay);
}

void NangTayGat(int goc, int timeDelay) {
  digitalWrite(dirPin, LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for (int x = 0; x < goc; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  //  delay(timeDelay);
}
void GatBongCaHai() {
  gServo4.write(5);
  delay(1000);
  for (int i = 10 ; i < 135 ; i ++) {
    gServo5.write(i);
    delay(15);
//    gServo5.write(i-5);
//    delay(15);
  }
  //  delay(700);
  gServo4.write(100);
  delay(1000);
  gServo5.write(10);
  //  delay(2000);
}
void GatBongDoiBan() {
  if (!viTriGatBong[iViTri  % 6]) {
    return;
  }
  HaTayGat(2335, 6000); // góc và timeDelay
  delay(700);
  //  CanChinhGatBong();
  delay(200);
  GatBongCaHai();
  delay(1000);
  NangTayGat(2335, 6000);  // góc và timeDelay

}
void ThaBong() {
  delay(500);
  gServo2.write(135);
  delay(500);
  gServo1.write(240);
  delay(1200);
  gServo1.write(135);
  delay(500);
  gServo2.write(240);

}
void ThaBongDoiBan() {
  if (!viTriThaBongDoiBan[iViTri  % 6]) {
    return;
  }
  gServo3.write(175);
  delay(1000);
  ThaBong();
  delay(1300);
  gServo3.write(10);
  delay(200);
}
