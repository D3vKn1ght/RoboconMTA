void LayBong() {
  TimeTemp = millis();
  while (millis() - TimeTemp < timeWaitGetBall) {
    if (digitalRead(congTacNhanBong)) {
      delay(2000);
      break;
    }
  }
}
