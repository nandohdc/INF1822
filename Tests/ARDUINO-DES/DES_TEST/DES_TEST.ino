#include <DES.h>

/*
   This function encrypts a block of 64 bits (8 bytes) with the DES algorithm.
   Key expansion is done automatically.
   The key is 64 bits long, but note that only 56 bits are used (the LSB of each byte is dropped).
   The input and output blocks may overlap.
   source: http://spaniakos.github.io/ArduinoDES/classDES.html
*/

void DES_test() {
  DES des;
  unsigned long Time_start;
  unsigned long Time_end;
  unsigned long Time_Elapsed;
  int counter;
  byte out[8];
  byte in[] = "JqoejK4V";
  byte key[] = { 0x3b, 0x38, 0x98, 0x37, 0x15, 0x20, 0xf7, 0x5e };

  Serial.println("========= DES test ==========");
  //encrypt
  Serial.println("Encrypt...");
  Time_start = micros();
  for (counter = 0; counter < 100; ++counter) {
    des.encrypt(out, in, key);
  }
  Time_end = micros();
  Time_Elapsed = Time_end - Time_start;
  Serial.print("Time Elapsed: ");
  Serial.println(Time_Elapsed);
  Serial.print("OrgMsg: ");
  Serial.println("JqoejK4V");
  Serial.print("Result: ");
  printArray(out);

  //decrypt
  for (int i = 0; i < 8; i++) {
    in[i] = out[i];
  }
  Serial.println("Decrypt...");
  Time_start = micros();
  for (counter = 0; counter < 100; ++counter) {
    des.decrypt(out, in, key);
  }
  Time_end = micros();
  Time_Elapsed = Time_end - Time_start;
  Serial.print("Time Elapsed: ");
  Serial.println(Time_Elapsed);
  Serial.print("OrgMsg: ");
  Serial.println("JqoejK4V");
  Serial.print("Result: ");
  printArray(out);
}

void printArray(byte output[]) {
  for (int i = 0; i < 8; i++) {
    if (output[i] < 0x10) {
      Serial.print("0");
    }
    Serial.print(output[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("START");
  desTest();
  Serial.println("FINISH");
}
