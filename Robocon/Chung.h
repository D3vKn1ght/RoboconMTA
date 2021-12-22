//----------------------------------------Chon san ---------------------------------//
bool IsSanTrai = false;


//----------------------------------------Timer ---------------------------------//
#define timeWaitRetry 4000
#define timeZ 3000
#define timeVaoLayBong 700
#define timeLuiVeLineChinh 1500
#define timeLuiVeLineChinhMax  4000
#define timeWaitGetBall 90000
#define timeLuiMu 2000
//----------------------------------------Servo ---------------------------------//
#include <Servo.h>
#define TIME_OUT 5000
#define SERVO_PIN1 46
#define SERVO_PIN2 48
#define SERVO_PIN3 50
#define SERVO_PIN4 52
#define SERVO_PIN5 13
//#define SERVO_PIN6 12
Servo gServo1, gServo2, gServo3, gServo4, gServo5, gServo6;

unsigned long timeStart;
unsigned long timeEnd;

// ----------Cong tac hanh trinh--------


#define congTacHanhTrinh 47  //R16   47
#define congTacNhanBong 49  //R17    49
#define ThaBong1 44  //SW1        22
#define ThaBong2 30  //SW2
#define ThaBong3 29   //SW4           24
#define LayBong1 43    //SW5           25
#define LayBong2 26    //SW6        26
#define LayBong3 27    //SW7       27
#define GatBong1 42   //SW9        28
#define GatBong2 45   //SW10   29
#define GatBong3 53   //SW8      30
#define GatBong4 51    //R19         53
#define ThaBongDoiBan1  23 //SW13     42
#define ThaBongDoiBan2 22   //S14     43
#define ThaBongDoiBan3 25    //44
#define ThaBongDoiBan4 24        //45

#define DaoNguoc 28  //R18

//----------------------------------------Dong co ---------------------------------//
//#define R_EN_L1 22
//#define L_EN_L1 23
//#define R_EN_L2 24
//#define L_EN_L2 25
//#define R_EN_R1 21
//#define L_EN_R1 18
//#define R_EN_R2 14
//#define L_EN_R2 17

//P5
#define RPWM_L1 3
#define LPWM_L1 2
//P6
#define RPWM_L2 5
#define LPWM_L2 4
//P10
#define RPWM_R1 7
#define LPWM_R1 6
//P9
#define RPWM_R2 9
#define LPWM_R2 8


int TocDo = 140;
int TocDoCham = TocDo / 2;
int TocDoNhanh = 200;
int TocDoXoay = TocDo ;
int TocDoXoayCham = TocDoXoay * 3 / 5;
int TocDoXoayNhanh = 6 * TocDoXoay / 5;

int LSpeed = TocDo;
int RSpeed = TocDo;

int lostLineLeft = -4;
int lostLineRight = 4;

//----------------------------------------Dong co buoc ---------------------------------//
#define stepPin 10
#define dirPin 11  // đảo chiều
#define enPin 32
//----------------------------------------Cam Bien Tha Bong ---------------------------------//
#define camBienGatBong 12
//----------------------------------------Cam Bien Tien ---------------------------------//
//P3
#define camBienTien1 A7
#define camBienTien2 A6
#define camBienTien3 A5
#define camBienTien4 A4
#define camBienTien5 A3
#define camBienTien6 A2
#define camBienTien7 A1
#define camBienTien8 A0
int Tien[8];

int GTtien[8];
int it;
float Et, Errort = 0, previous_Errort = 0;
float PID_value_Tien;
int St, Tt;
float Pt = 0, It = 0, Dt = 0, previous_It = 0;
float Kp = 50;
float Kd = 20;
float Ki = 0;
//----------------------------------------Cam Bien Lui ---------------------------------//
//P4
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
float Kd2 = 20;
float Ki2 = 0;
//----------------------------------------Cam Bien Trai ---------------------------------//
//P7
#define camBienTrai1 41//34
#define camBienTrai2 40//35
#define camBienTrai3 39//36
#define camBienTrai4 38//37
#define camBienTrai5 37//38
#define camBienTrai6 36//39
#define camBienTrai7 35//40
#define camBienTrai8 34//41


int GTTrai[8];
float ErrorTrai = 0;

//----------------------------------------Cam Bien Phai ---------------------------------//
//P8
#define camBienPhai1 21//14
#define camBienPhai2 20//15
#define camBienPhai3 19//16
#define camBienPhai4 18//17
#define camBienPhai5 17//18
#define camBienPhai6 16//19
#define camBienPhai7 15//20
#define camBienPhai8 14//21

