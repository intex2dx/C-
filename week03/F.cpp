#include <iostream>

#ifndef N
#define N 2  // actual size of the array
#endif
using namespace std;


int binsearch(int (&array)[N]){
    int left = 0, right = N;
    while (left < right){
        int m = (left + right)/2;
        if (array[m] == 0) left = m + 1;
        else right = m;
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