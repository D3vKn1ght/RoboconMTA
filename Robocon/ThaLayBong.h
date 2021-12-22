void XoayDenLine() {
  doc_CBT();
  doc_CBL();
  int temp = Errort;
  bool over = false;
  TimeTemp = millis();
  if (IsSanTrai) {
    while (true) {
      temp = Errort;
      doc_CBT();
      doc_CBL();
      xoayTrai(TocDoXoayCham);
      //check quay vuot line chinh
      if (over == false) {
        if (Errort >= temp) {
          continue;
        }
        else {
          over = true;
          //          delay(50);
        }
      }
      //cham line moi
      else {

        if (GTtien[2] || GTtien[3] || GTtien[4] || GTtien[5]) {
          if (millis() - TimeTemp < 500) {
            continue;
          }
          Errorl = lostLineRight;
          break;
        }
      }
    }
  }
  else {
    while (true) {
      temp = Errort;
      doc_CBT();
      doc_CBL();
      xoayTrai(TocDoXoayCham);
      //check quay vuot line chinh
      if (over == false) {
        if (Errort <= temp) {
          continue;
        }
        else {
          over = true;
        }
      }
      //cham line moi
      else {
        if (GTtien[2] || GTtien[3] || GTtien[4] || GTtien[5]) {
          if (millis() - TimeTemp < 500) {
            continue;
          }
          Errorl = lostLineRight;
          break;
        }
      }
    }
  }
}
void ReDenLine() {
  doc_CBT();
  int temp = Errort;
  bool over = false;
  TimeTemp = millis();
  if (IsSanTrai) {
    while (true) {
      temp = Errort;
      doc_CBT();
      ReTraiNgaBa(TocDoXoayNhanh);
      //check quay vuot line chinh
      if (over == false) {
        if (Errort >= temp) {
          continue;
        }
        else {
          over = true;
        }
      }
      //cham line moi
      else {
        if (GTtien[2] || GTtien[3] || GTtien[4] || GTtien[5]) {
          if (millis() - TimeTemp < 600) {
            continue;
          }
          break;
        }
      }
    }
  }
  else {
    while (true) {
      temp = Errort;
      doc_CBT();
      ReTraiNgaBa(TocDoXoayNhanh);
      //check quay vuot line chinh
      if (over == false) {
        if (Errort <= temp) {
          continue;
        }
        else {
          over = true;
        }
      }
      //cham line moi
      else {
        if (GTtien[2] || GTtien[3] || GTtien[4] || GTtien[5]) {
          if (millis() - TimeTemp < 400) {
            continue;
          }
          break;
        }
      }
    }
  }
  DK_Tien(TocDo);
}


