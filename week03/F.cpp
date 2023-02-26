#include <iostream>

#ifndef N
#define N 5
#endif
using namespace std;


int binsearch(int (&array)[N]){
    int left = 0, right = N;
    while (left < right){
        int m = (left + right - 1)/2 + 1;
        if (array[m] == 0) left = m;
        else right = m - 1;
    }
    return left;
}

int main(){
    int a[N] = {0};
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    cout << binsearch(a) << endl;

}