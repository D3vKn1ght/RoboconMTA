void tien()
{

    digitalWrite(R_EN_L1, HIGH);
    digitalWrite(L_EN_L1, LOW);
    digitalWrite(R_EN_L2, HIGH);
    digitalWrite(L_EN_L2, LOW);
    digitalWrite(R_EN_R1, LOW);
    digitalWrite(L_EN_R1, HIGH);
    digitalWrite(R_EN_R2, LOW);
    digitalWrite(L_EN_R2, HIGH);
}

void lui()
{
    digitalWrite(R_EN_L1, LOW);
    digitalWrite(L_EN_L1, HIGH);
    digitalWrite(R_EN_L2, LOW);
    digitalWrite(L_EN_L2, HIGH);
    digitalWrite(R_EN_R1, HIGH);
    digitalWrite(L_EN_R1, LOW);
    digitalWrite(R_EN_R2, HIGH);
    digitalWrite(L_EN_R2, LOW);
}

void phai()
{
    Speed = 50;
    digitalWrite(R_EN_L1, HIGH);
    digitalWrite(L_EN_L1, LOW);
    digitalWrite(R_EN_L2, HIGH);
    digitalWrite(L_EN_L2, LOW);
    digitalWrite(R_EN_R1, HIGH);
    digitalWrite(L_EN_R1, LOW);
    digitalWrite(R_EN_R2, HIGH);
    digitalWrite(L_EN_R2, LOW);
}

void trai()
{
    Speed = 50;
    digitalWrite(R_EN_L1, LOW);
    digitalWrite(L_EN_L1, HIGH);
    digitalWrite(R_EN_L2, LOW);
    digitalWrite(L_EN_L2, HIGH);
    digitalWrite(R_EN_R1, LOW);
    digitalWrite(L_EN_R1, HIGH);
    digitalWrite(R_EN_R2, LOW);
    digitalWrite(L_EN_R2, HIGH);
}

void tienCham()
{
    Speed = 50;
    tien();
}
void dung()
{
    digitalWrite(R_EN_L1, LOW);
    digitalWrite(L_EN_L1, LOW);
    digitalWrite(R_EN_L2, LOW);
    digitalWrite(L_EN_L2, LOW);
    digitalWrite(R_EN_R1, LOW);
    digitalWrite(L_EN_R1, LOW);
    digitalWrite(R_EN_R2, LOW);
    digitalWrite(L_EN_R2, LOW);
}
