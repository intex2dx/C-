#include <iostream>

#ifndef N
#define N 3  // actual size of the array
#endif

using namespace std;

int main(){
    int a[N] = {0}, b[N] = {0};
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    for (int i = 0; i < N; i++){
        cin >> b[i];
        }
    
    int c[N] = {0};
    for (int i=0; i<N; i++){
        c[2*i] = max(a[i], b[i]);
        c[2*i+1] = min(a[i], b[i]);
    }
    cout << c[0];
    for (int i =0;i<2*N; i++){
        cout << ' ' << c[i];
    }
    cout << endl;
    return 0;
}