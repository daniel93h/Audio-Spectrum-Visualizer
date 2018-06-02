/*
AudioVisualizer
by;
Daniel Harjuniemi
Mattias Bälter
Petter Zethelius
Christopher Edberg
*/

#include<LedControl.h>

//connections of the MAX7219
int DIN = 12;
int CS = 11;
int CLK = 10;

//globals

//analog ins
int lowIn = 0;
int midLowIn = 1;
int midHighIn = 2;
int highIn = 3;

//initiations for the loop
int readLow;
int readMidLow;
int readMidHigh;
int readHigh;

//Arrays for different figures.
byte smile[8]= {0x30,0x63,0xC3,0xD8,0xD8,0xC3,0x63,0x30}; //{0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};
byte ten[8]= {0x00,0x02,0xFF,0x00,0x7E,0x81,0x81,0x7E};
byte nine[8]={0x00,0x00,0x00,0x4E,0x91,0x91,0x7E,0x00};
byte eight[8]={0x00,0x00,0x00,0x76,0x89,0x89,0x76,0x00};
byte seven[8]={0x00,0x00,0x00,0x01,0xE1,0x1D,0x03,0x00};
byte six[8]={0x00,0x00,0x00,0x7E,0x89,0x89,0x72,0x00};
byte five[8]={0x00,0x00,0x00,0x4F,0x89,0x89,0x71,0x00};
byte four[8]={0x00,0x00,0x10,0x18,0x14,0x12,0xFF,0x00};
byte three[8]={0x00,0x00,0x00,0x42,0x81,0x89,0x76,0x00};
byte two[8]={0x00,0x00,0x00,0xC2,0xA1,0x91,0x8E,0x00};
byte one[8]={0x00,0x00,0x00,0x00,0x82,0xFF,0x80,0x00};
byte zero[8]={0x00,0x00,0x00,0x7E,0x81,0x81,0x7E,0x00};






LedControl lc = LedControl(DIN, CLK, CS, 0);

//An array for setRow (10000000,11000000,11100000,11110000,11111000,11111100,11111110,11111111)
byte row[]=
{
  0x80,
  0xC0,
  0xE0,
  0xF0,
  0xF8,
  0xFC,
  0xFE,
  0xFF
};


