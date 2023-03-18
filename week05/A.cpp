#include <iostream>

int main() {
    double *ptr = nullptr;
    double value = 0;
    ptr = &value;
    std::cout << ptr << ' ' << *ptr << std::endl;
    ptr -= 3;
    std::cout << ptr << ' ' << *ptr << std::endl;
    ptr += 5;
    std::cout << ptr << ' ' << *ptr << std::endl;
    return 0;
}