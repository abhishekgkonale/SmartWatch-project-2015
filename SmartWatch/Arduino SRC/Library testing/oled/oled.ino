#include <U8glib.h>



#include "bitmap.h"


U8GLIB_SSD1306_128X64_2X u8g (12,11,10,9,8);


void setup() {
  // put your setup code here, to run once:

 u8g.drawBitmapP( 0, 0, 2,16, ICON_BITMAP_4);

}

void loop() {
  // put your main code here, to run repeatedly:
 
 
}


