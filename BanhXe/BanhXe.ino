#include <stdio.h>
#include "Chung.h"
#include "dieuKhienDongCo.h"
#include "CamBienTien.h"
#include "CamBienLui.h"
#include "DiemThaBong.h"
void setup()
{
  khoiTao();

  tien();
  dem = 0;
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
    dem++;

    diemThaBong();

  }
  DK_Tien();




}
