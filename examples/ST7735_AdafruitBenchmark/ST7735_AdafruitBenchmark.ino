// ST7735 library benchmark
// (c) 2019 Pawel A. Hernik

/*
 ST7735 128x160 1.8" LCD pinout (header at the top, from left):
 #1 LED   -> 3.3V
 #2 SCK   -> SCL/D13/PA5
 #3 SDA   -> MOSI/D11/PA7
 #4 A0/DC -> D8/PA1  or any digital
 #5 RESET -> D9/PA0  or any digital
 #6 CS    -> D10/PA2 or any digital
 #7 GND   -> GND
 #8 VCC   -> 3.3V
*/

#define SCR_WD   128
#define SCR_HT   160
#include <SPI.h>
#include <Adafruit_GFX.h>

#if (__STM32F1__) // bluepill
#define TFT_CS  PA2
#define TFT_DC  PA1
#define TFT_RST PA0
#include <Arduino_ST7735_STM.h>
#else
#define TFT_CS 10
#define TFT_DC  8
#define TFT_RST 9
//#include <Arduino_ST7735_Fast.h>
#endif

Arduino_ST7735 tft = Arduino_ST7735(TFT_DC, TFT_RST, TFT_CS);

// Color definitions
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF
#define RGBto565(r,g,b) ((((r) & 0xF8) << 8) | (((g) & 0xFC) << 3) | ((b) >> 3)) 


// ------------------------------------------------
unsigned long FillScreenTest()
{
  unsigned long start = millis();
  for(int i=0;i<5;i++) {
    tft.fillScreen(RED);
    tft.fillScreen(GREEN);
    tft.fillScreen(BLUE);
    tft.fillScreen(YELLOW);
  }
  return millis()-start;
}

// ------------------------------------------------
unsigned long ClearScreenTest()
{
  unsigned long start = millis();
  for(int i=0;i<5*4;i++) 
    tft.fillScreen(BLACK);
  return millis()-start;
}
// ------------------------------------------------
const uint16_t imgF[] PROGMEM = {0xF800,0xF840,0xF8A0,0xF900,0xF960,0xF9C0,0xFA20,0xFA80,0xFAE0,0xFB40,0xFBA0,0xFC00,0xFC60,0xFCC0,0xFD20,0xFD80,0xFDE0,0xFE40,0xFEA0,0xFF00,0xFF60,0xFFC0,0xFFE0,0xEFE0,0xE7E0,0xD7E0,0xCFE0,0xBFE0,0xB7E0,0xA7E0,0x9FE0,0x8FE0,0x87E0,0x77E0,0x6FE0,0x5FE0,0x57E0,0x47E0,0x3FE0,0x2FE0,0x27E0,0x17E0,0xFE0,0x7E0,0x7E1,0x7E3,0x7E4,0x7E6,0x7E7,0x7E9,0x7EA,0x7EC,0x7ED,0x7EF,0x7F0,0x7F2,0x7F3,0x7F5,0x7F6,0x7F8,0x7F9,0x7FB,0x7FC,0x7FE,0x7FF,0x79F,0x73F,0x6DF,0x67F,0x61F,0x5BF,0x55F,0x4FF,0x49F,0x43F,0x3DF,0x37F,0x31F,0x2BF,0x25F,0x1FF,0x19F,0x13F,0xDF,0x7F,0x1F,0x81F,0x101F,0x201F,0x281F,0x381F,0x401F,0x501F,0x581F,0x681F,0x701F,0x801F,0x881F,0x981F,0xA01F,0xB01F,0xB81F,0xC81F,0xD01F,0xE01F,0xE81F,0xF81F,0xF81F,0xF81D,0xF81C,0xF81A,0xF819,0xF817,0xF816,0xF814,0xF813,0xF811,0xF810,0xF80E,0xF80D,0xF80B,0xF80A,0xF808,0xF807,0xF805,0xF804,0xF802,0xF801,
                                 0xF800,0xF840,0xF8A0,0xF900,0xF960,0xF9C0,0xFA20,0xFA80,0xFAE0,0xFB40,0xFBA0,0xFC00,0xFC60,0xFCC0,0xFD20,0xFD80,0xFDE0,0xFE40,0xFEA0,0xFF00,0xFF60,0xFFC0,0xFFE0,0xEFE0,0xE7E0,0xD7E0,0xCFE0,0xBFE0,0xB7E0,0xA7E0,0x9FE0,0x8FE0,0x87E0,0x77E0,0x6FE0,0x5FE0,0x57E0,0x47E0,0x3FE0,0x2FE0,0x27E0,0x17E0,0xFE0,0x7E0,0x7E1,0x7E3,0x7E4,0x7E6,0x7E7,0x7E9,0x7EA,0x7EC,0x7ED,0x7EF,0x7F0,0x7F2,0x7F3,0x7F5,0x7F6,0x7F8,0x7F9,0x7FB,0x7FC,0x7FE,0x7FF,0x79F,0x73F,0x6DF,0x67F,0x61F,0x5BF,0x55F,0x4FF,0x49F,0x43F,0x3DF,0x37F,0x31F,0x2BF,0x25F,0x1FF,0x19F,0x13F,0xDF,0x7F,0x1F,0x81F,0x101F,0x201F,0x281F,0x381F,0x401F,0x501F,0x581F,0x681F,0x701F,0x801F,0x881F,0x981F,0xA01F,0xB01F,0xB81F,0xC81F,0xD01F,0xE01F,0xE81F,0xF81F,0xF81F,0xF81D,0xF81C,0xF81A,0xF819,0xF817,0xF816,0xF814,0xF813,0xF811,0xF810,0xF80E,0xF80D,0xF80B,0xF80A,0xF808,0xF807,0xF805,0xF804,0xF802,0xF801};
