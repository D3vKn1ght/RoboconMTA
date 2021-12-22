void doc_CBTrai() {
  GTTrai[0]  = !digitalRead(camBienTrai1);
  GTTrai[1]  = !digitalRead(camBienTrai2);
  GTTrai[2]  = !digitalRead(camBienTrai3);
  GTTrai[3]  = !digitalRead(camBienTrai4);
  GTTrai[4]  = !digitalRead(camBienTrai5);
  GTTrai[5]  = !digitalRead(camBienTrai6);
  GTTrai[6]  = !digitalRead(camBienTrai7);
  GTTrai[7]  = !digitalRead(camBienTrai8);


  if (GTTrai[3] == 1 || GTTrai[4] == 1 )
  {
    ErrorTrai = 0;
  }
  else if (GTTrai[2] == 1)
  {
    ErrorTrai = 2;
  }
  else if (GTTrai[5] == 1)
  {
    ErrorTrai = -2;
  }
  else if (GTTrai[1] == 1)
  {
    ErrorTrai = 3;
  }
  else if (GTTrai[6] == 1)
  {
    ErrorTrai = -3;
  }
  else if (GTTrai[0] == 1)
  {
    ErrorTrai = 4;
  }
  else if (GTTrai[7] == 1)
  {
    ErrorTrai = -4;
  }
  //  else {
  //    if (ErrorTrai < 0) {
  //      ErrorTrai = -5;
  //    }
  //    else {
  //      ErrorTrai = 5;
  //    }
  //  }
}
