#include "caesar.h"
#include <cstring>
#include <cctype>

char* decrypt(char* encryptedText, int key) {
    int length = strlen(encryptedText);
    char* decryptedText = new char[length + 1];

    // Loop through each character in the encrypted string
    for (int i = 0; i < length; ++i) {
        char c = encryptedText[i];
        // Check if character is alphabetic
        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            // Apply decryption by shifting in the opposite direction
            decryptedText[i] = (c - offset - key + 26) % 26 + offset;
        } else {
            // Leave non-alphabetic characters unchanged
            decryptedText[i] = c;
        }
    }
    decryptedText[length] = '\0';

    return decryptedText;
}
