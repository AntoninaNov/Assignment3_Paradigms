#include <iostream>
#include <dlfcn.h>
#include <limits>

using namespace std;

typedef char* (*EncryptFunc)(char*, int);
typedef char* (*DecryptFunc)(char*, int);

void displayMenu() {
    cout << "1. Encrypt Text\n";
    cout << "2. Decrypt Text\n";
    cout << "3. Exit\n";
}

int main() {
    void* handle = dlopen("./libcaesar.dylib", RTLD_LAZY);
    if (!handle) {
        cerr << "Cannot load library: " << dlerror() << '\n';
        return 1;
    }

    EncryptFunc encrypt = (EncryptFunc) dlsym(handle, "encrypt");
    DecryptFunc decrypt = (DecryptFunc) dlsym(handle, "decrypt");
    if (!encrypt || !decrypt) {
        cerr << "Cannot load symbols: " << dlerror() << '\n';
        dlclose(handle);
        return 1;
    }

    int choice;
    string text;
    int key;
    char* processedText;

    while (true) {
        displayMenu();

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 3) {
            break;
        }

        cout << "Enter text: ";
        if (!getline(cin, text) || text.empty()) {
            cerr << "Invalid input\n";
            continue;
        }

        cout << "Enter key: ";
        if (!(cin >> key)) {
            cerr << "Invalid key\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            processedText = encrypt(const_cast<char*>(text.c_str()), key);
            if (!processedText) {
                cerr << "Encryption failed\n";
                continue;
            }
            cout << "Encrypted text: " << processedText << '\n';
        } else if (choice == 2) {
            processedText = decrypt(const_cast<char*>(text.c_str()), key);
            if (!processedText) {
                cerr << "Decryption failed\n";
                continue;
            }
            cout << "Decrypted text: " << processedText << '\n';
        } else {
            cerr << "Invalid choice\n";
            continue;
        }

        delete[] processedText;
    }

    if (dlclose(handle) != 0) {
        cerr << "Error while closing dynamic library: " << dlerror() << '\n';
    }

    return 0;
}
