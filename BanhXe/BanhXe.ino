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
  //    for ( int i=0;i<8;i++){
  //
  //  Serial.print(Tien[i]);
  //  Serial.print("\t");
  //
  //    }
  //     Serial.print("\n");
  //     ;
  DK_Tien();





}
