//----------------------------------------Chon san ---------------------------------//
#define IsSanTrai false
//----------------------------------------Timer ---------------------------------//
#define timeWaitRetry 4000
#define timeZ 3000
#define timeWaitGetBall 60000
//----------------------------------------Servo ---------------------------------//
#include <Servo.h>
#define TIME_OUT 5000
#define SERVO_PIN1 52 //Servo4
#define SERVO_PIN2 50 //Servo3
#define SERVO_PIN3 48 //Servo2
#define SERVO_PIN4 46 //Servo1

Servo gServo1, gServo2;

//#define congTacLayBong 5

unsigned long timeStart;
unsigned long timeEnd;

// ----------Cong tac hanh trinh--------
//53 --ctht1
//51 --ctht2
//49 --ctht3
//47 --ctht4
//22 --c12
//24 --c13
//26 --c14
//28 --c15

#define congTacHanhTrinh 53
#define congTacNhanBong 51
#define ThaBong1 49 
#define ThaBong2 22
#define ThaBong3 47 
#define LayBong1 28
#define LayBong2 26
#define LayBong3 24


//----------------------------------------Dong co ---------------------------------//
#define R_EN_L 21
#define L_EN_L 18
#define R_EN_R 14
#define L_EN_R 17
#define RPWM_L 2
#define LPWM_L 3
#define RPWM_R 4
#define LPWM_R 5
int TocDoXoay = 200;
int SetTocDo = 110;
int LSpeed = SetTocDo;
int RSpeed = SetTocDo;

//----------------------------------------Cam Bien Tien ---------------------------------//
#define camBienTien1 A7 // A0
#define camBienTien2 A6 // A4
#define camBienTien3 A5 // A1
#define camBienTien4 A4 // A5
#define camBienTien5 A3 // A2
#define camBienTien6 A2 // A6
#define camBienTien7 A1 // A3
#define camBienTien8 A0 // A7
int Tien[8];

int GTtien[8];
int it;
float Et, Errort = 0, previous_Errort = 0;
float PID_value_Tien;
int St, Tt;
float Pt = 0, It = 0, Dt = 0, previous_It = 0;
float Kp = 50;
float Kd = 5;
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
int iLui;
float El, Errorl = 0, previous_Errorl = 0;
float PID_value_Lui = 0;
int Sl, Tl;
float Pl = 0, Il = 0, Dl = 0, previous_Il = 0;
float Kp2 = 50;
float Kd2 = 5;
float Ki2 = 0;

//----------------------------------------Khoi tao ---------------------------------//
int tb = 400;
bool viTriThaBong[] = {false, false, false, false, false, true, true, true, true, true};
bool viTriLayBong[] = {false, false, false, false, false, false, true, true, true, true};
int defineLayBong[] = {LayBong1, LayBong2, LayBong3};
int defineThaBong[] = {ThaBong1, ThaBong2, ThaBong3};
int iViTri = 0;
unsigned long TimeTemp;
int dem = 0;
int soBong = 1;

void khoiTao()
{
  Serial.begin(9600);
  pinMode(congTacHanhTrinh, INPUT);
  pinMode(congTacNhanBong, INPUT);
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

  pinMode(LayBong1, INPUT);
  pinMode(LayBong2, INPUT);
  pinMode(LayBong3, INPUT);
  pinMode(ThaBong1, INPUT);
  pinMode(ThaBong1, INPUT);
  pinMode(ThaBong1, INPUT);

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


  gServo1.attach(SERVO_PIN1);
  gServo1.write(135);
  gServo2.attach(SERVO_PIN2);
  gServo2.write(230);
}
