#include <iostream>
#include <cmath>

using namespace std;

#ifndef N
#define N 5
#endif

unsigned fibonacci[2*N] = {0};

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

unsigned binary_search(unsigned (&arr)[2*N], unsigned elem){
    unsigned left = 0;
    unsigned right = N;
    while (left < right){
        unsigned med = (left + right - 1)/2 + 1;
        if (arr[med] <= elem) left = med;
        else right = med - 1; 
    }
    return left;
}


void shell_sort(unsigned (&arr)[N]){
    unsigned i_ind = binary_search(fibonacci, N);
    unsigned i = fibonacci[i_ind];
    while (i > 1){
        for (unsigned begin_idx = 0; begin_idx <= N%i; begin_idx++){
            check(arr, i, begin_idx);
        }
        i_ind--;
        i = fibonacci[i_ind];
    }
    check(arr, 1, 0);
}



void create_fibonacci(){
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i = 2; i < 2*N; i++) fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
}

int main(){
    create_fibonacci();
    unsigned a[N] = {0};
    for (int i = 0; i < N; i++) cin >> a[i];
    shell_sort(a);
    cout << a[0];
    for (int i = 1; i < N; i++) cout << ' ' << a[i];
    cout << endl;
}