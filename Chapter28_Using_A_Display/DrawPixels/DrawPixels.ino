// Include the display library
#include <U8glib.h>

// Create new SSD1306 IC2 display with 128x64 resolution
U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);

void setup() {
  
}

void loop() {
  
  // Refresh picture
  oled.firstPage();
  do
  {
    draw();
  } while (oled.nextPage());
  

}
void draw(){

  // Draw pixels - point(x,y)
  oled.drawPixel(11, 44);
  oled.drawPixel(13, 44);

  // Draw lines - line(start-x, start-y, end-x, end-y)
  oled.drawLine(12, 28, 12, 60);
  oled.drawLine(12, 60, 128, 60);
  oled.drawLine(12, 60, 128, 30);

}