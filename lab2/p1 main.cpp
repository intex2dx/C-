#include <iostream>
using namespace std;

#ifndef N
#define N 10
#endif

void swap(unsigned& lha, unsigned&rha){
        int tmp = lha;
        lha = rha;
        rha = tmp;
}

void forward_step(unsigned (&arr)[N], unsigned const begin_idx, unsigned const end_idx){
    for (int i = begin_idx; i < end_idx; i++){
        if (arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
    }

}
void backward_step(unsigned (&arr)[N], unsigned const begin_idx, unsigned const end_idx){
    for (int i = end_idx; i > begin_idx; i--){
        if (arr[i] < arr[i-1]) swap(arr[i], arr[i-1]);
    }
}
void shaker_sort(unsigned (&arr)[N], unsigned const begin_idx, unsigned const end_idx){
    if (begin_idx < end_idx){
        forward_step(arr, begin_idx, end_idx);
        backward_step(arr, begin_idx, end_idx-1);
        shaker_sort(arr, begin_idx+1, end_idx-1);
    }
}

int main(){
    unsigned a[N] = {0};
    for (int i = 0; i < N; i++) cin >> a[i];
    shaker_sort(a, 0, N-1);
    cout << a[0];
    for (int i = 1; i < N; i++) cout << ' ' << a[i];
    cout << endl;
}
