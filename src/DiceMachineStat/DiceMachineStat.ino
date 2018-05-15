#include <SPI.h>


//https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_GFX.h>
//https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library
#include <Adafruit_PCD8544.h>



int8_t BUTTON_PIN = 12;

int8_t SCREEN_BACK_LIGHT = 8;

int8_t SCREEN_PIN_SCLK = 7;
int8_t SCREEN_PIN_DIN = 6;
int8_t SCREEN_PIN_DC = 5;
int8_t SCREEN_PIN_RST = 4;

Adafruit_PCD8544 display = Adafruit_PCD8544(SCREEN_PIN_SCLK, SCREEN_PIN_DIN, SCREEN_PIN_DC, SCREEN_PIN_RST);



// display: 84x48. non-square pixels (ratio ~1.2)
static const uint16_t SCREEN_WIDTH = 84;
static const uint16_t SCREEN_HEIGHT = 48;
static const uint16_t DICE_WIDTH = 36;
static const uint16_t DICE_HEIGHT = 30;
static const uint16_t DICE_CORNER = 5;
static const uint16_t DOT_WIDTH = 6;
static const uint16_t DOT_HEIGHT = 5;

static const uint16_t LIGHT_ON_milliseconds = 3000;



class Die {
  
private:  
  uint8_t m_x;
  uint8_t m_y;
  uint8_t m_w;
  uint8_t m_h;
  uint8_t m_centerX;
  uint8_t m_centerY;
  
  uint8_t m_frame_x[8];
  uint8_t m_frame_y[8];
  
public:
  Die(uint8_t x, uint8_t y, uint8_t w, uint8_t h) 
    : m_x(x), m_y(y), m_w(w), m_h(h), m_centerX(m_x+m_w/2), m_centerY(m_y+m_h/2)
  {
    m_frame_x[0] = x+DICE_CORNER;
    m_frame_y[0] = y;
    m_frame_x[1] = x+w-DICE_CORNER;
    m_frame_y[1] = y;
    m_frame_x[2] = x+w;
    m_frame_y[2] = y+DICE_CORNER;
    m_frame_x[3] = x+w;
    m_frame_y[3] = y+h-DICE_CORNER;
    m_frame_x[4] = x+w-DICE_CORNER;
    m_frame_y[4] = y+h;
    m_frame_x[5] = x+DICE_CORNER;
    m_frame_y[5] = y+h;
    m_frame_x[6] = x;
    m_frame_y[6] = y+h-DICE_CORNER;
    m_frame_x[7] = x;
    m_frame_y[7] = y+DICE_CORNER;
  }
  
  void draw(uint8_t number) {
    drawFrame();
    drawFace(number);
  }
  
private:
  
  void drawFrame() {
    for (uint8_t i=0; i<8; i++) {
      int8_t x1 = m_frame_x[i];
      int8_t y1 = m_frame_y[i];
      int8_t x2 = m_frame_x[(i+1)%8];
      int8_t y2 = m_frame_y[(i+1)%8];
      display.drawLine(x1-1, y1-1, x2-1, y2-1, BLACK);    
      display.drawLine(x1, y1, x2, y2, BLACK);    
      display.drawLine(x1+1, y1+1, x2+1, y2+1, BLACK);    
    }
  }
  
  
  
  void drawFace(uint8_t number) {
    
    int8_t dW = m_w/2;
    int8_t dX_25 = dW - m_w / 4;
    int8_t dX_33 = dW - m_w / 3;
    
    int8_t dH = m_h/2;
    int8_t dY_25 = dH - m_h / 4;
    int8_t dY_33 = dH - m_h / 3;

    switch (number) {
      case 1:
        drawDot(0, 0);
        break;
      case 2:
        drawDot(-dX_33,  dY_33);
        drawDot( dX_33, -dY_33);
        break;
      case 3:
        drawDot(-dX_25,  dY_25);
        drawDot( 0,      0);
        drawDot( dX_25, -dY_25);
        break;
      case 4:
        drawDot(-dX_33, -dY_33);
        drawDot( dX_33, -dY_33);
        drawDot(-dX_33,  dY_33);
        drawDot( dX_33,  dY_33);
        break;
      case 5:
        drawDot(-dX_25, -dY_25);
        drawDot( dX_25, -dY_25);
        drawDot( 0,      0);
        drawDot(-dX_25,  dY_25);
        drawDot( dX_25,  dY_25);
        break;
      case 6:
        drawDot(-dX_33, -dY_25);
        drawDot( dX_33, -dY_25);
        drawDot(-dX_33,  0);
        drawDot( dX_33,  0);
        drawDot(-dX_33,  dY_25);
        drawDot( dX_33,  dY_25);
        break;
    }
  }
  
  
  void drawDot(int8_t dX, int8_t dY) {
    uint8_t displaceX = DOT_WIDTH/2;
    uint8_t displaceY = DOT_HEIGHT/2;

    display.fillRect(
      m_centerX + dX - displaceX,
      m_centerY + dY - displaceY,
      DOT_WIDTH,
      DOT_HEIGHT,
      BLACK);
  }
  
  

  
};





