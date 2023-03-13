#include <iostream>

using namespace std;

#ifndef N
#define N 10
#endif

void swap(unsigned& lha, unsigned&rha){
        unsigned tmp = lha;
        lha = rha;
        rha = tmp;
}

void check(unsigned (&arr)[N], unsigned step, unsigned begin_idx){
    unsigned length = N/step;
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[begin_idx + j*step] > arr[begin_idx + (j+1) * step]) swap(arr[begin_idx + j*step], arr[begin_idx + (j+1)*step]);
        }
    }
}

void comb_sort(unsigned (&arr)[N]){
    unsigned divider = 2;
    while (N/divider > 1){
        for (unsigned begin_idx = 0; begin_idx <= N%(N/divider); begin_idx++){
            check(arr, N/divider, begin_idx);
        }
        
        divider *= 2;
    }
    check(arr, 1, 0);
}

int main(){
    unsigned a[N] = {0};
    for (int i = 0; i < N; i++) cin >> a[i];
    comb_sort(a);
    cout << a[0];
    for (int i = 1; i < N; i++) cout << ' ' << a[i];
    cout << endl;
}
