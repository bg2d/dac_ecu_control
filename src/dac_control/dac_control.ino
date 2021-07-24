#define ZERO  48
#define ONE   49
#define TWO   50
#define THREE 51
#define FOUR  52
#define FIVE  53

int g_incoming_byte = 0; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
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
        break;
      }
      case ONE: {
        Serial.print("I received: ");
        Serial.println(g_incoming_byte, DEC);
        break;
      }
      case TWO: {
        Serial.print("I received: ");
        Serial.println(g_incoming_byte, DEC);
        break;
      }
      case THREE: {
        Serial.print("I received: ");
        Serial.println(g_incoming_byte, DEC);
        break;
      }
      case FOUR: {
        Serial.print("I received: ");
        Serial.println(g_incoming_byte, DEC);
        break;
      }
      case FIVE: {
        Serial.print("I received: ");
        Serial.println(g_incoming_byte, DEC);
        break;
      }
      default: {
        break;
      }
    }
  }
}
