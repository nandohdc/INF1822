#include <DES.h>

DES des;

void setup() {
  Serial.begin(9600);
  Serial.println("Hello!");
}

void loop() {
  desTest();
  delay(2000);
}

void desTest()
{
  byte out[16];
  byte in[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  byte key[] = { 0x3b, 0x38, 0x98, 0x37, 0x15, 0x20, 0xf7, 0x5e };
  unsigned long time;
  int count;
  
  Serial.println();
  Serial.println("========= DES test ==========");
  
  //encrypt
  Serial.print("Encrypt...");
  time = micros();
 for (count = 0; count < 1000; ++count) {
  des.encrypt(out, in, key);
 }
  time = ((micros() - time)/1000);
  Serial.print("done. (");
  Serial.print(time);
  Serial.println(" micros)");
  printArray(out);
  
  //decrypt
  for (int i = 0; i < 8; i++)
  {
    in[i] = out[i];
  }
  Serial.print("Decrypt...");
  time = micros();
  for (count = 0; count < 1000; ++count) {
    des.decrypt(out, in, key);
  }
  time = ((micros() - time)/1000);
  Serial.print("done. (");
  Serial.print(time);
  Serial.println(" micros)");
  printArray(out);
}

void printArray(byte output[])
{
  for (int i = 0; i < 8; i++)
  {
    if (output[i] < 0x10)
    {
      Serial.print("0");
    }
    Serial.print(output[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
}
