// ESP32 2.0.4
// 업로드 옵션 : default 4MB with SPIFFS (1.2MB / 1.5MB SPIFFS)
#include "hid_device.h"

#define CHECK_STOP() if ( check_stop() == false ) return;

volatile int play_flag = 0; // 0 : 정지 , 1 : 재생
volatile unsigned long prev_btn1_change_millis;
volatile int pause_flag = 0; // 1 : 일시정지
volatile unsigned long prev_btn2_change_millis;

void send_keyboard2(uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4, uint8_t data5, uint8_t data6, uint8_t data7, uint8_t data8)
{
  uint8_t buffer[8];
  buffer[0] = data1;
  buffer[1] = data2;
  buffer[2] = data3;
  buffer[3] = data4;
  buffer[4] = data5;
  buffer[5] = data6;
  buffer[6] = data7;
  buffer[7] = data8;
  send_keyboard(buffer);
}

void stop_isr()
{
  if ( ( millis() - prev_btn1_change_millis ) < 200 ) return; // debouncing
  play_flag = !play_flag;
  prev_btn1_change_millis = millis();
}

void pause_isr()
{
  if ( ( millis() - prev_btn2_change_millis ) < 200 ) return; // debouncing
  pause_flag = !pause_flag;
  prev_btn2_change_millis = millis();
}

bool check_stop()
{
  while (1)
  {
    if ( play_flag == 0 )
    // 재생 정지된 경우 구동 정지
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      pause_flag = 0;
      return false; // 구동 정지
    }
    else
    {
      digitalWrite(LED1, HIGH);
    }

    if ( pause_flag == 0 )
    // 일시 정지가 아닌 경우 구동
    {
      digitalWrite(LED2, LOW);
      return true;
    }
    digitalWrite(LED2, HIGH);
  }
  return true;
}

void random_delay(int boundary_1, int boundary_2)
{
    int randNumber = random(boundary_1, boundary_2);
    delay(randNumber);
}

void setup()
{
  Serial.begin(11500);
  // 마우스, 키보드 초기화
  usb_hid_init();
  keyboard_flag = true; // 키보드 전송 모드 ON
  mouse_flag = true; // 마우스 전송 모드 ON
  macro_flag = true; // 매크로 모드 OFF
  echo_mode = true; // 시리얼 모니터에 마우스, 키보드 신호 출력
  attachInterrupt(BTN1, stop_isr, RISING);
  attachInterrupt(BTN2, pause_isr, RISING);
  ///////////////////////////////////////////////////////////
  // 레오나르도의 setup의 내용을 아래에 추가하세요
  ///////////////////////////////////////////////////////////
}

void delay_fucntion(int x)  //x분
{
  for(int k=0;k<x;k++)
  {
    delay(1000*60);
    CHECK_STOP();
  }
}
void loop()
{
  ///////////////////////////////////////////////////////////
  // 레오나르도의 loop의 내용을 아래에 추가하세요
  ///////////////////////////////////////////////////////////
  
  CHECK_STOP();
  delay_fucntion(55); //55분 delay
  macro_code();


  Keyboard.releaseAll();
}

//###########################################
//###    MACRO START    #####################
//###########################################
//###########################################
void macro_code()
{
random_delay(2135, 2150);
send_keyboard2(0,0,41,0,0,0,0,0);
random_delay(112, 127);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
random_delay(280, 295);
send_keyboard2(0,0,41,0,0,0,0,0);
random_delay(127, 142);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
random_delay(605, 620);
send_keyboard2(0,0,82,0,0,0,0,0);
random_delay(104, 119);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
random_delay(569, 584);
send_keyboard2(0,0,40,0,0,0,0,0);
random_delay(63, 78);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
random_delay(608, 623);
send_keyboard2(0,0,40,0,0,0,0,0);
random_delay(63, 78);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
random_delay(4357, 4372);
send_keyboard2(0,0,80,0,0,0,0,0);
random_delay(66, 81);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
random_delay(1132, 1147);
send_keyboard2(0,0,40,0,0,0,0,0);
random_delay(65, 80);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
}
//###########################################
//###    MACRO END      #####################
//###########################################
//###########################################
