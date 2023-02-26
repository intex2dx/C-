#include <iostream>

#ifndef N
#define N 1
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
    
    int c[2*N] = {0};
    int cnt_a = 0;
    int cnt_b = 0;
    for (int i = 0; i < 2*N; i++){
        if (a[cnt_a] <= b[cnt_b]) {
            c[i] = a[cnt_a];
            cnt_a++;
        }
        else {
            c[i] = b[cnt_b];
            cnt_b++;
        }
    }
    cout << c[0];
    for (int i = 1; i < 2 * N; i++){
        cout << ' ' << c[i];
    }
    cout << endl;
    return 0;
}