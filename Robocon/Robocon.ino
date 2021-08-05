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
  doc_CBL();
  if ((GTtien[7] && GTtien[5]) || (GTtien[2] && GTtien[0])) {
    dem++;
    TimeTemp = millis();
    while ((millis() - TimeTemp) < 120 ) {
      doc_CBT();
      doc_CBL();
    }
  }
  //  for ( int i = 0; i <= 7; i++) {
  //    Serial.print(Tien[i]);
  //    Serial.print('\t');
  //  }
  //  Serial.print(dem);
  //  Serial.print("\n");
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
    DK_Lui();
                                                                                                                                                                                            //    if (digitalRead(congTacHanhTrinh)) {
    //      dung();
    //      ThaBong();
    //      veLine();
    //      dem = 0;
    //    }
  }
  else {
    DK_Tien();
  }
}
