#include <Adafruit_GFX.h> 
#include <Arduino_ST7789.h> 
#include <SPI.h>
#include <math.h>

#define TFT_DC    16
#define TFT_RST   4  
Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST);

#define PI 3.14

struct Axis {
  int a[4];
  int b[4];
  int c[4];
  int d[4];
};

void setup() {
  Serial.begin(115200);
  tft.init(240, 240);
  tft.fillScreen(BLACK);
  tft.drawLine(119, 0, 0, 119, RED);
  tft.drawLine(0, 120, 119, 239, RED);  
  /*for (double i=0;i<=360;i+=3){
    int x = (int)120*cos(i*PI/180);
    int y = (int)120*sin(i*PI/180);
    tft.drawLine(120, 120, 120+x, 120-y, RED);
    delay(200);
  }*/
  Axis mteaching = {{119,0,0,119},{0,120,119,239},{119,239,239,119},{239,119,120,0}};
  for (double i=90;i>=0;i-=3){
    /*tft.drawLine(mteaching.a[0], mteaching.a[1], mteaching.a[2], mteaching.a[3], BLACK);
    tft.drawLine(mteaching.b[0], mteaching.b[1], mteaching.b[2], mteaching.b[3], BLACK);
    tft.drawLine(mteaching.c[0], mteaching.c[1], mteaching.c[2], mteaching.c[3], BLACK);
    tft.drawLine(mteaching.d[0], mteaching.d[1], mteaching.d[2], mteaching.d[3], BLACK);*/
    
    int x1 = 120+(int)120*cos(i*PI/180);
    int y1 = 120-(int)120*sin(i*PI/180);
    int x2 = 120+(int)120*cos((i+90)*PI/180);
    int y2 = 120-(int)120*sin((i+90)*PI/180);
    tft.drawLine(x1, y1, x2, y2, CYAN);

    int x3 = 120+(int)120*cos((i+90)*PI/180);
    int y3 = 120-(int)120*sin((i+90)*PI/180);
    int x4 = 120+(int)120*cos((i+180)*PI/180);
    int y4 = 120-(int)120*sin((i+180)*PI/180);
    tft.drawLine(x3, y3, x4, y4, CYAN);

    int x5 = 120+(int)120*cos((i+180)*PI/180);
    int y5 = 120-(int)120*sin((i+180)*PI/180);
    int x6 = 120+(int)120*cos((i+270)*PI/180);
    int y6 = 120-(int)120*sin((i+270)*PI/180);
    tft.drawLine(x5, y5, x6, y6, CYAN);

    int x7 = 120+(int)120*cos((i+270)*PI/180);
    int y7 = 120-(int)120*sin((i+270)*PI/180);
    int x8 = 120+(int)120*cos((i)*PI/180);
    int y8 = 120-(int)120*sin((i)*PI/180);
    tft.drawLine(x7, y7, x8, y8, CYAN);

    mteaching={{x1, y1, x2, y2},{x3,y3,x4,y4},{x5,y5,x6,y6},{x7,y7,x8,y8}};
    delay(200);
  }
}

void loop() {
  
}
