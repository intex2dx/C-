#include <iostream>


int main(){
    short int* ptr;
    *ptr           = new short int[10];
    for (int i = 0; i < 10; i++){
        *ptr[i] = i;
    }
}