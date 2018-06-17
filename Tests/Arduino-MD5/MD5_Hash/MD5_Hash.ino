#include <MD5.h>
/*
  This is en example of how to use my MD5 library. It provides two
  easy-to-use methods, one for generating the MD5 hash, and the second
  one to generate the hex encoding of the hash, which is frequently used.
*/

void MD5_test(char* OriginalMsg) {
  MD5  hashMD5;
  unsigned long Time_start;
  unsigned long Time_end;
  unsigned long Time_Elapsed;
  int counter;
  char *md5str;
  //give it a second
  delay(1000);
  //generate the MD5 hash for our string
  Time_start = micros();
  for (counter = 0; counter < 20; ++counter) {
    md5str = hashMD5.md5(OriginalMsg);
  }
  Time_end = micros();
  Time_Elapsed = Time_end - Time_start;
  Serial.print("Time Elapsed: ");
  Serial.println(Time_Elapsed);
  Serial.print("OrgMsg: ");
  Serial.println(OriginalMsg);
  Serial.print("Result: ");
  Serial.println(md5str);
}


void setup()
{
  Serial.begin(9600);
  Serial.println("START");
  char* msg = "JqoejK4V";
  MD5_test(msg);
  Serial.print("FINISH");
}

void loop()
{
}