uint16_t img[SCR_WD];
unsigned long DrawImageTest()
{
  for(int i=0;i<SCR_WD;i++) img[i] = tft.rgbWheel(256+i*511/SCR_WD);
  unsigned long start = millis();
  for(int i=0;i<5*4;i++) {
    for(int y=0;y<SCR_HT;y++) tft.drawImage(0,y,SCR_WD,1,img);
  }
  return millis()-start;
}
// ------------------------------------------------ 
unsigned long DrawImageFTest()
{
  unsigned long start = millis();
  for(int i=0;i<5*4;i++) {
    for(int y=0;y<SCR_HT;y++) tft.drawImageF(0,y,SCR_WD,1,imgF);
  }
  return millis()-start;
}
// ------------------------------------------------ 
unsigned long orig[14]={ 1443,1443,361212,51728,473844,33872,24608,
                         440804,134556,203012,110552,266208,86616,457856 };

unsigned long res[14];
void result(int i)
{
  Serial.print(res[i]);
  if(res[i]<1000000) Serial.print("\t");
  Serial.print("\t\t\t");
  Serial.print(100*orig[i]/res[i]);
  Serial.println("%");
}

void setup(void) 
{
  Serial.begin(9600);
  Serial.println(F("ST7735 128x168"));
  tft.init();
  tft.fillScreen(BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(WHITE);  tft.setTextSize(1);
  tft.println("ST7735 128x168");
  tft.println("Library Benchmark");
  tft.println("starts in 3s ...");
  delay(13000);

  Serial.println(F("Benchmark   Time (microseconds)"));

  res[0]=FillScreenTest();
  Serial.print(F("FillScreen Mbps          "));
  Serial.println(String(res[0])+"ms  "+String(1000*20.0/res[0])+"fps  "+String(20.0*SCR_WD*SCR_HT*16/res[0]/1000.0)+" Mbps\t"+100*orig[0]/res[0]+"%");

  res[1]=ClearScreenTest();
  Serial.print(F("ClearScreen Mbps         "));
  Serial.println(String(res[1])+"ms  "+String(1000*20.0/res[1])+"fps  "+String(20.0*SCR_WD*SCR_HT*16/res[1]/1000.0)+" Mbps\t"+100*orig[1]/res[1]+"%");

  res[1]=DrawImageTest();
  Serial.print(F("DrawImage Mbps           "));
  Serial.println(String(res[1])+"ms  "+String(1000*20.0/res[1])+"fps  "+String(20.0*SCR_WD*SCR_HT*16/res[1]/1000.0)+" Mbps\t"+100*orig[1]/res[1]+"%"); 

  res[1]=DrawImageFTest();
  Serial.print(F("DrawImageF Mbps          "));
  Serial.println(String(res[1])+"ms  "+String(1000*20.0/res[1])+"fps  "+String(20.0*SCR_WD*SCR_HT*16/res[1]/1000.0)+" Mbps\t"+100*orig[1]/res[1]+"%"); 
  
  res[2]=testFillScreen();
  Serial.print(F("Screen fill              "));
  result(2);
  delay(500);

  res[3]=testText();
  Serial.print(F("Text                     "));
  result(3);
  delay(3000);

  res[4]=testLines(CYAN);
  Serial.print(F("Lines                    "));
  result(4);
  delay(500);

  res[5]=testFastLines(RED, BLUE);
  Serial.print(F("Horiz/Vert Lines         "));
  result(5);
  delay(500);

  res[6]=testRects(GREEN);
  Serial.print(F("Rectangles (outline)     "));
  result(6);
  delay(500);

  res[7]=testFilledRects(YELLOW, MAGENTA);
  Serial.print(F("Rectangles (filled)      "));
  result(7);
  delay(500);

  res[8]=testFilledCircles(10, MAGENTA);
  Serial.print(F("Circles (filled)         "));
  result(8);

  res[9]=testCircles(10, WHITE);
  Serial.print(F("Circles (outline)        "));
  result(9);
  delay(500);

  res[10]=testTriangles();
  Serial.print(F("Triangles (outline)      "));
  result(10);
  delay(500);

  res[11]=testFilledTriangles();
  Serial.print(F("Triangles (filled)       "));
  result(11);
  delay(500);

  res[12]=testRoundRects();
  Serial.print(F("Rounded rects (outline)  "));
  result(12);
  delay(500);

  res[13]=testFilledRoundRects();
  Serial.print(F("Rounded rects (filled)   "));
  result(13);
  delay(500);

  Serial.println(F("Done!"));

  int c1=YELLOW, c2=WHITE;
  tft.fillScreen(BLACK);
  tft.setCursor(0, 0);
  tft.setTextSize(1);
  tft.setTextColor(CYAN);
  //tft.println("RESULTS:");

  //tft.setTextSize(1);
  //tft.println();
  tft.setTextColor(GREEN);
  tft.println(F("Benchmark    Time/us"));
  tft.setTextColor(c1); tft.print(F("FillScr Mbps  "));
  //tft.setTextColor(c2); tft.print(String(res[0])+"ms "+String(20.0*SCR_WD*SCR_HT*16/res[0]/1000.0)+" Mbps");
  tft.setTextColor(c2); tft.println(String(20.0*SCR_WD*SCR_HT*16/res[0]/1000.0));
  //tft.setTextColor(c1); tft.print(F("ClrScr  Mbps  "));
  ///tft.setTextColor(c2); tft.print(String(res[1])+"ms "+String(20.0*SCR_WD*SCR_HT*16/res[1]/1000.0)+" Mbps");
  //tft.setTextColor(c2); tft.println(String(20.0*SCR_WD*SCR_HT*16/res[1]/1000.0));
  tft.setTextColor(c1); tft.print(F("DrwImgF Mbps  "));
  tft.setTextColor(c2); tft.println(String(20.0*SCR_WD*SCR_HT*16/res[1]/1000.0));
  tft.setTextColor(c1); tft.print(F("Screen fill   "));
  tft.setTextColor(c2); tft.println(res[2]);
  tft.setTextColor(c1); tft.print(F("Text          "));
  tft.setTextColor(c2); tft.println(res[3]);
  tft.setTextColor(c1); tft.print(F("Lines         "));
  tft.setTextColor(c2); tft.println(res[4]);
  tft.setTextColor(c1); tft.print(F("H/V Lines     "));
  tft.setTextColor(c2); tft.println(res[5]);
  tft.setTextColor(c1); tft.print(F("Rects O       "));
  tft.setTextColor(c2); tft.println(res[6]);
  tft.setTextColor(c1); tft.print(F("Rects F       "));
  tft.setTextColor(c2); tft.println(res[7]);
  tft.setTextColor(c1); tft.print(F("Circles F     "));
  tft.setTextColor(c2); tft.println(res[8]);
  tft.setTextColor(c1); tft.print(F("Circles O     "));
  tft.setTextColor(c2); tft.println(res[9]);
  tft.setTextColor(c1); tft.print(F("Tris O        "));
  tft.setTextColor(c2); tft.println(res[10]);
  tft.setTextColor(c1); tft.print(F("Tris F        "));
  tft.setTextColor(c2); tft.println(res[11]);
  tft.setTextColor(c1); tft.print(F("Round rects O "));
  tft.setTextColor(c2); tft.println(res[12]);
  tft.setTextColor(c1); tft.print(F("Round rects F "));
  tft.setTextColor(c2); tft.println(res[13]);
  tft.setTextColor(RED); tft.println(F("Done!"));
}

/*
ST7735 128x168 - original
Benchmark   Time (microseconds)
FillScreen Mbps          1443ms  13.86fps  4.54 Mbps  100%
ClearScreen Mbps         1444ms  13.85fps  4.54 Mbps  99%
Screen fill              361208       100%
Text                     51728        100%
Lines                    473844       100%
Horiz/Vert Lines         33876        99%
Rectangles (outline)     24608        100%
Rectangles (filled)      440808       99%
Circles (filled)         134560       99%
Circles (outline)        202996       100%
Triangles (outline)      110548       100%
Triangles (filled)       266220       99%
Rounded rects (outline)  86608        100%
Rounded rects (filled)   457860       99%
Done!


ST7735_Fast 128x168
Benchmark   Time (microseconds)
FillScreen Mbps          942ms  21.23fps  6.96 Mbps  153%
ClearScreen Mbps         942ms  21.23fps  6.96 Mbps 153%
Screen fill              236052       153%
Text                     33528        154%
Lines                    238608       198%
Horiz/Vert Lines         20996        161%
Rectangles (outline)     15116        162%
Rectangles (filled)      287916       153%
Circles (filled)         77240        174%
Circles (outline)        102868       197%
Triangles (outline)      56120        196%
Triangles (filled)       189220       140%
Rounded rects (outline)  46180        187%
Rounded rects (filled)   296400       154%
Done!

DrawImage Mbps           1146ms  17.45fps  5.72 Mbps
DrawImageF Mbps          1342ms  14.90fps  4.88 Mbps

STM32:
Benchmark   Time (microseconds)
FillScreen Mbps          182ms  109.89fps  36.01 Mbps 792%
ClearScreen Mbps         182ms  109.89fps  36.01 Mbps 792%
DrawImage Mbps           234ms  85.47fps  28.01 Mbps  616%
DrawImageF Mbps          234ms  85.47fps  28.01 Mbps  616%
Screen fill              45622        791%
Text                     9537         542%
Lines                    106473       445%
Horiz/Vert Lines         4705         719%
Rectangles (outline)     3780         651%
Rectangles (filled)      55959        787%
Circles (filled)         24377        551%
Circles (outline)        45470        446%
Triangles (outline)      24492        451%
Triangles (filled)       31716        839%
Rounded rects (outline)  18054        479%
Rounded rects (filled)   60926        751%
Done!

*/

// ------------------------------------------------

void loop(void) 
{
}

// ------------------------------------------------

unsigned long testFillScreen() {
  unsigned long start = micros();
  tft.fillScreen(BLACK);
  tft.fillScreen(RED);
  tft.fillScreen(GREEN);
  tft.fillScreen(BLUE);
  tft.fillScreen(BLACK);
  return micros() - start;
}

// ------------------------------------------------
unsigned long testText() {
  tft.fillScreen(BLACK);
  unsigned long start = micros();
  tft.setCursor(0, 0);
  tft.setTextColor(WHITE);  tft.setTextSize(1);
  tft.println("Hello World!");
  tft.setTextColor(YELLOW); tft.setTextSize(2);
  tft.println(1234.56);
  tft.setTextColor(RED);    tft.setTextSize(3);
  tft.println(0xDEADBEEF, HEX);
  tft.println();
  tft.setTextColor(GREEN);
  tft.setTextSize(5);
  tft.println("Groop");
  tft.setTextSize(2);
  tft.println("I implore thee,");
  tft.setTextSize(1);
  tft.println("my foonting turlingdromes.");
  tft.println("And hooptiously drangle me");
  tft.println("with crinkly bindlewurdles,");
  tft.println("Or I will rend thee");
  tft.println("in the gobberwarts");
  tft.println("with my blurglecruncheon,");
  tft.println("see if I don't!");
  return micros() - start;
}

// ------------------------------------------------
unsigned long testLines(uint16_t color) {
  unsigned long start, t;
  int           x1, y1, x2, y2,
                w = tft.width(),
                h = tft.height();

  tft.fillScreen(BLACK);

  x1 = y1 = 0;
  y2    = h - 1;
  start = micros();
  for(x2=0; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
  x2    = w - 1;
  for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);
  t     = micros() - start; // fillScreen doesn't count against timing

  tft.fillScreen(BLACK);

  x1    = w - 1;
  y1    = 0;
  y2    = h - 1;
  start = micros();
  for(x2=0; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
  x2    = 0;
  for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);
  t    += micros() - start;

  tft.fillScreen(BLACK);

  x1    = 0;
  y1    = h - 1;
  y2    = 0;
  start = micros();
  for(x2=0; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
  x2    = w - 1;
  for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);
  t    += micros() - start;

  tft.fillScreen(BLACK);

  x1    = w - 1;
  y1    = h - 1;
  y2    = 0;
  start = micros();
  for(x2=0; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
  x2    = 0;
  for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);

  return micros() - start;
}

// ------------------------------------------------
unsigned long testFastLines(uint16_t color1, uint16_t color2) {
  unsigned long start;
  int           x, y, w = tft.width(), h = tft.height();

  tft.fillScreen(BLACK);
  start = micros();
  for(y=0; y<h; y+=5) tft.drawFastHLine(0, y, w, color1);
  for(x=0; x<w; x+=5) tft.drawFastVLine(x, 0, h, color2);

  return micros() - start;
}

// ------------------------------------------------
unsigned long testRects(uint16_t color) {
  unsigned long start;
  int           n, i, i2,
                cx = tft.width()  / 2,
                cy = tft.height() / 2;

  tft.fillScreen(BLACK);
  n     = min(tft.width(), tft.height());
  start = micros();
  for(i=2; i<n; i+=6) {
    i2 = i / 2;
    tft.drawRect(cx-i2, cy-i2, i, i, color);
  }

  return micros() - start;
}

// ------------------------------------------------
unsigned long testFilledRects(uint16_t color1, uint16_t color2) {
  unsigned long start, t = 0;
  int           n, i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;

  tft.fillScreen(BLACK);
  n = min(tft.width(), tft.height());
  for(i=n; i>0; i-=6) {
    i2    = i / 2;
    start = micros();
    tft.fillRect(cx-i2, cy-i2, i, i, color1);
    t    += micros() - start;
    // Outlines are not included in timing results
    tft.drawRect(cx-i2, cy-i2, i, i, color2);
  }

  return t;
}

// ------------------------------------------------
unsigned long testFilledCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int x, y, w = tft.width(), h = tft.height(), r2 = radius * 2;

  tft.fillScreen(BLACK);
  start = micros();
  for(x=radius; x<w; x+=r2) {
    for(y=radius; y<h; y+=r2) {
      tft.fillCircle(x, y, radius, color);
    }
  }

  return micros() - start;
}

