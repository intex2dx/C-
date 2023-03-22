#include <iostream>
#include <cstring>

using namespace std;

char *resize(const char *buf, size_t size, size_t new_size) {
    char* new_buf = new char[new_size];
    for (int i = 0; i < min(new_size, size); i++){
        new_buf[i] = buf[i];
    }
    return new_buf;
    
}

int main() {
    int *a = new int[10];
    const char* a_char;
    resize(a_char, 10, 20);
    delete[] a;
}