/*
 This code requires the following libraries:

   - RTClib https://github.com/adafruit/RTClib
   - DST_RTC https://github.com/andydoro/DST_RTC
   - Adafruit_GFX https://github.com/adafruit/Adafruit-GFX-Library
   - Adafruit_NeoPixel https://github.com/adafruit/Adafruit_NeoPixel
   - Adafruit_NeoMatrix https://github.com/adafruit/Adafruit_NeoMatrix

   grid pattern

    I T S H I S T H A L F B R T E N
    F L Q U A R T E R S T W E N T Y
    F I V E F E M I N U T E S S T O
    W P A S T C O N E S T H R E E W
    S T W O V F O U R G H E I G H T
    E L E V E N O T E N T I F I V E
    K N I N E R V S E V E N E S I X
    T W E L V E T S O R C L O C K S

*/

// include the library code:
#include <Wire.h>
#include <RTClib.h>
#include <DST_RTC.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

// define pins
#define NEOPIN 6  // connect to DIN on NeoMatrix 8x8 via a resistor
#define RTCGND A2 // use this as  ground 
#define RTCPWR A3 // use this as  power


RTC_DS1307 RTC; // Establish clock object
DST_RTC dst_rtc; // DST object

DateTime theTime; // Holds current clock time



// configure for 8x8 neopixel matrix
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, NEOPIN,
                            NEO_MATRIX_TOP  + NEO_MATRIX_LEFT +
                            NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
                            NEO_GRB         + NEO_KHZ800);
                            

