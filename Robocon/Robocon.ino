#include <stdio.h>
#include "Chung.h"
#include "dieuKhienDongCo.h"
#include "CamBienTien.h"
#include "CamBienLui.h"
#include "ThaLayBong.h"
#include "LayBong.h"
#include "ThaBong.h"
void setup()
{
  khoiTao();

  tien();
  dem = 0;


}

void loop()
{
  doc_CBT(); 
 

//      for (int i = 0; i <= 7; i++) {
//        Serial.print(Tien[i]);
//        Serial.print("\t");
//      }
//      Serial.print("\n");
  if ((GTtien[0] && GTtien[3]) || (GTtien[1] && GTtien[4]) || (GTtien[2] && GTtien[5]) || (GTtien[3] && GTtien[6]) || (GTtien[4] && GTtien[7]) ) {
    dem++;
    TimeTemp = millis();
    doc_CBL();
    while ((millis() - TimeTemp) < 120 ) {
      doc_CBT();
    }
    doc_CBL();
  }
  if (dem == 0) {
    DK_Tien();
  }
  else if (dem == 1) {
    diemLayBong();
    dem++;
  }
  else if (dem == 3) {
    dung();
    LayBong();
    delay(100);
    dem++;
  }
  else if (dem >= 4) {
    doc_CBL();
//      for (int i = 0; i <= 7; i++) {
//        Serial.print(SSLui[i]);
//        Serial.print("\t");
//      }
//      Serial.print("\n");
    DK_Lui();
    //    if (digitalRead(congTacHanhTrinh)) {
    //     if (digitalRead(congTacHanhTrinh)) {                                                                                                                                                                               //    if (digitalRead(congTacHanhTrinh)) {
    //      dung();
    //      ThaBong();
    //      delay(50);
    //      veLine();
    //      dem = 0;
    //    }
  }
  else {
    DK_Tien();
  }


}