// ------------------------------------------------
unsigned long testCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int           x, y, r2 = radius * 2,
                w = tft.width()  + radius,
                h = tft.height() + radius;

  // Screen is not cleared for this one -- this is
  // intentional and does not affect the reported time.
  start = micros();
  for(x=0; x<w; x+=r2) {
    for(y=0; y<h; y+=r2) {
      tft.drawCircle(x, y, radius, color);
    }
  }

  return micros() - start;
}

// ------------------------------------------------
unsigned long testTriangles() {
  unsigned long start;
  int           n, i, cx = tft.width()  / 2 - 1,
                      cy = tft.height() / 2 - 1;

  tft.fillScreen(BLACK);
  n     = min(cx, cy);
  start = micros();
  for(i=0; i<n; i+=5) {
    tft.drawTriangle(
      cx    , cy - i, // peak
      cx - i, cy + i, // bottom left
      cx + i, cy + i, // bottom right
      RGBto565(0, 0, i));
  }

  return micros() - start;
}

// ------------------------------------------------
unsigned long testFilledTriangles() {
  unsigned long start, t = 0;
  int           i, cx = tft.width()  / 2 - 1,
                   cy = tft.height() / 2 - 1;

  tft.fillScreen(BLACK);
  start = micros();
  for(i=min(cx,cy); i>10; i-=5) {
    start = micros();
    tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      RGBto565(0, i, i));
    t += micros() - start;
    tft.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      RGBto565(i, i, 0));
  }

  return t;
}

// ------------------------------------------------
unsigned long testRoundRects() {
  unsigned long start;
  int           w, i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;

  tft.fillScreen(BLACK);
  w     = min(tft.width(), tft.height());
  start = micros();
  for(i=0; i<w; i+=6) {
    i2 = i / 2;
    tft.drawRoundRect(cx-i2, cy-i2, i, i, i/8, RGBto565(i, 0, 0));
  }

  return micros() - start;
}

// ------------------------------------------------
unsigned long testFilledRoundRects() {
  unsigned long start;
  int           i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;

  tft.fillScreen(BLACK);
  start = micros();
  for(i=min(tft.width(), tft.height()); i>20; i-=6) {
    i2 = i / 2;
    tft.fillRoundRect(cx-i2, cy-i2, i, i, i/8, RGBto565(0, i, 0));
  }

  return micros() - start;
}
// ------------------------------------------------

