#include <iostream>

using namespace std;

#ifndef N
#define N 10
#endif

void swap(int& lha, int& rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void qsort(int (&array)[N], int ind_left_base, int ind_right_base){
    if (ind_left_base < ind_right_base){
        int pivot = array[(ind_left_base + ind_right_base)/2];
        int ind_left = ind_left_base, ind_right = ind_right_base;
        while (ind_left <= ind_right){   
            while (array[ind_left] < pivot) ind_left++;
            while (array[ind_right] > pivot) ind_right--;
            if (ind_left >= ind_right) break;
            swap(array[ind_left++], array[ind_right--]);
            
    }   

        qsort(array, ind_left_base, ind_right);
        qsort(array, ind_right + 1, ind_right_base);

}
}


int main(){
    int a[N] = {0};
    for (int i = 0; i < N; i++) cin >> a[i];
    qsort(a, 0, N-1);
    cout << a[0];
    for (int i = 1; i < N; i++) cout << ' ' << a[i];
    cout << endl;
}