#include <iostream>

#ifndef N
#define N 5  // actual size of the array
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
    for (int i=0; i<N/2; i++){
        swap(a[i], a[N-i-1]);
    }
    cout << a[0];
    for (int i=1; i<N; i++) {
        cout << ' ' <<a[i];
    }
    cout << endl;

}