//array to store if LEDs are lit or not
int ledMatrix[8][8] = {
  {1, 1, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
  };

int ledCount = 64;  // the 8x8 grid of the Neomatrix

void setup() {
  // put your setup code here, to run once:


//Serial for debugging
  Serial.begin(9600);

  // set pinmodes
  pinMode(NEOPIN, OUTPUT);



  // start clock
  Wire.begin();  // Begin I2C
  RTC.begin();   // begin clock
  RTC.adjust(DateTime(__DATE__, __TIME__));



  matrix.begin();
  matrix.setBrightness(100);
  matrix.fillScreen(0); // Initialize all pixels to 'off'
  matrix.show();

  
}

void loop() {
  // put your main code here, to run repeatedly:

  // get the time
  theTime = dst_rtc.calculateTime(RTC.now()); 
  // add 2.5 minutes to get better estimates
  theTime = theTime.unixtime() + 150;



//write 'it is' everytime:
ledMatrix[0][0] = 1;
ledMatrix[0][1] = 1;
ledMatrix[0][0] = 1;





if ((theTime.minute() > 4) && (theTime.minute() < 10)) {
    ledMatrix[2][0] = 1;
    ledMatrix[2][1] = 1;
    ledMatrix[2][2] = 1;
     Serial.print("mfive ");
  }
  if ((theTime.minute() > 9) && (theTime.minute() < 15)) {
    ledMatrix[0][6] = 1;
    ledMatrix[0][7] = 1;
     Serial.print("mten ");
  }
  if ((theTime.minute() > 14) && (theTime.minute() < 20)) {
    ledMatrix[1][0] = 1;
    ledMatrix[1][1] = 1;
    ledMatrix[1][2] = 1;
    ledMatrix[1][3] = 1;
     Serial.print("mquarter ");
  }
  if ((theTime.minute() > 19) && (theTime.minute() < 25)) {
    ledMatrix[1][4] = 1;
    ledMatrix[1][5] = 1;
    ledMatrix[1][6] = 1;
    ledMatrix[1][7] = 1;
     Serial.print("mtwenty ");
  }
  if ((theTime.minute() > 24) && (theTime.minute() < 30)) {
    ledMatrix[1][4] = 1;
    ledMatrix[1][5] = 1;
    ledMatrix[1][6] = 1;
    ledMatrix[1][7] = 1;
    ledMatrix[2][0] = 1;
    ledMatrix[2][1] = 1;
    ledMatrix[2][1] = 1;
     Serial.print("mtwenty five ");
  }
  if ((theTime.minute() > 29) && (theTime.minute() < 35)) {
    ledMatrix[0][3] = 1;
    ledMatrix[0][4] = 1;
    ledMatrix[0][5] = 1;
     Serial.print("mhalf ");
  }
  if ((theTime.minute() > 34) && (theTime.minute() < 40)) {
    ledMatrix[1][4] = 1;
    ledMatrix[1][5] = 1;
    ledMatrix[1][6] = 1;
    ledMatrix[1][7] = 1;
    ledMatrix[2][0] = 1;
    ledMatrix[2][1] = 1;
    ledMatrix[2][1] = 1;
     Serial.print("mtwenty five ");
  }
  if ((theTime.minute() > 39) && (theTime.minute() < 45)) {
    ledMatrix[1][4] = 1;
    ledMatrix[1][5] = 1;
    ledMatrix[1][6] = 1;
    ledMatrix[1][7] = 1;
     Serial.print("mtwenty ");
  }
  if ((theTime.minute() > 44) && (theTime.minute() < 50)) {
    ledMatrix[1][0] = 1;
    ledMatrix[1][1] = 1;
    ledMatrix[1][2] = 1;
    ledMatrix[1][3] = 1;
     Serial.print("mquarter ");
  }
  if ((theTime.minute() > 49) && (theTime.minute() < 55)) {
    ledMatrix[0][6] = 1;
    ledMatrix[0][7] = 1;
     Serial.print("mten");
  }
  if (theTime.minute() > 54) {
    ledMatrix[2][0] = 1;
    ledMatrix[2][1] = 1;
    ledMatrix[2][2] = 1;
     Serial.print("mfive ");
  }


  if ((theTime.minute() < 5))
  {
    switch (theTime.hour()) {
      case 1:
      case 13:
    ledMatrix[3][3] = 1;
    ledMatrix[3][4] = 1;
     Serial.print("hone ");
        break;
      case 2:
      case 14:
    ledMatrix[4][0] = 1;
    ledMatrix[4][1] = 1;
     Serial.print("htwo ");
        break;
      case 3:
      case 15:
    ledMatrix[3][7] = 1;
    ledMatrix[3][6] = 1;
     Serial.print("hthree ");
        break;
      case 4:
      case 16:
    ledMatrix[4][2] = 1;
    ledMatrix[4][3] = 1;
    ledMatrix[4][4] = 1;
     Serial.print("hfour ");
        break;
      case 5:
      case 17:
    ledMatrix[5][6] = 1;
    ledMatrix[5][7] = 1;
     Serial.print("hfive ");
        break;
      case 6:
      case 18:
    ledMatrix[6][6] = 1;
    ledMatrix[6][7] = 1;
     Serial.print("hsix ");
        break;
      case 7:
      case 19:
    ledMatrix[6][3] = 1;
    ledMatrix[6][4] = 1;
    ledMatrix[6][5] = 1;
     Serial.print("hseven ");
        break;
      case 8:
      case 20:
    ledMatrix[4][5] = 1;
    ledMatrix[4][6] = 1;
    ledMatrix[4][7] = 1;
     Serial.print("height ");
        break;
      case 9:
      case 21:
    ledMatrix[6][0] = 1;
    ledMatrix[6][1] = 1;
    ledMatrix[6][2] = 1;
     Serial.print("hnine ");
        break;
      case 10:
      case 22:
    ledMatrix[5][4] = 1;
    ledMatrix[5][5] = 1;
     Serial.print("hten ");
        break;
      case 11:
      case 23:
    ledMatrix[5][0] = 1;
    ledMatrix[5][1] = 1;
    ledMatrix[5][2] = 1;
    ledMatrix[5][3] = 1;
     Serial.print("heleven ");
        break;
      case 0:
      case 12:
    ledMatrix[7][0] = 1;
    ledMatrix[7][1] = 1;
    ledMatrix[7][2] = 1;
    ledMatrix[7][3] = 1;
     Serial.print("htwelve ");
        break;
    }

  }
  else if ((theTime.minute() < 35) && (theTime.minute() > 4))
  {
    ledMatrix[3][0] = 1;
    ledMatrix[3][1] = 1;
    ledMatrix[3][2] = 1;
     Serial.print("past");
   switch (theTime.hour()) {
      case 1:
      case 13:
    ledMatrix[3][3] = 1;
    ledMatrix[3][4] = 1;
     Serial.print("one ");
        break;
      case 2:
      case 14:
    ledMatrix[4][0] = 1;
    ledMatrix[4][1] = 1;
     Serial.print("two ");
        break;
      case 3:
      case 15:
    ledMatrix[3][7] = 1;
    ledMatrix[3][6] = 1;
     Serial.print("three ");
        break;
      case 4:
      case 16:
    ledMatrix[4][2] = 1;
    ledMatrix[4][3] = 1;
    ledMatrix[4][4] = 1;
     Serial.print("four ");
        break;
      case 5:
      case 17:
    ledMatrix[5][6] = 1;
    ledMatrix[5][7] = 1;
     Serial.print("five ");
        break;
      case 6:
      case 18:
    ledMatrix[6][6] = 1;
    ledMatrix[6][7] = 1;
     Serial.print("six ");
        break;
      case 7:
      case 19:
    ledMatrix[6][3] = 1;
    ledMatrix[6][4] = 1;
    ledMatrix[6][5] = 1;
     Serial.print("seven ");
        break;
      case 8:
      case 20:
    ledMatrix[4][5] = 1;
    ledMatrix[4][6] = 1;
    ledMatrix[4][7] = 1;
     Serial.print("eight ");
        break;
      case 9:
      case 21:
    ledMatrix[6][0] = 1;
    ledMatrix[6][1] = 1;
    ledMatrix[6][2] = 1;
     Serial.print("nine ");
        break;
      case 10:
      case 22:
    ledMatrix[5][4] = 1;
    ledMatrix[5][5] = 1;
     Serial.print("ten ");
        break;
      case 11:
      case 23:
    ledMatrix[5][0] = 1;
    ledMatrix[5][1] = 1;
    ledMatrix[5][2] = 1;
    ledMatrix[5][3] = 1;
     Serial.print("eleven ");
        break;
      case 0:
      case 12:
    ledMatrix[7][0] = 1;
    ledMatrix[7][1] = 1;
    ledMatrix[7][2] = 1;
    ledMatrix[7][3] = 1;
     Serial.print("twelve ");
        break;
    }
  }
  else
  {
    // if we are greater than 34 minutes past the hour then display
    // the next hour, as we will be displaying a 'to' sign
    ledMatrix[2][6] = 1;
    ledMatrix[2][7] = 1;
     Serial.print("to ");
    //Serial.print(" to ");
    switch (theTime.hour()) {
      case 1:
      case 13:
    ledMatrix[4][0] = 1;
    ledMatrix[4][1] = 1;
     Serial.print("two ");
        break;
      case 14:
      case 2:
    ledMatrix[3][7] = 1;
    ledMatrix[3][6] = 1;
     Serial.print("three ");
        break;
      case 15:
      case 3:
    ledMatrix[4][2] = 1;
    ledMatrix[4][3] = 1;
    ledMatrix[4][4] = 1;
     Serial.print("four ");
        break;
      case 4:
      case 16:
    ledMatrix[5][6] = 1;
    ledMatrix[5][7] = 1;
     Serial.print("five ");
        break;
      case 5:
      case 17:
    ledMatrix[6][6] = 1;
    ledMatrix[6][7] = 1;
     Serial.print("six ");
        break;
      case 6:
      case 18:
    ledMatrix[6][3] = 1;
    ledMatrix[6][4] = 1;
    ledMatrix[6][5] = 1;
     Serial.print("seven ");
        break;
      case 7:
      case 19:
    ledMatrix[4][5] = 1;
    ledMatrix[4][6] = 1;
    ledMatrix[4][7] = 1;
     Serial.print("eight ");
        break;
      case 8:
      case 20:
    ledMatrix[6][0] = 1;
    ledMatrix[6][1] = 1;
    ledMatrix[6][2] = 1;
     Serial.print("nine ");
        break;
      case 9:
      case 21:
    ledMatrix[5][4] = 1;
    ledMatrix[5][5] = 1;
     Serial.print("ten ");
        break;
      case 10:
      case 22:
    ledMatrix[5][0] = 1;
    ledMatrix[5][1] = 1;
    ledMatrix[5][2] = 1;
    ledMatrix[5][3] = 1;
     Serial.print("eleven ");
        break;
      case 11:
      case 23:
    ledMatrix[7][0] = 1;
    ledMatrix[7][1] = 1;
    ledMatrix[7][2] = 1;
    ledMatrix[7][3] = 1;
     Serial.print("twelve ");
        break;
      case 0:
      case 12:
    ledMatrix[3][3] = 1;
    ledMatrix[3][4] = 1;
     Serial.print("one ");
        break;
    }
  }

//=======================================================
//=======================================================


//it's show time....

for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if (ledMatrix[i][j] == 1) {
        matrix.drawPixel(i, j, matrix.Color(255, 255, 0));
      }
      else {
        matrix.drawPixel(i, j, matrix.Color(0, 0, 0));
      }

    }
    Serial.println();
  }

//====================================================


displayTime();
checkArray();
matrix.show();

delay(5000);
resetArray();

}




void checkArray(){
  //print out the array to check it:
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      Serial.print(ledMatrix[i][j]);
      Serial.print(",");
    }
    Serial.println();
  }
  Serial.println();
}


void resetArray(){
  //set all the array values to 0 (off):
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      ledMatrix[i][j] = 0;
    }
  }
  Serial.print("Array reset (All LEDs switched set to off)");
  Serial.println();
  Serial.println();
}

void displayTime() {

  // get time from the RTC
  DateTime theTime = RTC.now();

  // serial print current time
  
  Serial.print(theTime.year(), DEC);
  Serial.print('/');
  Serial.print(theTime.month(), DEC);
  Serial.print('/');
  Serial.print(theTime.day(), DEC);
  Serial.print(' ');
  Serial.print(theTime.hour(), DEC);
  Serial.print(':');
  Serial.print(theTime.minute(), DEC);
  Serial.print(':');
  Serial.print(theTime.second(), DEC);
  Serial.println();
}
