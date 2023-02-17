#include <iostream>

#ifndef N
#define N 5
#endif

void swap(int& lha, int&rha){
    int cmp = rha;
    rha = lha;
    lha = cmp;
}

using namespace std;
int main() {
    int a[N] = {0};
    int b[N] = {0};
    int i_a = 0, i_b = 0;
    for (int i = 0; i < N; i++){
        int elem;
        cin >> elem;
        if (elem > 0) {a[i_a] = elem; i_a++;}
        else {b[i_b] = elem; i_b++;}
    }
    if (a[0] != 0) {
        cout << a[0];
        int i = 1;
        while (a[i] != 0 & i < N) {
            cout << ' ' << a[i];
            i += 1;
        }
        if (b[0] !=0) {
          cout << '|';
        }
    }
    if (b[0] != 0){
        cout << b[0];
        int i = 1;
        while (b[i] !=0 & i < N){
            cout << ' ' << b[i];
            i += 1;
        }
    cout << endl;
    }
    
    return 0;
}