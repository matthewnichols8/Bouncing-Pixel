#include <Arduino_LED_Matrix.h>

int dt = 50;
ArduinoLEDMatrix matrix;
int br = 1000000;
int xPos = 3;
int yPos = 2;
int deltaX = 1;
int deltaY = 1;

byte frame[8][12] = {
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0}
};

void setup() {
  // put your setup code here, to run once:
    matrix.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
    if(yPos == 7)
    {
      deltaY = -1;
    }
    if(yPos == 0)
    {
      deltaY = 1;
    }
    if(xPos == 11)
    {
      deltaX = -1;
    }
    if(xPos == 0)
    {
      deltaX = 1;
    }

    frame[yPos][xPos] = 0;
    yPos += deltaY;
    xPos += deltaX;
    frame[yPos][xPos] = 1;
    matrix.renderBitmap(frame, 8, 12); //Render on LEDS
    delay(dt);

}
