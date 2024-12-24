#include <Arduino_LED_Matrix.h>

int dt = 50; //Delay time --> 50 m/s
ArduinoLEDMatrix matrix; //Creates matrix object
int br = 1000000; //Broadcast range for Serial Monitor
int xPos = 3;
int yPos = 2;
int deltaX = 1;
int deltaY = 1;

//initialize bitmap
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
    matrix.begin(); //initialize matrix object
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

    frame[yPos][xPos] = 0; //Turns off previous LED
    yPos += deltaY; // Increments Y position
    xPos += deltaX; // Increments X position
    frame[yPos][xPos] = 1; //Turns on LED of new position
    matrix.renderBitmap(frame, 8, 12); //Render on LEDS for the 8x12 Matrix
    delay(dt); //Sets a delay before loop starts again

}
