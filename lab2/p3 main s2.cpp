#include <iostream>
#include <cmath>

using namespace std;

#ifndef N
#define N 2
#endif


void swap(unsigned &lha, unsigned &rha){
    unsigned tmp = lha;
    lha = rha;
    rha = tmp;
}


void check(unsigned (&arr)[N], unsigned step, unsigned begin_idx){
    unsigned length = N/step;
    for (unsigned i = 0; i < length-1; i++){
        unsigned marker = i+1;
        while (marker > 0){
            if (arr[begin_idx + marker * step] >= arr[begin_idx + (marker - 1) * step]) break;
            swap(arr[begin_idx + marker*step], arr[begin_idx + (marker-1)*step]);
            marker--;
        }
    
    }
 
}


void shell_sort(unsigned (&arr)[N]){
    unsigned i = log2(N + 1);
    while (i > 1){
        for (unsigned begin_idx = 0; begin_idx <= N%i; begin_idx++){
            check(arr, i, begin_idx);
        }
        
        i--;
    }
    check(arr, 1, 0);
}

int main(){
    unsigned a[N] = {0};
    for (int i = 0; i < N; i++) cin >> a[i];
    shell_sort(a);
    cout << a[0];
    for (int i = 1; i < N; i++) cout << ' ' << a[i];
    cout << endl;
}