#include <iostream>
#include <dlfcn.h> // for dlopen, dlsym, dlclose

using namespace std;

// Function pointers for the library functions
typedef char* (*EncryptFunc)(char*, int);
typedef char* (*DecryptFunc)(char*, int);

int main() {
    // Load the dynamic library
    void* handle = dlopen("./libcaesar.dylib", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot load library: " << dlerror() << '\n';
        return 1;
    }

    // Load the symbols (functions)
    EncryptFunc encrypt = (EncryptFunc) dlsym(handle, "encrypt");
    DecryptFunc decrypt = (DecryptFunc) dlsym(handle, "decrypt");

    if (!encrypt || !decrypt) {
        std::cerr << "Cannot load symbols: " << dlerror() << '\n';
        return 1;
    }

    // Command Line Interface logic here
    // TODO: Take the input text and key, call encrypt and decrypt, and display results

    // Close the dynamic library
    dlclose(handle);

    return 0;
}
