#define LED 2

#define RST   16 // D0--REST
#define CS    5  // D1--RS
#define SID   4  // D2--RW
#define SCLK  0  // D3--E

#define LCD12864_RST_1()   digitalWrite(RST, HIGH)    
#define LCD12864_RST_0()   digitalWrite(RST, LOW)

#define LCD12864_CS_1()   digitalWrite(CS, HIGH)    
#define LCD12864_CS_0()   digitalWrite(CS, LOW)

#define LCD12864_SCLK_1()   digitalWrite(SCLK, HIGH)    
#define LCD12864_SCLK_0()   digitalWrite(SCLK, LOW)

#define LCD12864_SID_1()   digitalWrite(SID, HIGH)    
#define LCD12864_SID_0()   digitalWrite(SID, LOW)

void SendByteLCD(unsigned char data)
{
  unsigned char i=0;
  for(;i<8;i++){
    if((data<<i)&0x80)  LCD12864_SID_1();
    else LCD12864_SID_0();

    LCD12864_SCLK_0();
    delayMicroseconds(10);
    LCD12864_SCLK_1();
    delayMicroseconds(10);
  }
}

void SPIWR(unsigned char data, unsigned char rs){
  SendByteLCD(0xF8+(rs<<1));
  SendByteLCD(data&0xF0);
  SendByteLCD((data<<4)&0xF0);
}

void WRCommand(unsigned char command){
  LCD12864_CS_0();
  delayMicroseconds(100);
  LCD12864_CS_1();
  SPIWR(command, 0);
  delayMicroseconds(100);
}

void WRData(unsigned char data){
  LCD12864_CS_0();
  delayMicroseconds(100);
  LCD12864_CS_1();
  SPIWR(data, 1);
}

void LCD_Init()
{
  LCD12864_RST_1();
  delay(10);
  LCD12864_RST_0();
  delay(10);
  LCD12864_RST_1();

  WRCommand(0x30);
  WRCommand(0x06);
  WRCommand(0x01);
  WRCommand(0x0C);
  WRCommand(0x02);
}
void ShowNUMChar(unsigned char addr, unsigned char i, unsigned char count)
{
  unsigned char k=0;
  for(;k<count;){
    WRCommand(addr);
    WRData(i+k);
    k++;
    WRData(i+k);
    addr++;
    k++;
  }
}
void WRCGRAM(unsigned char a, unsigned char b, unsigned addr){
  unsigned char i=0;
  for(;i<16;){
    WRCommand(addr+i);
    WRData(a);
    WRData(a);
    i++;
    WRCommand(addr+i);
    WRData(b);
    WRData(b);
    i++;
  }
}
void ShowChar(unsigned char addr, unsigned char *buff, unsigned char count)
{
  unsigned char i=0;
  WRCommand(addr);

  for(;i<count;i++){
    WRData(buff[i]);
  }
}
void ShowCGChar(unsigned char addr, unsigned char i)
{
  unsigned char k=0;
  for(;k<0x20;k++)
  {
    WRCommand(addr+k);
    WRData(0x00);
    WRData(i);
  }
}
unsigned char x[128] = {"ABCDEFGHIJKLMNOP"};
unsigned char f[12] = {0x46,0x31,0x2D,0x2D,0x45,0x6E,0x67,0x6C,0x69,0x73,0x68,0x00};
unsigned char my[8] = {0xF7,0xF0,0xF7,0xF1,0xF7,0xF2,0xF7,0xF4};
unsigned char LV[8] = {0xF6,0xF0,0xF6,0xF1,0xF6,0xF2,0xF6,0xF3};
void setup() {
  pinMode(LED, OUTPUT);

  pinMode(RST,  OUTPUT);
  pinMode(CS,   OUTPUT);
  pinMode(SID,  OUTPUT);
  pinMode(SCLK, OUTPUT);
  

  LCD_Init();

  ShowNUMChar(0x80, 0x01, 0x0F);
  ShowNUMChar(0x90, 0x30, 0x0F);
  ShowNUMChar(0x88, 0x41, 0x0F);
  ShowNUMChar(0x98, 0x61, 0x0F);

  delay(2000);
  WRCommand(0x01);
/*
  WRCGRAM(0xFF, 0x00, 0x40);
  WRCGRAM(0x00, 0xFF, 0x50);
  WRCGRAM(0xAA, 0xAA, 0x60);
  WRCGRAM(0x55, 0x55, 0x70);
*/
  ShowChar(0x80, x, 16);
  ShowChar(0x90, f, 12);
  ShowChar(0x88, my, 8);
  ShowChar(0x9C, LV, 8);
}

void loop() {
  digitalWrite(LED, HIGH);   
  delay(1000);                      
  digitalWrite(LED, LOW);   
  delay(1000);                      
}
