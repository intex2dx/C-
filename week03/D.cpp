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

    for (int i=0; i<N; i++){
        if (a[i] < 0 and a[i+1] > 0)
    }


    return 0;
}