#include <iostream>

using namespace std;

#ifndef N
#define N 2
#endif


void swap(int& lha, int& rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void gnome_sort(int (&array)[N]){
    int i = 1, j = 2;
    while (i < N){
        if (array[i] >= array[i-1]){
            i = j;
            j++;
        }
        else {
            swap(array[i-1], array[i]);
            i--;
            if (i == 0) {
                i = j;
                j++;
            }
        }
    }
}

int main(){
    int a[N] = {0};
    for (int i = 0; i < N; i++) cin >> a[i];
    gnome_sort(a);
    cout << a[0];
    for (int i = 1; i < N; i++) cout << ' ' << a[i];
}