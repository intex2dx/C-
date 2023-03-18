#include <iostream>

int main(){
    int *ptr = new int[1];
    int elem, N = 0;
    std::cin >> elem;
    while (elem != 0){
        *ptr = elem;
        ptr+=1;
        N+=1;
        std::cin >> elem;
    }  

    int *arr = new int[N];
    arr += (ptr - N - arr);
    if (N > 1) {
        for (int i = 0; i < N-1; i++) std::cout << arr[i+1] - arr[i] << ' ';
    }
}