//Only happens once
void setup() {
    
    analogReference(DEFAULT);
  
    lc.shutdown(0,false);  //the MAX72XX is in power-saving mode on startup
    lc.setIntensity(0,15); //set the brightness to maximum
    lc.clearDisplay(0);    //clear the display

    //print a countdown on startup
    printByte(ten);
    delay(1500);
    printByte(nine);
    delay(1500);
    printByte(eight);
    delay(1500);
    printByte(seven);
    delay(1500);
    printByte(six);
    delay(1500);
    printByte(five);
    delay(1500);
    printByte(four);
    delay(1500);
    printByte(three);
    delay(1500);
    printByte(two);
    delay(1500);
    printByte(one);
    delay(1500);
    printByte(zero);
    delay(1500);



}
//main loop
void loop() {



    //read analogs
    
    readLow = analogRead(lowIn);
    readMidLow = analogRead(midLowIn);
    readMidHigh = analogRead(midHighIn);
    readHigh = analogRead(highIn);
    
    //contrain values
    readLow = constrain(readLow, 20, 580);
    readMidLow = constrain(readMidLow, 20, 580);
    readMidHigh = constrain(readMidHigh, 20, 580);
    readHigh = constrain(readHigh, 20, 580);


    //set rows 0 and 1 according to lowIn
    if(readLow <= 20)
    {
      lc.setRow(0,0,row[0]);
      lc.setRow(0,1,row[0]);
    }
    else if(readLow > 20 && readLow <= 100)
    {
      lc.setRow(0,0,row[1]);
      lc.setRow(0,1,row[1]);
    }
    else if(readLow > 100 && readLow <= 180)
    {
      lc.setRow(0,0,row[2]);
      lc.setRow(0,1,row[2]);
    }
    else if(readLow > 180 && readLow <= 260)
    {
      lc.setRow(0,0,row[3]);
      lc.setRow(0,1,row[3]);
    }
    else if(readLow > 260 && readLow <= 340)
    {
      lc.setRow(0,0,row[4]);
      lc.setRow(0,1,row[4]);
    }
    else if(readLow > 340 && readLow <= 420)
    {
      lc.setRow(0,0,row[5]);
      lc.setRow(0,1,row[5]);
    }
    else if(readLow > 420 && readLow <= 500)
    {
      lc.setRow(0,0,row[6]);
      lc.setRow(0,1,row[6]);
    }
    else
    {
      lc.setRow(0,0,row[7]);
      lc.setRow(0,1,row[7]);
    }

    
    //set rows 2 and 3 according to midLowIn
    if(readMidLow <= 20){
      lc.setRow(0,2,row[0]);
      lc.setRow(0,3,row[0]);
    }
    else if(readMidLow > 20 && readMidLow <= 100){
      lc.setRow(0,2,row[1]);
      lc.setRow(0,3,row[1]);
    }
    else if(readMidLow > 100 && readMidLow <= 180){
      lc.setRow(0,2,row[2]);
      lc.setRow(0,3,row[2]);
    }
    else if(readMidLow > 180 && readMidLow <= 260){
      lc.setRow(0,2,row[3]);
      lc.setRow(0,3,row[3]);
    }
    else if(readMidLow > 260 && readMidLow <= 340){
      lc.setRow(0,2,row[4]);
      lc.setRow(0,3,row[4]);
    }
    else if(readMidLow > 340 && readMidLow <= 420){
      lc.setRow(0,2,row[5]);
      lc.setRow(0,3,row[5]);
    }
    else if(readMidLow > 420 && readMidLow <= 500){
      lc.setRow(0,2,row[6]);
      lc.setRow(0,3,row[6]);
    }
    else{
      lc.setRow(0,2,row[7]);
      lc.setRow(0,3,row[7]);
    }


    //set rows 4 and 5 according to midHighIn
    if(readMidHigh <= 20){
      lc.setRow(0,4,row[0]);
      lc.setRow(0,5,row[0]);
    }
    else if(readMidHigh > 20 && readMidHigh <= 100){
      lc.setRow(0,4,row[1]);
      lc.setRow(0,5,row[1]);
    }
    else if(readMidHigh > 100 && readMidHigh <= 180){
      lc.setRow(0,4,row[2]);
      lc.setRow(0,5,row[2]);
    }
    else if(readMidHigh > 180 && readMidHigh <= 260){
      lc.setRow(0,4,row[3]);
      lc.setRow(0,5,row[3]);
    }
    else if(readMidHigh > 260 && readMidHigh <= 340){
      lc.setRow(0,4,row[4]);
      lc.setRow(0,5,row[4]);
    }
    else if(readMidHigh > 340 && readMidHigh <= 420){
      lc.setRow(0,4,row[5]);
      lc.setRow(0,5,row[5]);
    }
    else if(readMidHigh > 420 && readMidHigh <= 500){
      lc.setRow(0,4,row[6]);
      lc.setRow(0,5,row[6]);
    }
    else{
      lc.setRow(0,4,row[7]);
      lc.setRow(0,5,row[7]);
    }


    //set rows 6 and 7 according to highIn
    if(readHigh <= 20){
      lc.setRow(0,6,row[0]);
      lc.setRow(0,7,row[0]);
    }
    else if(readHigh > 20 && readHigh <= 100){
      lc.setRow(0,6,row[1]);
      lc.setRow(0,7,row[1]);
    }
    else if(readHigh > 100 && readHigh <= 180){
      lc.setRow(0,6,row[2]);
      lc.setRow(0,7,row[2]);
    }
    else if(readHigh > 180 && readHigh <= 260){
      lc.setRow(0,6,row[3]);
      lc.setRow(0,7,row[3]);
    }
    else if(readHigh > 260 && readHigh <= 340){
      lc.setRow(0,6,row[4]);
      lc.setRow(0,7,row[4]);
    }
    else if(readHigh > 340 && readHigh <= 420){
      lc.setRow(0,6,row[5]);
      lc.setRow(0,7,row[5]);
    }
    else if(readHigh > 420 && readHigh <= 500){
      lc.setRow(0,6,row[6]);
      lc.setRow(0,7,row[6]);
    }
    else{
      lc.setRow(0,6,row[7]);
      lc.setRow(0,7,row[7]);
    }


  delay(1);
}

//prints an image
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}


