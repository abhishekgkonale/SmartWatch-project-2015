#include <SoftwareSerial.h>
#include <U8glib.h>
#include <Time.h>
#include <TimeAlarms.h>
#include"bitmap.h";

U8GLIB_SSD1306_128X64_2X u8g(12, 11, 10, 9, 8); // SPI communication: SCK = 12, MOSI = 11, CS = 10, A0 = 9, Reset = 8

int minute_=0;



void setup(void) 
{ //Serial.begin(9600);
  setTime(22,07,30,2,10,2015);
  //Serial.println(weekday());
}



void loop(void) {
  // picture loop
  u8g.firstPage(); 
 if(minute_!=minute()){
  do {
    draw();
  } while( u8g.nextPage() );
 }
  
  // rebuild the picture after some delay
  delay(1000);
}



void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  int hour_12=hourFormat12();
  int hour_24=hour();
  minute_=minute();
  int day_=day();
  int week_day=weekday();
  int month_=month();
  bool AM_PM=isAM();
  
  //u8g.setFontLineSpacingFactor(0.8);
  u8g.setFont(u8g_font_fur35n);
  //u8g.setFont(u8g_font_freedoomr25n);
  u8g.setPrintPos(2,40);
  
    if(hour_12<10)
      {
       u8g.print("0");
       u8g.print(hour_12);
      }
    else 
      {
       u8g.print(hour_12);
      }
  
  
 
    
  u8g.print(":");
  
  if(minute_<10)
    {
     u8g.print("0");
     u8g.print(minute_);
    }
  else
    {
     u8g.print(minute_);
    }
  
  
  u8g.setFont(u8g_font_fub11);
  u8g.setPrintPos(5,60);
  
  if(week_day==1)
    { u8g.print("SUN");
    }
  else if(week_day==2)
    { u8g.print("MON");
    }
  else if(week_day==3)
    { u8g.print("TUE");
    }
  else if(week_day==4)
    { u8g.print("WED");
    } 
  else if(week_day==5)
    { u8g.print("THU");
    }   
  else if(week_day==6)
    { u8g.print("FRI");
    }
  else if(week_day==7)
    { u8g.print("SAT");
    }
  u8g.print("  ");
  u8g.print(day_);
  u8g.print("/");
  u8g.print(month_);
  u8g.print("     ");
  
 
    if(AM_PM==true)
      {
       u8g.print("AM");
      }
    else
      {
       u8g.print("PM");
      }
  
  
   
   
  
  
  
}
