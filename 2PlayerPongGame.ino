#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

byte frame[8][12];
int up1Pin = 2;
int down1Pin = 3;
int up2Pin = 6;
int down2Pin = 7;
int up1, down1, up2, down2;
int p1yPos = 2;
int p2yPos = 2;
int xDel = 1;
int yDel = 1;
int x = 5;
int y = 4;
String winner1 = "  Player 1 WON!";
String winner2 = "  Player 2 WON!";

void setup() {
  pinMode(up1Pin, INPUT);
  pinMode(down1Pin, INPUT);
  pinMode(up2Pin, INPUT);
  pinMode(down2Pin, INPUT);
  Serial.begin(115200);
  matrix.begin();
}

void loop() {

  matrix.beginDraw();
  matrix.textScrollSpeed(50);
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 255, 0, 0);


  up1 = digitalRead(up1Pin);
  down1 = digitalRead(down1Pin);
  up2 = digitalRead(up2Pin);
  down2 = digitalRead(down2Pin);

  if (up1 == 0) {
    p1yPos--;
  } else if (down1 == 0) {
    p1yPos++;
  } else if (up2 == 0) {
    p2yPos--;
  } else if (down2 == 0) {
    p2yPos++;
  }


  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 12; j++) {
      frame[i][j] = 0;


      frame[y][x] = 1;


      if (j == 0) {
        if (p1yPos >= 0 && p1yPos <= 5) {
          for (int t = 0; t <= 2; t++) {
            frame[p1yPos + t][j] = 1;
          }
        } else if (p1yPos < 0) {
          p1yPos = 0;
          for (int t = 0; t <= 2; t++) {
            frame[t][j] = 1;
          }
        } else if (p1yPos > 5) {
          p1yPos = 5;
          for (int t = 0; t <= 2; t++) {
            frame[5 + t][j] = 1;
          }
        }
      }
      if (j == 11) {
        if (p2yPos >= 0 && p2yPos <= 5) {
          for (int t = 0; t <= 2; t++) {
            frame[p2yPos + t][j] = 1;
          }
        } else if (p2yPos < 0) {
          p2yPos = 0;
          for (int t = 0; t <= 2; t++) {
            frame[t][j] = 1;
          }
        } else if (p2yPos > 5) {
          p2yPos = 5;
          for (int t = 0; t <= 2; t++) {
            frame[5 + t][j] = 1;
          }
        }
      }
    }
  }

  if (x == 1 && (y == p1yPos || y == p1yPos + 1 || y == p1yPos + 2)) {
    xDel = -xDel;
  } else if (x < 0) {
    delay(1000);
    matrix.println(winner2);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
    delay(1000);
    x = 5;
    y = 4;
  }



  if (y <= 0 || y >= 7) {
    yDel = -yDel;
  }
  if (x == 10 && (y == p2yPos || y == p2yPos + 1 || y == p2yPos + 2)) {
    xDel = -xDel;

  } else if (x > 11) {
    delay(1000);
    matrix.println(winner1);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
    delay(1000);
    x = 5;
    y = 4;
  }
  x = x + xDel;
  y = y + yDel;



  matrix.renderBitmap(frame, 8, 12);
  delay(150);
}