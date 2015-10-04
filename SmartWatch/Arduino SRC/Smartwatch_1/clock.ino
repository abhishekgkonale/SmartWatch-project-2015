#include <Time.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


//Hacktronics OLED 128*64
// If using software SPI (the default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

/* Uncomment this block to use hardware SPI
#define OLED_DC     6
#define OLED_CS     7
#define OLED_RESET  8
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);
*/

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

//time related variables
int Seconds=0;
int Minutes=0;
int Hours_24=0;
int Hours_12=1;
bool AM_PM=false; //true-AM ,false-PM
int Day=1;// days mapped to 1-7
int Alarm_hour=0;
int Alarm_minute=0;

//bitmap images
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };
  
  



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
    cli();//stop interrupts
   //arduino pro mini 3.3 v -8Mhz
   //clock 1 at 1hz
    TCCR1A = 0;        // set entire TCCR1A register to 0
    TCCR1B = 1<<CS12 | 0<<CS11 | 0<<CS10;     //256 prescaler
    TCNT1=34285; //8 Mhz
    //TCNT1=0x0bdb;  //16 Mhz
    
    TIMSK1 |= (1 << OCIE1A);
    
    sei();//allow interrupts
    
    // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  // init done
  
  
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();
  
  

    

}

void loop() {
  // put your main code here, to run repeatedly:

}


ISR(TIMER1_COMPA_vect){
  TCNT1=34285; 
  //TCNT1=0x0bdb;
 
  
  Seconds+=1;
  
  if(Seconds>59)
    { Seconds=0;
      Minutes+=1;
    
      if(Minutes>59)
       {
        Minutes=0;
        Hours_24+=1;
        Hours_12+=1;
        
        if(Hours_24>23)
         {
         Hours_24=0;
         Day+=1;
         if(Day>7)
           {Day=0;
           }
         }
         
         if(Hours_12>11)
         {  if(AM_PM==true)
              {AM_PM=false;
              }
            
            else if(AM_PM==false)
              {AM_PM=true;
              }
          
         }
         
         if(Hours_12>12)
           {
            Hours_12=1;
            
           }
       }
     }
     
     Serial.print(Seconds);
     Serial.print(Minutes);
     Serial.print(Hours_24);
     Serial.println(Day);
}

