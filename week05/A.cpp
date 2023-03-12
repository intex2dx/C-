#include <iostream>


int main(){
    double* ptr;
    *ptr = 0;
    std::cout << ptr << ' ' << *ptr << std::endl;
    ptr -= 3;
    std::cout << ptr << ' ' << *ptr << std::endl;
    ptr += 5;
    std::cout << ptr << ' ' << *ptr << std::endl;
}  