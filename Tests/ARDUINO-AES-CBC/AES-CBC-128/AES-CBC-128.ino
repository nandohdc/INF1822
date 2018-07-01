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
This example runs tests on the CBC implementation to verify correct behaviour.
*/

#include <Crypto.h>
#include <CryptoLegacy.h>
#include <AES.h>
#include <CBC.h>
#include <string.h>

#define MAX_PLAINTEXT_SIZE  64
#define MAX_CIPHERTEXT_SIZE 64

struct TestVector
{
    const char *name;
    byte key[16];
    byte plaintext[MAX_PLAINTEXT_SIZE];
    byte ciphertext[MAX_CIPHERTEXT_SIZE];
    byte iv[16];
    size_t size;
};

static TestVector const testVectorAES128CBC1 = {
    .name        = "AES-128-CBC",
    .key         = {'1', '2', '3', '4', '5', '6', '7', '8',
                    '9', '0', 'a', 'b', 'c', 'd', 'e', 'f'},    
    .plaintext   = /*{'4', 'v', 'J', 'F', 'K', 'a', 'p', 'f',
                    '1', '8', 'R', 'R', 'R', 'x', 'H', 'i'},*/
                    
                    {'V', 'n', 'z', 'd', 'f', 'S', 'p', 'u',
                    'd', 'k', 'b', 'G', 'R', 'w', 'X', '8',
                    'f', 'B', 'o', 'U', 'z', 'F', 'S', 'W',
                    'F', 'g', '9', '4', '0', 'z', 'c', 'o',
                    'r', '0', 'u', 'S', '5', '1', '7', '1',
                    '9', 'y', '2', 'r', 'E', 'c', 'W', 'J',
                    'a', '0', '1', '6', 'e', 'z', '0', 'H',
                    'i', '2', '9', 'F', 'K', 'M', '6', 'w',},
    .ciphertext  = {},
    .iv          = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f},
    .size        = 64
};

CBC<AES128> cbcaes128;

void perfCipher(const char *name, Cipher *cipher, const struct TestVector *test)
{
    unsigned long start;
    unsigned long elapsed;
    int count;
    byte buffer[64];

    Serial.print("AES-128-CBC Encrypt");
    Serial.print(" ... ");

    cipher->setKey(test->key, cipher->keySize());
    cipher->setIV(test->iv, cipher->ivSize());
    start = micros();
    for (count = 0; count < 500; ++count) {
        cipher->encrypt(test->ciphertext, test->plaintext, sizeof(test->plaintext));
    }
    elapsed = micros() - start;
    Serial.print("Time Elapsed: ");
    Serial.print(elapsed / (500.0));
    Serial.println("us");

    Serial.print("AES-128-CBC Decrypt");
    Serial.print(" ... ");

    cipher->setKey(test->key, cipher->keySize());
    cipher->setIV(test->iv, cipher->ivSize());
    start = micros();
    for (count = 0; count < 500; ++count) {
        cipher->decrypt(buffer, test->ciphertext, sizeof(test->ciphertext));
    }
    elapsed = micros() - start;
    Serial.print("Time Elapsed: ");
    Serial.print(elapsed / (500.0));
    Serial.println("us");

    for(int i = 0; i < test->size; i++){
      Serial.print((char)buffer[i]);
      }
    Serial.println();
}

void setup()
{
    Serial.begin(9600);

    Serial.println();

    Serial.println("Performance Tests:");
    perfCipher("AES-128-CBC Encrypt", &cbcaes128, &testVectorAES128CBC1);
}

void loop()
{
}
