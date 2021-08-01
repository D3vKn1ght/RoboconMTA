#include <stdio.h>
#include "Chung.h"
#include "dieuKhienDongCo.h"
#include "CamBienTien.h"
#include "CamBienLui.h"
void setup()
{
  khoiTao();

  Time1 = millis();
  tien();
}

void loop()
{

  doc_CBT();
  //    for ( int i=0;i<=7;i++){
  //      Serial.print(Tien[i]);
  //      Serial.print('\t');
  //    }
  //    Serial.print("\n");
  if ((GTtien[7] && GTtien[5]) || (GTtien[2] && GTtien[0])) {
    dung();
    delay(100);
    lui();
    delay(200);
    dung();
    delay(2000);
    DK_Tien();
    delay(220);
    doc_CBT();
  }
  DK_Tien();





}
