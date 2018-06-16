/*
 * Copyright (C) 2015 Southern Storm Software, Pty Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/*
This example runs tests on the AES implementation to verify correct behaviour.
*/

#include <Crypto.h>
#include <AES.h>
#include <string.h>

AES128 aes128;

uint8_t key[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
uint8_t data16[16] = {30,33,60,2,1,15,2,3,30,33,60,2,1,15,2,3};
byte buffer[16];
byte output[16];

void perfCipher(BlockCipher *cipher)
{
    unsigned long start;
    unsigned long elapsed;
    int count;
    int count2;

    crypto_feed_watchdog();

    Serial.print("AES-128-ECB");
    Serial.print(" Set Key ... ");
    start = micros();
    for (count = 0; count < 10000; ++count) {
        cipher->setKey(key, cipher->keySize());
    }
    elapsed = micros() - start;
    Serial.print(elapsed / 10000.0);
    Serial.print("us per operation, ");
    Serial.print((10000.0 * 1000000.0) / elapsed);
    Serial.println(" per second");

    Serial.print("AES-128-ECB");
    Serial.print(" Encrypt ... ");
    start = micros();
    for (count = 0; count < 1000; ++count) {
      cipher->encryptBlock(buffer, data16);
    }
    elapsed = (micros() - start)/1000.0;
    Serial.print("Elapsed:");
    Serial.print(elapsed);
    Serial.print(" us, ");
    Serial.print(elapsed / (1000.0 * 16.0));
    Serial.print(" us per byte, ");
    Serial.print((16.0 * 1000.0 * 1000000.0) / elapsed);
    Serial.println(" bytes per second");

    Serial.print("AES-128-ECB");
    Serial.print(" Decrypt ... ");
    start = micros();
    for (count = 0; count < 1000; ++count) {
        cipher->decryptBlock(output, buffer);
    }
    elapsed = (micros() - start)/1000.0;
    Serial.print("Elapsed:");
    Serial.print(elapsed);
    Serial.print(" us, ");
    Serial.print(elapsed / (1000.0 * 16.0));
    Serial.print(" us per byte, ");
    Serial.print((16.0 * 1000.0 * 1000000.0) / elapsed);
    Serial.println(" bytes per second");

    Serial.println();
    Serial.print("Original Message: ");
    for(int i=0; i<16; i++)
    Serial.print(output[i]);
}

void setup()
{
    Serial.begin(9600);

    Serial.println();

    Serial.println("State Sizes:");
    Serial.print("AES128 ... ");
    Serial.println(sizeof(AES128));

    Serial.println("Performance Tests:");
    perfCipher(&aes128);

}

void loop()
{
}
