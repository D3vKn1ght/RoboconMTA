#include <stdio.h>
#include "Chung.h"
#include "dieuKhienDongCo.h"
#include "CamBienTien.h"
#include "CamBienLui.h"
#include "CamBienTrai.h"
#include "CamBienPhai.h"
#include "KhoiDau.h"
#include "ThaLayBong.h"
#include "LayBong.h"
#include "ThaBong.h"



void setup()
{
  khoiTao();

  switchRetry();
  //  //  welcome();
  state = STATE_CHUA_XU_LY;

  Step = STEP_0_KHONG_LAM_GI;
  //  vuotQuaChuZ();
  iViTri = 0;

  calPosReverse();
  checkSan();
}
void loop()
{
  doc_CBT();
  doc_CBL();
  if (IsSanTrai) {
    doc_CBTrai();
  }
  else {
    doc_CBPhai();
  }

  if (checkNgaBaTien())
  {
    TimeTemp = millis();
    while (millis() - TimeTemp < 55)
    {
      doc_CBT();
      doc_CBL();
      doc_CBTrai();
      doc_CBPhai();
    }

    if (state == STATE_CHUA_XU_LY)
    {
      if (rev == REV_DANG) {
        iViTri--;
      }
      else {
        iViTri++;
      }
      if (iViTri == ViTriDaoNguoc && rev == REV_CHUA) {
        rev = REV_BAT_DAU;
      }

      if ( viTriThaBong[(iViTri) % 6] && rev != REV_CHUA)
      {
        //Bat dau xu ly
        state = STATE_DANG_XU_LY;
        if (viTriLayBong[iViTri  % 6]) {
          Step = STEP_2_RE_DEN_LINE;
        }
        else {
          Step = STEP_1_CAN_LINE;
        }
      }
      if (iViTri == 4) {
        TocDo = TocDo * 4 / 3;
      }
    }
  }

  if (Step == STEP_1_CAN_LINE) {
    dung();
    TimeTemp = millis();
    while (millis() - TimeTemp < 500)
    {
      doc_CBT();
      doc_CBL();
      doc_CBTrai();
      doc_CBPhai();
    }
    canChinhNgaBaTien();
    dung();
    delay(100);
    XoayDenLine();
    dung();
    TimeTemp = millis();
    while (millis() - TimeTemp < 100)
    {
      doc_CBT();
      doc_CBL();
      doc_CBTrai();
      doc_CBPhai();
    }
    if (iViTri == 5) {
      canChinhTruocSau();
      Step = STEP_6_LUI_THA_BONG;
    }
    else {
      canChinhTrucLineLayBong();
      Step = STEP_5_LUI_THEO_LINE;
    }
    dung();
    delay(100);
  }
  else if (Step == STEP_2_RE_DEN_LINE)
  {
    ReDenLine();
    Step = STEP_3_DI_VAO_LAY_BONG;
  }

  else if (Step == STEP_3_DI_VAO_LAY_BONG)
  {
    TimeTemp = millis();
    while (millis() - TimeTemp < 700) {
      doc_CBT();
      DK_Tien(TocDo);
    }
    TimeTemp = millis();
    while (!checkNgaBaTien()) {
      doc_CBT();
      if (millis() - TimeTemp < timeVaoLayBong) {
        DK_Tien(TocDo);
      }
      else {
        DK_Tien(TocDo * 2 / 3);
      }
    }
    Step = STEP_4_DUNG_LAY_BONG;
  }
  else if (Step == STEP_4_DUNG_LAY_BONG)
  {
    dung();
    LayBong();
    delay(100);
    Step = STEP_5_LUI_THEO_LINE;
  }
  else if (Step == STEP_5_LUI_THEO_LINE)
  {
    TimeTemp = millis();
    while (!checkNgaBaLui())
    {
      doc_CBL();
      if (millis() - TimeTemp < timeLuiVeLineChinh && viTriLayBong[iViTri  % 6]) {
        DK_Lui(TocDo);
      }
      else {
        DK_Lui(TocDo * 2 / 3);
      }
      if (millis() - TimeTemp < 1200 && viTriLayBong[iViTri  % 6]) {
        continue;
      }
      if (checkNgaBaLui()) {
        break;
      }
    }
    //    dung();
    //    delay(3000);
    Step = STEP_6_LUI_THA_BONG;
  }
  else if (Step == STEP_6_LUI_THA_BONG)
  {
    TimeTemp = millis();
    while (!digitalRead(congTacHanhTrinh)) {
      lui(TocDoCham);
      //      if (millis() - TimeTemp > timeLuiMu) {
      //        break;
      //      }
    }
    dung();
    GatBongDoiBan();
    ThaBongDoiBan();
    ThaBong();

    delay(50);
    viTriThaBong[(iViTri) % 6] = false;
    if (rev == REV_BAT_DAU) {
      rev = REV_DANG;
      IsSanTrai = !IsSanTrai;
    }
    int soViTriThaBong = 0;
    for (int i = 1; i <= 3; i++) {
      if (viTriThaBong[i]) {
        soViTriThaBong++;
      }
    }
    if (soViTriThaBong == 0 && iViTri != 5 && rev != REV_KHONG) {
      rev = REV_KHONG;
      IsSanTrai = !IsSanTrai;
    }
    checkSan();
    ReVeLineChinh();
    state = STATE_CHUA_XU_LY;
    Step = STEP_0_KHONG_LAM_GI;
    if (iViTri == 5) {
      while (true) {
        dung();
      }
    }
  }
  else
  {
    DK_Tien(TocDo);
  }


  //test
  //  Serial.println(digitalRead(congTacHanhTrinh));
  //    tien();
  //       DK_Tien(TocDoTien);
  //
  //      Test line truoc
  //  doc_CBT();
  //  for (int i = 0; i <= 7; i++) {
  //    Serial.print(Tien[i]);
  //    Serial.print("\t");
  //  }
  //  Serial.print("\n");
  //       Test Line sau
  //                  doc_CBL();
  //                           for (int i = 0; i <= 7; i++) {
  //                             Serial.print(SSLui[i]);
  //                             Serial.print("\t");
  //                           }
  //                           Serial.print("\n");
  //               DK_Lui(TocDo);
  //Test Line trai
  //      doc_CBTrai();
  //      for (int i = 0; i <= 7; i++) {
  //        Serial.print(GTTrai[i]);
  //        Serial.print("\t");
  //      }
  //      Serial.print("\n");

  //Test Line phai
  //    doc_CBPhai();
  //    for (int i = 0; i <= 7; i++) {
  //      Serial.print(GTPhai[i]);
  //      Serial.print("\t");
  //    }
  //    Serial.print("\n");


}
