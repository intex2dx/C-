#include <iostream>
#include <algorithm>

using namespace std;

#ifndef N
#define N 1
#endif

#ifndef M
#define M 3
#endif

void swap(int &rha, int &lha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void sort2d(int (&array)[N][M]){
    for (int k1 = 0; k1 < N*M; k1++){
        for (int k2 = 0; k2 < N*M - k1 - 1; k2++){
            if (array[k2/M][k2%M] > array[(k2+1)/M][(k2+1)%M]) swap(array[k2/M][k2%M], array[(k2+1)/M][(k2+1)%M]);
        }
    }
    
}


int main(){
    int a[N][M] = {{0}};
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }
    sort2d(a);
    for (int i = 0; i< N; i++){
        cout << a[i][0];
        for (int j = 1; j < M; j++){
            cout << ' ' << a[i][j];
        }
        cout << endl;
    }
    return 0;
}