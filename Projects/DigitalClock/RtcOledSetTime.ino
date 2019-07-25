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