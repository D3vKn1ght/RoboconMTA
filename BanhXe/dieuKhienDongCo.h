void tien()
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

void lui()
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

void phai()
{ 
    analogWrite(RPWM_L1, TocDoXoay);
    analogWrite(LPWM_L1, 0);
    analogWrite(RPWM_L2, TocDoXoay);
    analogWrite(LPWM_L2, 0);
    analogWrite(RPWM_R1, TocDoXoay);
    analogWrite(LPWM_R1, 0);
    analogWrite(RPWM_R2, TocDoXoay);
    analogWrite(LPWM_R2, 0);
}

void trai()
{    
    analogWrite(RPWM_L1, 0);
    analogWrite(LPWM_L1, TocDoXoay);
    analogWrite(RPWM_L2, 0);
    analogWrite(LPWM_L2, TocDoXoay);
    analogWrite(RPWM_R1, 0);
    analogWrite(LPWM_R1, TocDoXoay);
    analogWrite(RPWM_R2, 0);
    analogWrite(LPWM_R2, TocDoXoay);
}

void tienCham()
{
    LSpeed = 50;
    RSpeed=50;
    tien();
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
