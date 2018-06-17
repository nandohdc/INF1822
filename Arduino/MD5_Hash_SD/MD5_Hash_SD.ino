#include <MD5.h>
#include <SPI.h>
#include <SD.h>

MD5  hashMD5;
File myFile;
/*
  This is en example of how to use my MD5 library. It provides two
  easy-to-use methods, one for generating the MD5 hash, and the second
  one to generate the hex encoding of the hash, which is frequently used.
*/

String readTestFile(char* filename) {
  // re-open the file for reading:
  myFile = SD.open(filename);
  if (myFile) {
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      String msg = myFile.readStringUntil('\n');
      return msg;
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.print("error opening: ");
    Serial.println(filename);
  }
}

void writeResultsFile(unsigned long time_elapsed, String originalMsg, char* md5Result) {
  myFile = SD.open("results.txt", FILE_WRITE);
  // if the file opened okay, write to it:
  if (myFile) {
    myFile.print("Time Elapsed: ");
    myFile.println(time_elapsed);
    myFile.print("OrgMsg: ");
    myFile.println(originalMsg);
    myFile.print("Result: ");
    myFile.println(md5Result);
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void MD5_test(char* filename, String OriginalMsg) {
  unsigned long Time_start;
  unsigned long Time_end;
  unsigned long Time_Elapsed;
  int counter;
  int lenString;
  char *md5str;
  //give it a second
  delay(1000);
  //generate the MD5 hash for our string
  lenString = OriginalMsg.length();
  char msg [lenString + 1];
  OriginalMsg.toCharArray(msg, lenString+1) ;
  Time_start = micros();
  for (counter = 0; counter < 10; ++counter) {
    md5str = hashMD5.md5(msg);
  }
  Time_end = micros();
  Time_Elapsed = Time_end - Time_start;
  writeResultsFile(Time_Elapsed, OriginalMsg, md5str);
}


void setup()
{
  Serial.begin(9600);
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.print("START");
  String msg = readTestFile("8b.txt");
  MD5_test("8b.txt", msg);
  Serial.print("FINISH");
}

void loop()
{
}
