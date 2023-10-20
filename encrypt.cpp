#include "caesar.h"
#include <cstring>
#include <cctype>

char* encrypt(char* rawText, int key) {
    int length = strlen(rawText);
    char* encryptedText = new char[length + 1];

    // Loop through each character in the input string
    for (int i = 0; i < length; ++i) {
        char c = rawText[i];
        // Check if character is alphabetic
        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            // Apply encryption by shifting
            encryptedText[i] = (c - offset + key) % 26 + offset;
        } else {
            // Leave non-alphabetic characters unchanged
            encryptedText[i] = c;
        }
    }
    encryptedText[length] = '\0';

    return encryptedText;
}
