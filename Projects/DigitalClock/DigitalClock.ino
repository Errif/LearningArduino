// Include the display library
#include <RtcDS3231.h>
#include <Wire.h> 
#include <U8glib.h>

// Create new SSD1306 IC2 display with 128x64 resolution
U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);

// Create new RTC module object
RtcDS3231<TwoWire> rtcModule(Wire);

// Text
char titleText[] = "My Arduino";

// Create variables for time

int year;
byte month;
int day;
byte hour;
byte minute;
byte second;

void setup() {

}

void loop() {

  // Refresh picture
  oled.firstPage();
  do
  {
    draw();
  } while (oled.nextPage());

  delay(20);
  updateTime();

}

void updateTime(){
  RtcDateTime now = rtcModule.GetDateTime();
  
  year = now.Year();
  month = now.Month();
  day = now.Day();

  hour = now.Hour();
  minute = now.Minute();
  second = now.Second();
}

void draw() {


  // Set font to Helvetica size 10
  oled.setFont(u8g_font_helvB12);

  // Calculate starting position to center text
  int titleX = (oled.getWidth() - oled.getStrWidth(titleText)) / 2;

  // Print title 
  oled.drawStr(titleX, 13, "My Arduino");

  // Set font to Helvetica size 10
  oled.setFont(u8g_font_helvB10);

  // Display date
  char dateString[20];
  sprintf(dateString, "Date: %04u-%02u-%02u", year, month, day);

  oled.drawStr(0, 36, dateString);

  // Display time
  char timeString[20];
  sprintf(timeString, "Time: %02u:%02u:%02u", hour, minute, second);

  oled.drawStr(0, 56, timeString);

}
