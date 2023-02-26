#include <iostream>

using namespace std;

#ifndef N_const
#define N_const 10
#endif

bool binary_search(int (&array)[N_const], int N, int elem){
    int left = 0;
    int right = N;
    while (left < right){
        int med = (left + right)/2;
        if (array[med] < elem) left = med+ 1;
        else right = med; 
    }
    if (array[left] == elem) {
        if (left != 0) swap(array[0], array[left]);
        return true;
    }
    else return false;}

int a[N_const] = {0};