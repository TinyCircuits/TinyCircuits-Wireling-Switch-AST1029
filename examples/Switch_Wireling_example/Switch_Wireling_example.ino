/*
  TinyCircuits Switch Wireling Example Sketch

  This sketch will indicate if the switch is on or off.

  Written 30 July 2019
  By Hunter Hykes
  Modified N/A
  By N/A

  https://TinyCircuits.com
*/

#if defined (ARDUINO_ARCH_AVR)
#define SerialMonitorInterface Serial
#elif defined(ARDUINO_ARCH_SAMD)
#define SerialMonitorInterface SerialUSB
#endif

#define switchPin A0 // pin corresponds to port (i.e. A0 -> PORT0, A1 -> PORT1, etc.)

void setup() {
  SerialMonitorInterface.begin(9600); // start serial communications at 9600 Baud

  pinMode(switchPin, INPUT);
  
  delay(500);
}

void loop() {
  bool reading = digitalRead(switchPin);

  // NOTE: switch is active low so '0' is ON
  if(reading == 0) {
    SerialMonitorInterface.println("ON");
  } else {
    SerialMonitorInterface.println("OFF");
  }

  delay(1000); // wait 1 second
}
