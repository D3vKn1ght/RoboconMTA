#define congTacHanhTrinh 8


//----------------------------------------Dong co ---------------------------------//
#define R_EN_L 20
#define L_EN_L 21
#define R_EN_R 24
#define L_EN_R 25
#define RPWM_L 2
#define LPWM_L 3
#define RPWM_R 6
#define LPWM_R 7
int TocDoXoay = 200;
int SetTocDo = 120 ;
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
float Kp = 50;
float Kd = 20 ;
float Ki = 0;
//----------------------------------------Cam Bien Lui ---------------------------------//
#define camBienLui1 A8
#define camBienLui2 A9
#define camBienLui3 A10
#define camBienLui4 A11
#define camBienLui5 A12
#define camBienLui6 A13
#define camBienLui7 A14
#define camBienLui8 A15
int SSLui[8];
int GTlui[8];
int  iLui;
float El, Errorl = 0, previous_Errorl = 0;
float PID_value_Lui = 0;
int Sl, Tl;
float Pl = 0, Il = 0, Dl = 0, previous_Il = 0;
float Kp2 = 50;
float Kd2 = 20 ;
float Ki2 = 0;

//----------------------------------------Khoi tao ---------------------------------//
int tb = 400;
bool viTri[] = {false, true, true, true, true, true, true};
int iViTri = 0;
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
  pinMode(R_EN_L, OUTPUT);
  pinMode(L_EN_L, OUTPUT);
  pinMode(R_EN_R, OUTPUT);
  pinMode(L_EN_R, OUTPUT);
  pinMode(RPWM_L, OUTPUT);
  pinMode(LPWM_L, OUTPUT);
  pinMode(RPWM_R, OUTPUT);
  pinMode(LPWM_R, OUTPUT);
  digitalWrite(R_EN_L, HIGH);
  digitalWrite(L_EN_L, HIGH);
  digitalWrite(R_EN_R, HIGH);
  digitalWrite(L_EN_R, HIGH);
}
