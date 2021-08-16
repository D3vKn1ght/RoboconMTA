void tien()
{
  analogWrite(RPWM_L, LSpeed);
  analogWrite(LPWM_L, 0);
  analogWrite(RPWM_R, 0);
  analogWrite(LPWM_R, RSpeed);
}

void lui()
{
  analogWrite(RPWM_L, 0);
  analogWrite(LPWM_L, LSpeed);
  analogWrite(RPWM_R, RSpeed);
  analogWrite(LPWM_R, 0);
}

void phai()
{
  analogWrite(RPWM_L, TocDoXoay);
  analogWrite(LPWM_L, 0);
  analogWrite(RPWM_R, TocDoXoay);
  analogWrite(LPWM_R, 0);
}

void trai()
{
  analogWrite(RPWM_L, 0);
  analogWrite(LPWM_L, TocDoXoay);
  analogWrite(RPWM_R, 0);
  analogWrite(LPWM_R, TocDoXoay);
}

void tienCham()
{
  LSpeed = 50;
  RSpeed = 50;
  tien();
}
void luiCham()
{
  LSpeed = 50;
  RSpeed = 50;
  lui();
}
void dung()
{
  analogWrite(RPWM_L, 0);
  analogWrite(LPWM_L, 0);
  analogWrite(RPWM_R, 0);
  analogWrite(LPWM_R, 0);
}
