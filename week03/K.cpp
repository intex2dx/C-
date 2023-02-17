#include <iostream>

using namespace std;

#ifndef N
#define N 2
#endif

int trace(int (&array)[N*N]){
    int ans = 0;
    for (int i = 0; i < N; i++){
        ans += array[N * i + i];
    }
    return ans;
}

int main() {
    int a[N*N] = {0};
    for (int i = 0; i < N * N; i ++){
        cin >> a[i]; 
    }
    cout << trace(a) << endl;
    return 0;
}