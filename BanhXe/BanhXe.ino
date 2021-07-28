#include <stdio.h>
#include "Chung.h"
#include "dieuKhienDongCo.h"
void setup()
{
  // put your setup code here, to run once:
  analogWrite(RPWM_L1, Speed);
  analogWrite(LPWM_L1, Speed);
  analogWrite(RPWM_L2, Speed);
  analogWrite(LPWM_L2, Speed);
  analogWrite(RPWM_R1, Speed);
  analogWrite(LPWM_R1, Speed);
  analogWrite(RPWM_R2, Speed);
  analogWrite(LPWM_R2, Speed);
}

void loop()
{
  tien();
  delay(1000);
  phai();
  delay(1000);
  trai();
  delay(1000);
  lui();
  delay(1000);
  dung();
  delay(3000);
}
