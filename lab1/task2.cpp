#include <iostream>

using namespace std;

#ifndef N_const
#define N_const 10
#endif

bool search(int (&array)[N_const], int N, int summ){
    int left=0, right=N-1;
    while (left != right){
        if (array[left] + array[right] == summ) return true;
        else if (array[left] + array[right] > summ) right -= 1;
        else left += 1;
    }
    return false;

}

bool stupid_search(int (&array)[N_const], int N, int summ){
    for (int i = 0; i < N-1; i++){
        for (int j = i+1; j < N; j++){
            if (array[i] + array[j] == summ) return true;
        }
    }
    return false;
}

int main(){
    

}