Die die_1(1, (SCREEN_HEIGHT-DICE_HEIGHT)/2, DICE_WIDTH, DICE_HEIGHT);
Die die_2(SCREEN_WIDTH - 2 - DICE_WIDTH, (SCREEN_HEIGHT-DICE_HEIGHT)/2, DICE_WIDTH, DICE_HEIGHT);
uint8_t die_1_last = 0;
uint8_t die_2_last = 0;




void initRandomSeed() {
  randomSeed(millis() + random());
}


void roll() {
  display.clearDisplay();
  die_1_last = random(6);
  die_2_last = random(6);
  die_1.draw(die_1_last + 1);
  die_2.draw(die_2_last + 1);
  display.display();
}



uint32_t backLightOnTimestamp = 0;


void backLightOn() {
  backLightOnTimestamp = millis();
  digitalWrite(SCREEN_BACK_LIGHT, HIGH);
}

void checkBackLighthStatus() {
  if (backLightOnTimestamp + LIGHT_ON_milliseconds < millis()) {
    digitalWrite(SCREEN_BACK_LIGHT, LOW);
  }  
}




void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(SCREEN_BACK_LIGHT, OUTPUT);
  digitalWrite(BUTTON_PIN, HIGH);
  display.begin();
  display.setContrast(100);

  digitalWrite(SCREEN_BACK_LIGHT, LOW);

  initRandomSeed();

  roll();
}




bool isPreviousButtonStatusPressed = false;


void loop() {
  bool isCurrentButtonStatusPressed = !digitalRead(BUTTON_PIN);

  if (isCurrentButtonStatusPressed) {
    if (!isPreviousButtonStatusPressed) {
      initRandomSeed();
    }
    roll();
    updateStat();
    backLightOn();
    delay(50);
  } else {
    if (isPreviousButtonStatusPressed) {
      roll(); // one last roll when button is released
      updateStat();
      displayStat();
    }
  }

  isPreviousButtonStatusPressed = isCurrentButtonStatusPressed;
  //checkBackLighthStatus();
}





uint16_t rollCount = 0;
uint16_t die1Stat[6] = {0,0,0,0,0,0};
uint16_t die2Stat[6] = {0,0,0,0,0,0};
uint16_t diceSum[11] = {0,0,0,0,0,0,0,0,0,0,0};
uint8_t mode = 0;

void updateStat() {
  rollCount++;
  die1Stat[die_1_last]++;
  die2Stat[die_2_last]++;
  diceSum[die_1_last + die_2_last]++;
}

void displayStat() {
  display.clearDisplay();
  
  display.setRotation(1);
  display.setTextColor(WHITE, BLACK);  
  display.fillRect(0, 0, 48, 9, BLACK);
  display.setCursor(2, 1);
  display.print(rollCount);
  display.setCursor(30, 1);
  display.print(die_1_last+1);
  display.setCursor(41, 1);
  display.print(die_2_last+1);
  
  display.setRotation(0);
  display.setTextColor(BLACK, WHITE);

  if (mode == 0) {
    diceStat();
  } else if (mode == 1) {
    drawGraph(die1Stat, 6, 20);
    drawGraph(die2Stat, 6, 53);
  } else if (mode == 2) {
    sumStat();
  } else if (mode == 3) {
    drawGraph(diceSum, 11, 25);
  }

  mode++;
  if (mode>3) mode = 0;
  display.display();
}

void diceStat() {
  
  for (int i=0; i<6; i++) {
    display.setCursor(15, i*8);
    display.print(i+1);
    display.print(":");
    display.print(die1Stat[i]);

    display.setCursor(50, i*8);
    display.print(i+1);
    display.print(":");
    display.print(die2Stat[i]);
  }
 
}


void sumStat() {  
  for (int i=0; i<11; i++) {
    display.setCursor(15+(i>5?35:0), (i%6)*8);
    display.print(((i+2)%10));
    display.print(":");
    display.print(diceSum[i]);
  }
}


const uint16_t s = 2;
const uint16_t maxH = 48;

void drawGraph(uint16_t data[], uint8_t cnt, uint8_t x) {
  uint16_t maxVal = 1;
  for (uint8_t i=0; i<cnt; i++) {
    if (data[i] > maxVal) maxVal = data[i];
  }

  for (uint8_t i=0; i<cnt; i++) {
    uint16_t w = maxVal < maxH ?
      data[i] :
      (((float)(data[i])) / ((float)maxVal)) * maxH; 

    display.fillRect(x+i*(s+2), display.height() - w, s, w, BLACK);
  }
}











