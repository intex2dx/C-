#include <fstream>
#include <chrono>
#include <stdlib.h> 
#include <time.h>
#include <random>
#include <iostream>

#ifndef N_const
#define N_const 1000100
#endif

// линейный поиск элемента, которого нет

int linear_search(int (&array)[N_const], int N, int elem){
    int ans = 0;
    while (array[ans] != elem & ans < N){
        ans++;
    }
    if (ans == N) return -1;
    else return ans;
}

int randomizer(int left, int right){
    int num = left + ((rand() << 15) + rand())%(right - left + 1);
    return num;
}
int binary_search(int (&array)[N_const], int N, int elem){
    int left = 0;
    int right = N;
    while (left < right){
        int med = (left + right)/2;
        if (array[med] < elem) left = med+ 1;
        else right = med; 
    }
    if (array[left] == elem) return left;
    else return -1;
}


int a[N_const] = {0};

int main(){
    srand(time(NULL));
    std::ofstream Fout;
    Fout.open("output1.txt");
    Fout.close();
    
    for (int N = 100; N <= N_const; N += 50000) {
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 100000; cnt!= 0; --cnt){
            int elem = 1;
            int ans = linear_search(a, N, elem);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        Fout.open("output1.txt", std::ios_base::app);
        Fout << N << ' ' << time_span.count() << std::endl;
        Fout.close();
    }
    return 0;
}