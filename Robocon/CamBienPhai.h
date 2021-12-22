void doc_CBPhai() {
  GTPhai[0]  = !digitalRead(camBienPhai1);
  GTPhai[1]  = !digitalRead(camBienPhai2);
  GTPhai[2]  = !digitalRead(camBienPhai3);
  GTPhai[3]  = !digitalRead(camBienPhai4);
  GTPhai[4]  = !digitalRead(camBienPhai5);
  GTPhai[5]  = !digitalRead(camBienPhai6);
  GTPhai[6]  = !digitalRead(camBienPhai7);
  GTPhai[7]  = !digitalRead(camBienPhai8);


  if ( GTPhai[4] == 1 || GTPhai[3] == 1)
  {
    ErrorPhai = 0;
  }
  else if (GTPhai[2] == 1)
  {
    ErrorPhai = 2;
  }
  else if (GTPhai[5] == 1)
  {
    ErrorPhai = -2;
  }
  else if (GTPhai[1] == 1)
  {
    ErrorPhai = 3;
  }
  else if (GTPhai[6] == 1)
  {
    ErrorPhai = -3;
  }
  else if (GTPhai[0] == 1)
  {
    ErrorPhai = 4;
  }
  else if (GTPhai[7] == 1)
  {
    ErrorPhai = -4;
  }
  //  else {
  //    if (ErrorPhai < 0) {
  //      ErrorPhai = -5;
  //    }
  //    else {
  //      ErrorPhai = 5;
  //    }
  //  }
}