void ReVeLineChinh() {
  tien(TocDo);
  delay(250);
  TimeTemp = millis();
  //  RePhaiNgaBa(TocDoXoay);
  //  delay(400);
  doc_CBT();
  int temp = Errort;
  bool over = false;
  if (IsSanTrai) {
    while (true) {
      temp = Errort;
      doc_CBT();
      RePhaiNgaBa(TocDoXoay);
      //check quay vuot line chinh
      if (over == false) {
        if (Errort <= temp) {
          continue;
        }
        else {
          over = true;
        }
      }
      //cham line moi
      else {
        if (GTtien[2] || GTtien[3] || GTtien[4] || GTtien[5]) {
          if (millis() - TimeTemp < 600) {
            continue;
          }
          break;
        }
      }
    }
  } else {
    while (true) {
      temp = Errort;
      doc_CBT();
      RePhaiNgaBa(TocDoXoay);
      //check quay vuot line chinh
      if (over == false) {
        if (Errort >= temp) {
          continue;
        }
        else {
          over = true;
        }
      }
      //cham line moi
      else {
        if (GTtien[2] || GTtien[3] || GTtien[4] || GTtien[5]) {
          if (millis() - TimeTemp < 600) {
            continue;
          }
          break;
        }
      }
    }
  }
  DK_Tien(TocDo);
}
void canChinhTruocSau() {
  int timeOut = 1500;
  TimeTemp = millis();
  while (millis() - TimeTemp < timeOut) {
    doc_CBT();
    doc_CBL();

    if (IsSanTrai) {
      if ( Errort < 0 ) {
        xoayTraiTren(TocDoXoay);
      }
      else if (Errort > 0) {
        xoayPhaiTren(TocDoXoay);
      }
      else {
        dung();
        break;
      }
    }
    else {
      if ( Errort > 0 ) {
        xoayTraiTren(TocDoXoay);
      }
      else if (Errort < 0) {
        xoayPhaiTren(TocDoXoay);
      }
      else {
        dung();
        break;
      }
    }
  }
  TimeTemp = millis();
  while (millis() - TimeTemp < timeOut) {
    doc_CBT();
    doc_CBL();

    if (IsSanTrai) {
      if ( Errorl < 0 ) {
        xoayTraiDuoi(TocDoXoay);
      }
      else if (Errorl > 0) {
        xoayPhaiDuoi(TocDoXoay);
      }
      else {
        dung();
        break;
      }
    }
    else {
      if ( Errorl > 0 ) {
        xoayTraiDuoi(TocDoXoay);
      }
      else if (Errorl < 0) {
        xoayPhaiDuoi(TocDoXoay);
      }
      else {
        dung();
        break;
      }
    }
  }
}
void canChinhTrucLineLayBong() {
  int timeOut = 2000;
  TimeTemp = millis();
  while (millis() - TimeTemp < 150) {
    DK_Tien(TocDo);
    doc_CBT();
    doc_CBL();
  }
  TimeTemp = millis();
  while (!checkNgaBaLui()) {
    doc_CBT();
    doc_CBL();
    DK_Tien(TocDo);
    if (millis() - TimeTemp > timeOut) {
      break;
    }
  }
  while (true) {
    doc_CBT();
    doc_CBL();
    DK_Tien(TocDo);
    if (millis() - TimeTemp > 700) {
      break;
    }
  }
  while (millis() - TimeTemp < 200) {
    DK_Tien(TocDo);
    doc_CBT();
    doc_CBL();
  }
  dung();
  delay(200);
  for ( int i = 0; i < 3; i++) {
    canChinhTruocSau();
  }
}
void canChinhNgaBaTien() {
  int timeOut = 1000;
  doc_CBT();
  doc_CBL();
  doc_CBTrai();
  doc_CBPhai();
  if (checkNgaBaTien()) {
    TimeTemp = millis();
    while (millis() - TimeTemp < 500) {
      doc_CBT();
      doc_CBL();
      doc_CBTrai();
      tien(TocDoCham);
    }
  }
  if (checkNgaBaLui()) {
    TimeTemp = millis();
    while (millis() - TimeTemp < 500) {
      doc_CBT();
      doc_CBL();
      doc_CBTrai();
      lui(TocDoCham);
    }
  }
  TimeTemp = millis();
  while (millis() - TimeTemp < timeOut) {
    doc_CBT();
    doc_CBL();
    doc_CBTrai();
    if (IsSanTrai) {
      if ( Errort < 0 ) {
        xoayTraiTren(TocDoXoay);
      }
      else if (Errort > 0) {
        xoayPhaiTren(TocDoXoay);
      }
      else {
        dung();
        break;
      }
    }
    else {
      if ( Errort > 0 ) {
        xoayTraiTren(TocDoXoay);
      }
      else if (Errort < 0) {
        xoayPhaiTren(TocDoXoay);
      }
      else {
        dung();
        break;
      }
    }
  }
  TimeTemp = millis();
  while (millis() - TimeTemp < timeOut) {
    doc_CBT();
    doc_CBL();
    doc_CBTrai();
    if (IsSanTrai) {
      if ( Errorl < 0 ) {
        xoayTraiDuoi(TocDoXoay);
      }
      else if (Errorl > 0) {
        xoayPhaiDuoi(TocDoXoay);
      }
      else {
        dung();
        break;
      }
    }
    else {
      if ( Errorl > 0 ) {
        xoayTraiDuoi(TocDoXoay);
      }
      else if (Errorl < 0) {
        xoayPhaiDuoi(TocDoXoay);
      }
      else {
        dung();
        break;
      }
    }
  }

  if (IsSanTrai) {
    TimeTemp = millis();
    while (millis() - TimeTemp < timeOut) {
      doc_CBT();
      doc_CBL();
      doc_CBTrai();
      int demSoLineSang = 0;
      for (int i = 0; i <= 7; i++)
      {
        if (GTTrai[i])
        {
          demSoLineSang++;
        }
      }
      if (demSoLineSang == 0)
      {
        tien(TocDoCham);
      }
      else {
        dung();
        break;
      }
    }
    TimeTemp = millis();
    while (millis() - TimeTemp < timeOut) {
      doc_CBT();
      doc_CBL();
      doc_CBTrai();
      Serial.println(ErrorTrai);
      if (ErrorTrai < 0 ) {
        tien(TocDoCham);
      }
      else if (ErrorTrai > 0 ) {
        lui(TocDoCham);
      }
      else {
        dung();
        break;
      }
    }
  }
  else {
    TimeTemp = millis();
    while (millis() - TimeTemp < timeOut) {
      doc_CBT();
      doc_CBL();
      doc_CBPhai();
      int demSoLineSang = 0;
      for (int i = 0; i <= 7; i++)
      {
        if (GTPhai[i])
        {
          demSoLineSang++;
        }
      }
      if (demSoLineSang == 0)
      {
        tien(TocDoCham);
      }
      else {
        dung();
        break;
      }
    }
    TimeTemp = millis();
    while (millis() - TimeTemp < timeOut) {
      doc_CBT();
      doc_CBL();
      doc_CBPhai();
      if (ErrorPhai > 0 ) {
        tien(TocDoCham);
      }
      else if (ErrorPhai < 0 ) {
        lui(TocDoCham);
      }
      else {
        dung();
        break;
      }
    }
  }
}


