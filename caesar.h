#ifndef CAESAR_H
#define CAESAR_H

extern "C" {
char* encrypt(char* rawText, int key);
char* decrypt(char* encryptedText, int key);
}

#endif //CAESAR_H
