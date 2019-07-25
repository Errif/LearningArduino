# 1 "c:\\Users\\Edvin\\OneDrive\\Programmering\\Arduino\\LearningArduino\\Projects\\DigitalClock\\DigitalClock.ino"
# 1 "c:\\Users\\Edvin\\OneDrive\\Programmering\\Arduino\\LearningArduino\\Projects\\DigitalClock\\DigitalClock.ino"
// Include the display library
# 3 "c:\\Users\\Edvin\\OneDrive\\Programmering\\Arduino\\LearningArduino\\Projects\\DigitalClock\\DigitalClock.ino" 2

// Create new SSD1306 IC2 display with 128x64 resolution
U8GLIB_SSD1306_128X64 oled(0);

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

  delay(20;
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
# 1 "c:\\Users\\Edvin\\OneDrive\\Programmering\\Arduino\\LearningArduino\\Projects\\DigitalClock\\RtcOledSetTime.ino"
/* // Include the libraries

#include <RtcDS3231.h>

#include <Wire.h> 



// Create new RTC module object

RtcDS3231<TwoWire> rtcModule(Wire);



void setup(){



    // Enable I2C communication

    Wire.begin();



    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);

    rtcModule.SetDateTime(compiled);



    Serial.begin(9600);

    Serial.println("## Date and time set ## ");

}



void loop(){



} */