void canChinhNgaBaNgang() {
  int timeOut = 1500;
  TimeTemp = millis();
  while (millis() - TimeTemp < timeOut) {
    doc_CBT();
    doc_CBTrai();
    doc_CBPhai();

    if (IsSanTrai) {
      if ( Errort < 0 ) {
        xoayTraiTren(TocDoXoay);
      }
      else if (Errort > 0) {
        xoayPhaiTren(TocDoXoay);
      }
      else {
        dung();
        break;
      }
    }
    else {
      if ( Errort > 0 ) {
        xoayTraiTren(TocDoXoay);
      }
      else if (Errort < 0) {
        xoayPhaiTren(TocDoXoay);
      }
      else {
        dung();
        break;
      }
    }

  }
  TimeTemp = millis();
  while (millis() - TimeTemp < timeOut) {
    doc_CBT();
    doc_CBTrai();
    doc_CBPhai();
    if (IsSanTrai) {
      if (ErrorPhai < -2 || ErrorTrai > 2) {
        lui(TocDoCham);
        delay(50);
        continue;
      }
      dung();
      delay(1000);
      if ( (ErrorTrai + ErrorPhai) < 0 ) {
        xoayTraiDuoi(TocDoXoay);

      }
      else if ((ErrorTrai + ErrorPhai) > 0) {
        xoayPhaiDuoi(TocDoXoay);
      }
      else {
        dung();
        break;
      }
    }
    else {
      if (ErrorPhai > -2 || ErrorTrai < 2) {
        lui(TocDoCham);
        delay(50);
        continue;
      }
      dung();
      delay(1000);
      if ( (ErrorTrai + ErrorPhai) > 0 ) {
        xoayTraiDuoi(TocDoXoay);

      }
      else if ((ErrorTrai + ErrorPhai) < 0) {
        xoayPhaiDuoi(TocDoXoay);
      }
      else {
        dung();
        break;
      }
    }
  }
}
