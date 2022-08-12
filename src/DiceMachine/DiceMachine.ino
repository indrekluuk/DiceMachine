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

static const uint16_t LIGHT_ON_milliseconds = 10000;
static const uint16_t ROLL_TIMEOUT_milliseconds = 500;
static const uint16_t STAT_milliseconds = 3000;


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





Die die_1(1, (SCREEN_HEIGHT-DICE_HEIGHT)/2 - 4, DICE_WIDTH, DICE_HEIGHT);
Die die_2(SCREEN_WIDTH - 2 - DICE_WIDTH, (SCREEN_HEIGHT-DICE_HEIGHT)/2 - 4, DICE_WIDTH, DICE_HEIGHT);

uint8_t rolledDie1Number = 0;
uint8_t rolledDie2Number = 0;

long buttonPressedTimer = 0;
long buttonReleaseTimer = 0;
long backLightOnTimer = 0;

uint16_t rollCount = 0;
uint16_t die1Stat[6] = {0,0,0,0,0,0};
uint16_t die2Stat[6] = {0,0,0,0,0,0};
uint16_t diceSum[11] = {0,0,0,0,0,0,0,0,0,0,0};



void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(SCREEN_BACK_LIGHT, OUTPUT);
  digitalWrite(BUTTON_PIN, HIGH);
  display.begin();
  display.setContrast(50);

  digitalWrite(SCREEN_BACK_LIGHT, LOW);

  initRandomSeed();
  drawDice(roll(), roll(), true);
}



void loop() {

  if (isButtonDown()) {
    if (!buttonPressedTimer) {
      initRandomSeed();
      // Decided the roll after first press so drawing doesn't affect the result.
      rolledDie1Number = roll();
      rolledDie2Number = roll();
      buttonPressedTimer = millis();
    }
    buttonReleaseTimer = millis();
  }

  if (buttonPressedTimer) {
    bool showStat = (millis() - buttonPressedTimer) > STAT_milliseconds;

    if (showStat) {
      displayStat();
    } else {
      backLightOn();
      drawDice(roll(), roll(), false);
      delay(50);     
    }

    if ((millis() - buttonReleaseTimer) > ROLL_TIMEOUT_milliseconds) {
      buttonPressedTimer = 0;
      if (!showStat) {
        recordStat(rolledDie1Number, rolledDie2Number);
        drawDice(rolledDie1Number, rolledDie2Number, true);        
      }
    }    
  }
  
  checkBackLighthStatus();
}

bool isButtonDown() {
  return !digitalRead(BUTTON_PIN);
}





void initRandomSeed() {
  randomSeed(millis() + random());
}


uint8_t roll() {
  return random(6)+1;
}

void recordStat(uint8_t die1Number, uint8_t die2Number) {
  rollCount++;
  die1Stat[die1Number - 1]++;
  die2Stat[die2Number - 1]++;
  diceSum[(die1Number - 1) + (die2Number - 1)]++;
}


void drawDice(uint8_t die1Number, uint8_t die2Number, bool showSum) {
  display.clearDisplay();
  die_1.draw(die1Number);
  die_2.draw(die2Number);
  if (showSum) {
    uint8_t sum = die1Number + die2Number;
    display.setCursor(40 - (sum > 9 ? 3 : 0), 41);
    display.print(sum);    
  }
  display.display();
}


void displayStat() {
  display.clearDisplay();
  
  display.setRotation(1);
  display.setTextColor(WHITE, BLACK);  
  display.fillRect(0, 0, 48, 9, BLACK);
  display.setCursor(2, 1);
  display.print(rollCount);
  
  display.setRotation(0);
  display.setTextColor(BLACK, WHITE);
  /*
  die1Stat[0] = 100;
  die2Stat[0] = 70;
  diceSum[0] = 150;
  diceSum[10] = 150;
  */
  

  uint8_t graphH = display.height() / 2;

  uint16_t die1MaxRolls = getMaxRolls(die1Stat, 6);
  uint16_t die2MaxRolls = getMaxRolls(die2Stat, 6);
  uint16_t diceMaxRolls = die1MaxRolls > die2MaxRolls ? die1MaxRolls : die2MaxRolls;
  drawGraph(die1Stat, 6, 20, graphH - 1, diceMaxRolls, graphH - 1);
  drawGraph(die2Stat, 6, 52, graphH - 1, diceMaxRolls, graphH - 1);

  uint16_t sumMaxRolls = getMaxRolls(diceSum, 11);
  drawGraph(diceSum, 11, 26, graphH*2, sumMaxRolls, graphH - 1);
  
  display.display();
}


const uint16_t GRAPH_SPACE = 2;

void drawGraph(uint16_t data[], uint8_t cnt, uint8_t x, uint8_t y, uint16_t maxVal, uint16_t maxH) {
  for (uint8_t i=0; i<cnt; i++) {
    uint16_t rolls = maxVal < maxH ?
      data[i] :
      (((float)(data[i])) / ((float)maxVal)) * maxH; 

    if (rolls == 0) {
      rolls = 1;
    }
    display.fillRect(x+i*(GRAPH_SPACE+2), y - rolls, GRAPH_SPACE, rolls, BLACK);  
  }
}

uint16_t getMaxRolls(uint16_t data[], uint8_t cnt) {
  uint16_t maxRolls = 1;
  for (uint8_t i=0; i<cnt; i++) {
    if (data[i] > maxRolls) maxRolls = data[i];
  }
  return maxRolls;
}




void backLightOn() {
  backLightOnTimer = millis();
  digitalWrite(SCREEN_BACK_LIGHT, HIGH);
}

void checkBackLighthStatus() {
  if ((millis() - backLightOnTimer) > LIGHT_ON_milliseconds) {
    digitalWrite(SCREEN_BACK_LIGHT, LOW);
  }  
}
