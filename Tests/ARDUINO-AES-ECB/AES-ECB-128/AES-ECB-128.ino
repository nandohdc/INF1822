/*
   Copyright (C) 2015 Southern Storm Software, Pty Ltd.

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/

/*
  This example runs tests on the AES implementation to verify correct behaviour.
*/

#include <Crypto.h>
#include <AES.h>
#include <string.h>

struct TestVector
{
  const char *name;
  byte key[16];
  byte plaintext[16];
  byte ciphertext[16];
};

// Define the ECB test vectors from the FIPS specification.
static TestVector const testVectorAES128 = {
  .name        = "AES-128-ECB",
  .key         = {'1', '2', '3', '4', '5', '6', '7', '8',
    '9', '0', 'a', 'b', 'c', 'd', 'e', 'f'
  },
  .plaintext   = {'4', 'v', 'J', 'F', 'K', 'a', 'p', 'f',
    '1', '8', 'R', 'R', 'R', 'x', 'H', 'i'
  }
};


AES128 aes128;

void perfCipher(BlockCipher *cipher, const struct TestVector *test)
{
  unsigned long start;
  unsigned long elapsed;
  int count;
  byte buffer[16];

  crypto_feed_watchdog();

  Serial.print(test->name);
  Serial.println(" Set Key ... ");
  start = micros();
  for (count = 0; count < 10000; ++count) {
    cipher->setKey(test->key, cipher->keySize());
  }
  elapsed = micros() - start;

  Serial.print(test->name);
  Serial.print(" Encrypt ... ");
  start = micros();
  for (count = 0; count < 1000; ++count) {
    cipher->encryptBlock(test->ciphertext, test->plaintext);
  }
  elapsed = micros() - start;
  Serial.print("Time Elapsed: ");
  Serial.print(elapsed);
  Serial.println("us");

  Serial.print(test->name);
  Serial.print(" Decrypt ... ");
  start = micros();
  for (count = 0; count < 1000; ++count) {
    cipher->decryptBlock(buffer, test->ciphertext);
  }
  elapsed = micros() - start;
  Serial.print("Time Elapsed: ");
  Serial.print(elapsed);
  Serial.println("us");

  Serial.println();

  Serial.print("Decrypted Msg: ");
  for (int i = 0; i < 16; i++) {
    Serial.print((char)buffer[i]);
  }
  Serial.println();
}

void setup()
{
  Serial.begin(9600);
  int i = 20;
  while (i > 0) {
    Serial.println("State Sizes:");
    Serial.print("AES128 ... ");
    Serial.println(sizeof(AES128));
    Serial.println();

    Serial.println("Performance Tests:");
    perfCipher(&aes128, &testVectorAES128);
    i--;
  }
}

void loop()
{
}
