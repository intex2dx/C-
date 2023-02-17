#include <iostream>

using namespace std;

#ifndef N
#define N 2
#endif

#ifndef M
#define M 2
#endif

void print_transoposed(int (&array)[N][M]){
    for (int j = 0; j < M; j++){
        cout << array[0][j];
        for (int i = 1; i<N; i++){
            cout << ' ' << array[i][j];
        }
        cout << endl;
    }
}

int main(){
    int a[N][M] = {{0}};
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }
    print_transoposed(a);
    return 0;
}