int GTPhai[8];
float ErrorPhai = 0;

//----------------------------------------Khoi tao ---------------------------------//

#define STATE_CHUA_XU_LY 0
#define STATE_DANG_XU_LY 1
#define REV_KHONG -1
#define REV_CHUA 0
#define REV_BAT_DAU 1
#define REV_DANG 2
#define STEP_0_KHONG_LAM_GI 0
#define STEP_1_CAN_LINE 1
#define STEP_2_RE_DEN_LINE 2
#define STEP_3_DI_VAO_LAY_BONG 3
#define STEP_4_DUNG_LAY_BONG 4
#define STEP_5_LUI_THEO_LINE 5
#define STEP_6_LUI_THA_BONG 6

int tb = 400;
bool viTriThaBong[] = {false, false, false, false, false, true, true, true, true, true};
bool viTriLayBong[] = {false, false, false, false, false, false, true, true, true, true};
bool viTriGatBong[] = {false, false, false, false, false, false, true, true, true, true};
bool viTriThaBongDoiBan[] = {false, false, false, false, false, false, true, true, true, true};
int defineLayBong[] = {LayBong1, LayBong2, LayBong3};
int defineThaBong[] = {ThaBong1, ThaBong2, ThaBong3};
int defineGatBong[] = {GatBong1, GatBong2, GatBong3, GatBong4};
int defineThaBongDoiBan[] = {ThaBongDoiBan1, ThaBongDoiBan2, ThaBongDoiBan3, ThaBongDoiBan4};
int iViTri = 0;
unsigned long TimeTemp;

int state = STATE_CHUA_XU_LY;
int Step = STEP_0_KHONG_LAM_GI;
int rev = REV_KHONG;
int ViTriDaoNguoc = 0;

void khoiTao()
{
//  Serial.begin(9600);
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

  pinMode(camBienGatBong, INPUT);

  pinMode(LayBong1, INPUT);
  pinMode(LayBong2, INPUT);
  pinMode(LayBong3, INPUT);
  pinMode(ThaBong1, INPUT);
  pinMode(ThaBong2, INPUT);
  pinMode(ThaBong3, INPUT);
  pinMode(GatBong1, INPUT);
  pinMode(GatBong2, INPUT);
  pinMode(GatBong3, INPUT);
  pinMode(ThaBongDoiBan1, INPUT);
  pinMode(ThaBongDoiBan2, INPUT);
  pinMode(ThaBongDoiBan3, INPUT);
  pinMode(DaoNguoc, INPUT);

  //  pinMode(R_EN_L1, OUTPUT);
  //  pinMode(L_EN_L1, OUTPUT);
  //  pinMode(R_EN_L2, OUTPUT);
  //  pinMode(L_EN_L2, OUTPUT);
  //  pinMode(R_EN_R1, OUTPUT);
  //  pinMode(L_EN_R1, OUTPUT);
  //  pinMode(R_EN_R2, OUTPUT);
  //  pinMode(L_EN_R2, OUTPUT);
  pinMode(RPWM_L1, OUTPUT);
  pinMode(LPWM_L1, OUTPUT);
  pinMode(RPWM_L2, OUTPUT);
  pinMode(LPWM_L2, OUTPUT);
  pinMode(RPWM_R1, OUTPUT);
  pinMode(LPWM_R1, OUTPUT);
  pinMode(RPWM_R2, OUTPUT);
  pinMode(LPWM_R2, OUTPUT);
  //  digitalWrite(R_EN_L1, HIGH);
  //  digitalWrite(L_EN_L1, HIGH);
  //  digitalWrite(R_EN_L2, HIGH);
  //  digitalWrite(L_EN_L2, HIGH);
  //  digitalWrite(R_EN_R1, HIGH);
  //  digitalWrite(L_EN_R1, HIGH);
  //  digitalWrite(R_EN_R2, HIGH);
  //  digitalWrite(L_EN_R2, HIGH);


  gServo1.attach(SERVO_PIN1);
  gServo1.write(135);

  gServo2.attach(SERVO_PIN2);
  gServo2.write(230);

  gServo3.attach(SERVO_PIN3);
  gServo3.write(10);
  gServo4.attach(SERVO_PIN4);
  gServo4.write(100);
  gServo5.attach(SERVO_PIN5);
  gServo5.write(10);

  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);

}
