# 1 "c:\\Users\\Edvin\\OneDrive\\Programmering\\Arduino\\LearningArduino\\Chapter28_Using_A_Display\\DrawText\\DrawText.ino"
# 1 "c:\\Users\\Edvin\\OneDrive\\Programmering\\Arduino\\LearningArduino\\Chapter28_Using_A_Display\\DrawText\\DrawText.ino"
// Include the display library
# 3 "c:\\Users\\Edvin\\OneDrive\\Programmering\\Arduino\\LearningArduino\\Chapter28_Using_A_Display\\DrawText\\DrawText.ino" 2

// Create new SSD1306 IC2 display with 128x64 resolution
U8GLIB_SSD1306_128X64 oled(0);

// Text
char titleText[] = "My Arduino";

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
void draw() {


  // Set font to Helvetica size 10
  oled.setFont(u8g_font_helvB12);

  // Calculate starting position to center text
  int titleX = (oled.getWidth() - oled.getStrWidth(titleText)) / 2;

  // Print title 
  oled.drawStr(titleX, 13, "My Arduino");

  // Set font to Helvetica size 10
  oled.setFont(u8g_font_helvB10);

  // Print text
  oled.drawStr(0, 36, "Date: 2019-07-25");

  char timeString[20];
  sprintf(timeString, "Duration: %d s", millis()/1000);

  oled.drawStr(0, 56, timeString);


}
