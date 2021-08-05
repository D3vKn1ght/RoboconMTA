#define congTacHanhTrinh 35
//----------------------------------------Dong co ---------------------------------//
#define R_EN_L1 20
#define L_EN_L1 21
#define R_EN_L2 22
#define L_EN_L2 23
#define R_EN_R1 24
#define L_EN_R1 25
#define R_EN_R2 26
#define L_EN_R2 27
#define RPWM_L1 2
#define LPWM_L1 3
#define RPWM_L2 4
#define LPWM_L2 5
#define RPWM_R1 6
#define LPWM_R1 7
#define RPWM_R2 8
#define LPWM_R2 9
int TocDoXoay = 255;
int SetTocDo = 70 ;
int LSpeed = SetTocDo;
int RSpeed = SetTocDo;

//----------------------------------------Cam Bien Tien ---------------------------------//
#define camBienTien1 A0
#define camBienTien2 A4
#define camBienTien3 A1
#define camBienTien4 A5
#define camBienTien5 A2
#define camBienTien6 A6
#define camBienTien7 A3
#define camBienTien8 A7
int Tien[8];
int GTtien[8];
int  it;
float Et, Errort = 0, previous_Errort = 0;
float PID_value_Tien;
int St, Tt;
float Pt = 0, It = 0, Dt = 0, previous_It = 0;
float Kp = 45;
float Kd = 40 ;
float Ki = 0;
//----------------------------------------Cam Bien Lui ---------------------------------//
#define camBienLui1 A8
#define camBienLui2 A12
#define camBienLui3 A9
#define camBienLui4 A13
#define camBienLui5 A10
#define camBienLui6 A14
#define camBienLui7 A11
#define camBienLui8 A15
int SSLui[8];
int GTlui[8];
int  iLui;
float El, Errorl = 0, previous_Errorl = 0;
float PID_value_Lui = 0;
int Sl, Tl;
float Pl = 0, Il = 0, Dl = 0, previous_Il = 0;
float Kp2 = 35;
float Kd2 = 35 ;
float Ki2 = 0;

//----------------------------------------Khoi tao ---------------------------------//
int tb = 700;
unsigned long TimeTemp;
int dem = 0;
void khoiTao() {
  Serial.begin(9600);
  pinMode(congTacHanhTrinh, INPUT);
  pinMode(camBienTien1, INPUT);
  pinMode(camBienTien2, INPUT);
  pinMode(camBienTien3, INPUT);
  pinMode(camBienTien4, INPUT);
  pinMode(camBienTien5, INPUT);
  pinMode(camBienTien6, INPUT);
  pinMode(camBienTien7, INPUT);
  pinMode(camBienTien8, INPUT);
  pinMode(camBienLui1, INPUT);
  pinMode(camBienLui2, INPUT);
  pinMode(camBienLui3, INPUT);
  pinMode(camBienLui4, INPUT);
  pinMode(camBienLui5, INPUT);
  pinMode(camBienLui6, INPUT);
  pinMode(camBienLui7, INPUT);
  pinMode(camBienLui8, INPUT);
  pinMode(R_EN_L1, OUTPUT);
  pinMode(L_EN_L1, OUTPUT);
  pinMode(R_EN_L2, OUTPUT);
  pinMode(L_EN_L2, OUTPUT);
  pinMode(R_EN_R1, OUTPUT);
  pinMode(L_EN_R1, OUTPUT);
  pinMode(R_EN_R2, OUTPUT);
  pinMode(L_EN_R2, OUTPUT);
  pinMode(RPWM_L1, OUTPUT);
  pinMode(LPWM_L1, OUTPUT);
  pinMode(RPWM_L2, OUTPUT);
  pinMode(LPWM_L2, OUTPUT);
  pinMode(RPWM_R1, OUTPUT);
  pinMode(LPWM_R1, OUTPUT);
  pinMode(RPWM_R2, OUTPUT);
  pinMode(LPWM_R2, OUTPUT);
  digitalWrite(R_EN_L1, HIGH);
  digitalWrite(L_EN_L1, HIGH);
  digitalWrite(R_EN_L2, HIGH);
  digitalWrite(L_EN_L2, HIGH);
  digitalWrite(R_EN_R1, HIGH);
  digitalWrite(L_EN_R1, HIGH);
  digitalWrite(R_EN_R2, HIGH);
  digitalWrite(L_EN_R2, HIGH);
}
