#include <iostream>

using namespace std;

#ifndef N
#define N 9
#endif

//Разумеется, идея кода была подсмотрена с чужого гита (PavVovk)
//Могу лишь заметить, что помимо коммутативности важна
//ещё и ассоциативность операции XOR


int search(int (&array)[N]){
    int ans;
    for (int i = 0; i < N; i++){
        ans = ans ^ array[i];
    }
    return ans;
}

int main(){
    int a[N] = {0};
    for (int i = 0; i < N; i++) cin >> a[i];
    cout << search(a);
    return 0;
}