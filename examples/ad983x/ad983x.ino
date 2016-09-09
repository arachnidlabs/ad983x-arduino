/*
 malcolm@faed.name
  Circuit:
  AD9833 module

  Select Pin D9 - CS - MCP41010 Digial Potentiometer
  Select Pin D10 - FSY - AD9833 DDS
  MOSI: pin D11 - DAT
  MISO: pin D12 - no connection
  SCK: pin D13 - CLK
*/

#include <ad983x.h>

#define DDS_SELECT_PIN 10 // Select Pin - FSY
#define POT_SELECT_PIN 9 // Select Pin - CS

// Initalise the ad983x library
AD983X_SW DDS = AD983X_SW(DDS_SELECT_PIN, 25); // 25MHz oscillator

void setup() {
  // put your setup code here, to run once:

  //pinMode(DDS_SELECT_PIN, OUTPUT); // This is done in the AD983x Library
  pinMode(POT_SELECT_PIN, OUTPUT);

  //digitalWrite(DDS_SELECT_PIN, HIGH);  // This is done in the AD983x Library
  digitalWrite(POT_SELECT_PIN, HIGH);

  // Initalise the ad983x library

  DDS.begin();
  // DDS.setOutputMode(OUTPUT_MODE_SINE);
  // DDS.setSignOutput(SIGN_OUTPUT_NONE); // Default is Sine Wave DAC output.

  DDS.setFrequency(0, 1000L); // Load frequency register 0 with 1000Hz
  DDS.setFrequency(1, 2000L);// Load frequency register 0 with 2000Hz

}
void loop() {
  // put your main code here, to run repeatedly:

  // Toggle between frequencies.
  DDS.selectFrequency(byte(0));

  delay(1000);

  DDS.selectFrequency(byte(1));

  delay(1000);

}
