#include <iostream>
#include <dlfcn.h>

using namespace std;

typedef char* (*EncryptFunc)(char*, int);
typedef char* (*DecryptFunc)(char*, int);

int main() {
    // Load the dynamic library
    void* handle = dlopen("./libcaesar.dylib", RTLD_LAZY);
    if (!handle) {
        cerr << "Cannot load library: " << dlerror() << '\n';
        return 1;
    }

    // Load the symbols
    EncryptFunc encrypt = (EncryptFunc) dlsym(handle, "encrypt");
    DecryptFunc decrypt = (DecryptFunc) dlsym(handle, "decrypt");

    if (!encrypt || !decrypt) {
        cerr << "Cannot load symbols: " << dlerror() << '\n';
        return 1;
    }

    // Command Line Interface
    string text;
    int key;

    // Encryption
    cout << "Enter text to encrypt: ";
    getline(cin, text);
    cout << "Enter key: ";
    cin >> key;

    char* encrypted = encrypt(const_cast<char*>(text.c_str()), key);
    cout << "Encrypted text: " << encrypted << '\n';
    delete[] encrypted;

    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Decryption
    cout << "Enter text to decrypt: ";
    getline(cin, text);
    cout << "Enter key: ";
    cin >> key;

    char* decrypted = decrypt(const_cast<char*>(text.c_str()), key);
    cout << "Decrypted text: " << decrypted << '\n';
    delete[] decrypted;

    // Close the dynamic library
    dlclose(handle);

    return 0;
}
