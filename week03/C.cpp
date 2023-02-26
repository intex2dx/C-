#include <iostream>

#ifndef N
#define N 7  // actual size of the array
#endif

void swap(int& lha, int&rha){
    int cmp = rha;
    rha = lha;
    lha = cmp;
}

void shift(int (&array)[N]){
    for (int i = N-1;i!=0;i--){
        swap(array[i-1], array[i]);
    }
}

using namespace std;
int main() {
    int k;
    cin >> k;
    int a[N] = {0};
    for (int i=0;i<N;i++){   
        cin >> a[i];}
    for (int i = 0; i < k%N; i++){
        shift(a);
    }
    cout << a[0];
    for (int i=1; i<N; i++) {
        cout << ' ' << a[i];
    }
    cout << endl;
    return 0;
}