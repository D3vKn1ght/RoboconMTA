
void welcome() {
  Serial.print("San trai\n");
}
void diNgangTrai(int tocDo) {
  analogWrite(RPWM_L1, tocDo);
  analogWrite(LPWM_L1, 0);
  analogWrite(RPWM_L2, 0);
  analogWrite(LPWM_L2, tocDo);
  analogWrite(RPWM_R1, tocDo);
  analogWrite(LPWM_R1, 0);
  analogWrite(RPWM_R2, 0);
  analogWrite(LPWM_R2, tocDo);
}
void diNgangTraiHaiBanh(int tocDo) {
  analogWrite(RPWM_L1, tocDo);
  analogWrite(LPWM_L1, 0);
  analogWrite(RPWM_L2, 0);
  analogWrite(LPWM_L2, tocDo);
  analogWrite(RPWM_R1, 0);
  analogWrite(LPWM_R1, 0);
  analogWrite(RPWM_R2, 0);
  analogWrite(LPWM_R2, 0);
}
void diNgangPhai(int tocDo) {
  analogWrite(RPWM_L1, 0);
  analogWrite(LPWM_L1, tocDo);
  analogWrite(RPWM_L2, tocDo);
  analogWrite(LPWM_L2, 0);
  analogWrite(RPWM_R1, 0);
  analogWrite(LPWM_R1, tocDo);
  analogWrite(RPWM_R2, tocDo);
  analogWrite(LPWM_R2, 0);
}
void diNgangPhaiHaiBanh(int tocDo) {
  analogWrite(RPWM_L1, 0);
  analogWrite(LPWM_L1, 0);
  analogWrite(RPWM_L2, 0);
  analogWrite(LPWM_L2, 0);
  analogWrite(RPWM_R1, 0);
  analogWrite(LPWM_R1, tocDo);
  analogWrite(RPWM_R2, tocDo);
  analogWrite(LPWM_R2, 0);
}
void RePhaiNgaBa(int tocDo) {
  if (IsSanTrai) {
    analogWrite(RPWM_L1, 0);
    analogWrite(LPWM_L1, tocDo);
    analogWrite(RPWM_L2, 0);
    analogWrite(LPWM_L2, tocDo / 2 );
    analogWrite(RPWM_R1, 0);
    analogWrite(LPWM_R1, tocDo / 2);
    analogWrite(RPWM_R2, 0);
    analogWrite(LPWM_R2, 0);
  }
  else {
    analogWrite(RPWM_L1, tocDo / 2);
    analogWrite(LPWM_L1, 0);
    analogWrite(RPWM_L2, 0);
    analogWrite(LPWM_L2, 0 );
    analogWrite(RPWM_R1, tocDo);
    analogWrite(LPWM_R1, 0);
    analogWrite(RPWM_R2, tocDo / 2);
    analogWrite(LPWM_R2, 0);
  }
}

void ReTraiNgaBa(int tocDo)
{
  IsSanTrai = !IsSanTrai;
  RePhaiNgaBa(tocDo);
  IsSanTrai = !IsSanTrai;

}

