#include <iostream>

using namespace std;

int main(){
    int X1 = 0;
    cin >> X1;
    long long a[4];
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    for (int i = 4; i < X1+1; i++){
        long long last = a[3];
        a[3] = a[1] + a[2] + a[3];
        a[0] = a[1];
        a[1] = a[2];
        a[2] = last;

    }
    if (X1 < 3) cout << a[X1];
    else cout << a[3];
}