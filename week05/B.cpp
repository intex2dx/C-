#include <iostream>


int main(){
    short int* ptr = new short int[10];
    for (int i = 0; i < 10; i++) ptr[i] = i;
    for (int i = 0; i < 10; i++) std::cout << &ptr[i] << ' ';
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) std::cout << ptr[i] << ' ';
    for (int i = 0; i < 10; i+=2) *(ptr + i) *= *(ptr + i);
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) std::cout << ptr[i] << ' ';
    delete [] ptr;
    return 0;
}