void xoayTrai(int tocDo)
{
  if (IsSanTrai) {
    analogWrite(RPWM_L1, tocDo);
    analogWrite(LPWM_L1, 0);
    analogWrite(RPWM_L2, tocDo);
    analogWrite(LPWM_L2, 0);
    analogWrite(RPWM_R1, tocDo);
    analogWrite(LPWM_R1, 0);
    analogWrite(RPWM_R2, tocDo);
    analogWrite(LPWM_R2, 0);
  }
  else {
    analogWrite(RPWM_L1, 0);
    analogWrite(LPWM_L1, tocDo);
    analogWrite(RPWM_L2, 0);
    analogWrite(LPWM_L2, tocDo);
    analogWrite(RPWM_R1, 0);
    analogWrite(LPWM_R1, tocDo);
    analogWrite(RPWM_R2, 0);
    analogWrite(LPWM_R2, tocDo);
  }
}
void xoayPhai(int tocDo)
{
  IsSanTrai = !IsSanTrai;
  xoayTrai(tocDo);
  IsSanTrai = !IsSanTrai;
}
void xoayTraiTren(int tocDo)
{
  if (IsSanTrai) {
    analogWrite(RPWM_L1, tocDo);
    analogWrite(LPWM_L1, 0);
    analogWrite(RPWM_L2, 0);
    analogWrite(LPWM_L2, 0);
    analogWrite(RPWM_R1, tocDo);
    analogWrite(LPWM_R1, 0);
    analogWrite(RPWM_R2, 0);
    analogWrite(LPWM_R2, 0);
  }
  else {
    analogWrite(RPWM_L1, 0);
    analogWrite(LPWM_L1, tocDo);
    analogWrite(RPWM_L2, 0);
    analogWrite(LPWM_L2, 0);
    analogWrite(RPWM_R1, 0);
    analogWrite(LPWM_R1, tocDo);
    analogWrite(RPWM_R2, 0);
    analogWrite(LPWM_R2, 0);
  }
}
void xoayPhaiTren(int tocDo)
{
  IsSanTrai = !IsSanTrai;
  xoayTraiTren(tocDo);
  IsSanTrai = !IsSanTrai;
}
void xoayTraiDuoi(int tocDo)
{
  if (!IsSanTrai) {
    analogWrite(RPWM_L1, 0);
    analogWrite(LPWM_L1, 0);
    analogWrite(RPWM_L2, tocDo);
    analogWrite(LPWM_L2, 0);
    analogWrite(RPWM_R1, 0);
    analogWrite(LPWM_R1, 0);
    analogWrite(RPWM_R2, tocDo);
    analogWrite(LPWM_R2, 0);
  }
  else {
    analogWrite(RPWM_L1, 0);
    analogWrite(LPWM_L1, 0);
    analogWrite(RPWM_L2, 0);
    analogWrite(LPWM_L2, tocDo);
    analogWrite(RPWM_R1, 0);
    analogWrite(LPWM_R1, 0);
    analogWrite(RPWM_R2, 0);
    analogWrite(LPWM_R2, tocDo);
  }
}
void xoayPhaiDuoi(int tocDo)
{
  IsSanTrai = !IsSanTrai;
  xoayTraiDuoi(tocDo);
  IsSanTrai = !IsSanTrai;
}
void xoayTraiTrai(int tocDo)
{
  if (IsSanTrai) {
    analogWrite(RPWM_L1, tocDo);
    analogWrite(LPWM_L1, 0);
    analogWrite(RPWM_L2, tocDo);
    analogWrite(LPWM_L2, 0);
    analogWrite(RPWM_R1, 0);
    analogWrite(LPWM_R1, 0);
    analogWrite(RPWM_R2, 0);
    analogWrite(LPWM_R2, 0);
  }
  else {
    analogWrite(RPWM_L1, 0);
    analogWrite(LPWM_L1, tocDo);
    analogWrite(RPWM_L2, 0);
    analogWrite(LPWM_L2, tocDo);
    analogWrite(RPWM_R1, 0);
    analogWrite(LPWM_R1, 0);
    analogWrite(RPWM_R2, 0);
    analogWrite(LPWM_R2, 0);
  }
}
void xoayPhaiTrai(int tocDo)
{ IsSanTrai = !IsSanTrai;
  xoayTraiTrai(tocDo);
  IsSanTrai = !IsSanTrai;
}
void xoayTraiPhai(int tocDo)
{
  if (IsSanTrai) {
    analogWrite(RPWM_L1, 0);
    analogWrite(LPWM_L1, 0);
    analogWrite(RPWM_L2, 0);
    analogWrite(LPWM_L2, 0);
    analogWrite(RPWM_R1, tocDo);
    analogWrite(LPWM_R1, 0);
    analogWrite(RPWM_R2, tocDo);
    analogWrite(LPWM_R2, 0);
  }
  else {
    analogWrite(RPWM_L1, 0);
    analogWrite(LPWM_L1, 0);
    analogWrite(RPWM_L2, 0);
    analogWrite(LPWM_L2, 0);
    analogWrite(RPWM_R1, 0);
    analogWrite(LPWM_R1, tocDo);
    analogWrite(RPWM_R2, 0);
    analogWrite(LPWM_R2, tocDo);
  }
}
void xoayPhaiPhai(int tocDo)
{ IsSanTrai = !IsSanTrai;
  xoayTraiPhai(tocDo);
  IsSanTrai = !IsSanTrai;
}


void lui()
{
  analogWrite(RPWM_L1, LSpeed);
  analogWrite(LPWM_L1, 0);
  analogWrite(RPWM_L2, LSpeed);
  analogWrite(LPWM_L2, 0);
  analogWrite(RPWM_R1, 0);
  analogWrite(LPWM_R1, RSpeed);
  analogWrite(RPWM_R2, 0);
  analogWrite(LPWM_R2, RSpeed);
}
void tien()
{
  analogWrite(RPWM_L1, 0);
  analogWrite(LPWM_L1, LSpeed);
  analogWrite(RPWM_L2, 0);
  analogWrite(LPWM_L2, LSpeed);
  analogWrite(RPWM_R1, RSpeed);
  analogWrite(LPWM_R1, 0);
  analogWrite(RPWM_R2, RSpeed);
  analogWrite(LPWM_R2, 0);
}

void tien(int tocDo)
{
  LSpeed = tocDo;
  RSpeed = tocDo;
  tien();
}

void lui(int tocDo)
{
  LSpeed = tocDo;
  RSpeed = tocDo;
  lui();
}

void tienCham()
{
  LSpeed = TocDoCham;
  RSpeed = TocDoCham;
  tien();
}
void luiCham()
{
  LSpeed = TocDoCham;
  RSpeed = TocDoCham;
  lui();
}
void dung()
{
  analogWrite(RPWM_L1, 0);
  analogWrite(LPWM_L1, 0);
  analogWrite(RPWM_L2, 0);
  analogWrite(LPWM_L2, 0);
  analogWrite(RPWM_R1, 0);
  analogWrite(LPWM_R1, 0);
  analogWrite(RPWM_R2, 0);
  analogWrite(LPWM_R2, 0);
}
