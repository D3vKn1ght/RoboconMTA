#include <stdio.h>
#include "Chung.h"
#include "dieuKhienDongCo.h"
#include "CamBienTien.h"
#include "CamBienLui.h"
#include "KhoiDau.h"
#include "ThaLayBong.h"
#include "LayBong.h"
#include "ThaBong.h"


void setup()
{
  khoiTao();
  switchRetry();
  //  welcome();
  //    tien();
  dem = -1;
  vuotQuaChuZ();
  iViTri = 0;

//  delay(1000);
//  ThaBong4();
  //  for (int i=0;i<8;i++){
  //    Serial.print(viTriThaBong[i]);
  //    Serial.print(" ");
  //    }
  //    Serial.print("\n");
  //    for (int i=0;i<8;i++){
  //      Serial.print(viTriLayBong[i]);
  //      Serial.print(" ");
  //      }
  //      Serial.print("\n");


}
//void loop() {}
void loop()
{
  doc_CBT();


  //  trai();
  //  Serial.println(digitalRead(congTacHanhTrinh));
  //  tien();
  //       DK_Tien();
  //
  //  //     Test line truoc
  //      for (int i = 0; i <= 7; i++) {
  //        Serial.print(Tien[i]);
  //        Serial.print("\t");
  //      }
  //      Serial.print("\n");


  if (checkNgaBa())
  {
    for (int i = 0; i < 6; i++)
    {
      doc_CBT();
      doc_CBL();
      delay(20);
    }
    if (dem == -1)
    {
      if (viTriThaBong[(iViTri + 1) % 6])
      {
        dem = 1;
      }
      iViTri++;
            if (iViTri == 5) {
              ThaBong4();
            }
    }
    else
    {
      dem++;
    }
  }


  if (dem == 1)
  {
    diemLayBong();
    dem++;
  }
  else if (dem == 2)
  {
    DK_Tien();
    if (!(viTriLayBong[iViTri  % 6]))
    {
      tien();
      delay(500);
      dungNeuConBong();
    }
  }
  else if (dem == 3)
  {
    dung();
    LayBong();
    delay(100);

    dem++;
  }
  else if (dem >= 4)
  {
    doc_CBL();
    if (checkNgaBaLui())
    {
      while (!digitalRead(congTacHanhTrinh)) {
        Errorl = 0;
        DK_Lui();
      }
      dung();
      ThaBong();
      delay(50);
      veLine();
      dem = -1;
    }
    DK_Lui();
  }

  else
  {
    DK_Tien();
  }

  //       Test Line sau
  //            doc_CBL();
  //                     for (int i = 0; i <= 7; i++) {
  //                       Serial.print(SSLui[i]);
  //                       Serial.print("\t");
  //                     }
  //                     Serial.print("\n");
  //               DK_Lui();


}
