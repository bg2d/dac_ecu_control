#include <Wire.h>
#include <Adafruit_MCP4725.h>

#define ZERO  48
#define ONE   49
#define TWO   50
#define THREE 51
#define FOUR  52
#define FIVE  53
#define NEW_LINE 10

/*  Hex values for DAC control.
 *  The values are computed using 5V reference voltage.
 */
#define VOLT_0 0x000
#define VOLT_1 0x333
#define VOLT_2 0x666
#define VOLT_3 0x999
#define VOLT_4 0xCCC
#define VOLT_5 0xFFF

int g_incoming_byte = 0; // for incoming serial data
Adafruit_MCP4725 dac;
uint32_t dac_val = VOLT_0;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

  dac.begin(0x62);
  dac.setVoltage(dac_val, false);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    g_incoming_byte = Serial.read();

    switch (g_incoming_byte) {
      case ZERO: {
        Serial.print("I received: ");
        Serial.println(g_incoming_byte, DEC);
        Serial.println("Set DAC to 0V");
        
        dac_val = VOLT_0;
        dac.setVoltage(dac_val, false);
        break;
      }
      case ONE: {
        Serial.print("I received: ");
        Serial.println(g_incoming_byte, DEC);
        Serial.println("Set DAC to 1V");
        
        dac_val = VOLT_1;
        dac.setVoltage(dac_val, false);
        break;
      }
      case TWO: {
        Serial.print("I received: ");
        Serial.println(g_incoming_byte, DEC);
        Serial.println("Set DAC to 2V");
        
        dac_val = VOLT_2;
        dac.setVoltage(dac_val, false);
        break;
      }
      case THREE: {
        Serial.print("I received: ");
        Serial.println(g_incoming_byte, DEC);
        Serial.println("Set DAC to 3V");
        
        dac_val = VOLT_3;
        dac.setVoltage(dac_val, false);
        break;
      }
      case FOUR: {
        Serial.print("I received: ");
        Serial.println(g_incoming_byte, DEC);
        Serial.println("Set DAC to 4V");
        
        dac_val = VOLT_4;
        dac.setVoltage(dac_val, false);
        break;
      }
      case FIVE: {
        Serial.print("I received: ");
        Serial.println(g_incoming_byte, DEC);
        Serial.println("Set DAC to 5V");
        
        dac_val = VOLT_5;
        dac.setVoltage(dac_val, false);
        break;
      }
      case NEW_LINE: {
        break;
      }
      default: {
        Serial.print("I received: ");
        Serial.println(g_incoming_byte, DEC);
        Serial.println("Invalid input! Allowed values are: 0, 1, 2, 3, 4 and 5");
        break;
      }
    }
  }
}
