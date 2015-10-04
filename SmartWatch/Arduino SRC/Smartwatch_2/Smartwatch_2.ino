
#include <U8glib.h>
#include <SoftwareSerial.h>
#include <TimeAlarms.h>
#include <Time.h>
#include "bitmap.h" //Includes all images


/////////////////////////////////////////////////////////////
//OLED,BLE instance

U8GLIB_SSD1306_128X64_2X u8g (12,11,10,9,8);// 128*64 OLED pins SCK,MOSI,CS,A0 
SoftwareSerial BLE (2,3); //HM10 BLE 4.0


///////////////////////////////////////////////////////////////
//Bluetooth communication commands,transaction details





///////////////////////////////////////////////////////////////


int button_1 = 5;
int button_2 = 6;
int button_3 = 7;



//////////////////////////////////////////////////////////
//setup

void setup() {
  // put your setup code here, to run once:
 BLE.begin(9600);//BLE 4.0 init
 
 pinMode(button_1,INPUT);//UI buttons pins 5,6,7
 pinMode(button_2,INPUT);
 pinMode(button_3,INPUT);
 
 drawLOGO();
 
 drawStartscreen();
 

}

/////////////////////////////////////////////////////////////

//loop

void loop() {
  // put your main code here, to run repeatedly:
   
 
}

///////////////////////////////////////////////////////////////

//serialEvent

void serialEvent()
{

}

//////////////////////////////////////////////////////////////

void drawStartscreen()
{

}
 
void drawLOGO ()
{
}

