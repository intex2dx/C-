#include <iostream>

#ifndef N
#define N 4  // actual size of the array
#endif

void swap(int& lha, int&rha){
    int cmp = rha;
    rha = lha;
    lha = cmp;
}

using namespace std;
int main() {
    int a[N] = {0};
    for (int i=0;i<N;i++){   
        cin >> a[i];}
    for (int i=1; i<N; i++){
        swap(a[i-1], a[i]);
    }
    cout << a[0];
    for (int i=1; i<N; i++) {
        cout << ' ' <<a[i];
    }
    cout << endl;
    return 0;
}