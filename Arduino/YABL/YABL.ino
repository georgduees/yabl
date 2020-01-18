#include <DigiCDC.h>
#include <cRGB.h>
#include <WS2812.h>
WS2812 LED(1); // 1 LED
cRGB value;
void setup() {
  SerialUSB.begin();
  LED.setOutput(0);
  SerialUSB.delay(1000);
  value.g=255;
}
void loop() {
  if (SerialUSB.available()) {
    char buf[6];
    char input = SerialUSB.read();
    if (input == '#') {
      SerialUSB.delay(5); // Wait 500 ms
      buf[0] = SerialUSB.read();
      SerialUSB.delay(5); // Wait 500 ms
      buf[1] = SerialUSB.read();
      SerialUSB.delay(5); // Wait 500 ms
      buf[2] = SerialUSB.read();
      SerialUSB.delay(5); // Wait 500 ms
      buf[3] = SerialUSB.read();
      SerialUSB.delay(5); // Wait 500 ms
      buf[4] = SerialUSB.read();
      SerialUSB.delay(5); // Wait 500 ms
      buf[5] = SerialUSB.read();
      SerialUSB.delay(5); // Wait 500 ms
      buf[6] = SerialUSB.read();
      SerialUSB.delay(5); // Wait 500 ms
       
      char red[5] = {0};
      char green[5] = {0};
      char blue[5] = {0};
      red[0] = green[0] = blue[0] = '0';
      red[1] = green[1] = blue[1] = 'X';
      red[2] = buf[1];
      red[3] = buf[2];
      green[2] = buf[3];
      green[3] = buf[4];
      blue[2] = buf[5];
      blue[3] = buf[6];
      SerialUSB.delay(4); // Wait 500 ms
      value.r = strtol(red, NULL, 16);
      value.g= strtol(green, NULL, 16);
      value.b = strtol(blue, NULL, 16);
      SerialUSB.delay(4); // Wait 500 ms
      memset(buf,0,sizeof(buf));
    }
  }
      LED.set_crgb_at(0, value); // Set value at LED found at index 0
      LED.sync(); // Sends the value to the LED
      SerialUSB.delay(10); // Wait 500 ms
}
