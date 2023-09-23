const char* keyboard_manufact = "Dell";
const char* keyboard_product = "Dell Universal Receiver";

uint16_t ch9329_vid = 0x413C;
uint16_t ch9329_pid = 0x8505;

// 공통 변수
// 시작시 세팅
volatile int mouse_flag = false; // 마우스 작동
volatile int keyboard_flag = false; // 키보드 작동
volatile int macro_flag = false; // 매크로 작동

volatile int echo_mode = false; // 마우스 키보드 데이타를 시리얼 출력할지?
