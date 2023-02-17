#include <iostream>
#include <algorithm>

using namespace std;

#ifndef N
#define N 2
#endif

#ifndef M
#define M 2
#endif


void sort2d(int (&array)[N][M]){
    int new_array[N*M];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            new_array[i*M + j] = array[i][j];
        }
    }
    sort(new_array, new_array + M * N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            array[i][j] = new_array[i*M + j];
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