void LayBong() {
  TimeTemp = millis();
  while (millis() - TimeTemp < timeWaitGetBall) {
    if (digitalRead(congTacNhanBong)) {
      delay(2000);
      break;
    }
  }

//  gServo1.write(135);
//  delay(3000);
//  gServo2.write(135);
  //  soBong--;
  //  if (soBong < 0) {
  //    soBong = 0;
  //  }
  //  delay(2000);
}
