#include <fstream>
#include <chrono>
#include <stdlib.h> 
#include <time.h>
#include <random>
#include <iostream>

#ifndef N_const
#define N_const 10000
#endif

using namespace std;


unsigned n_swaps = 0;

int randomizer(int left, int right){
    int num = left + ((rand() << 15) + rand())%(right - left + 1);
    return num;
}

void swap(unsigned &lha, unsigned &rha){
    unsigned tmp = lha;
    lha = rha;
    rha = tmp;
    n_swaps++;
}


void check(unsigned (&arr)[N_const], unsigned N, unsigned step, unsigned begin_idx){
    unsigned length = N/step;
    for (unsigned i = 0; i < length-1; i++){
        unsigned marker = i+1;
        while (marker > 0){
            if (arr[begin_idx + marker * step] >= arr[begin_idx + (marker - 1) * step]) break;
            swap(arr[begin_idx + marker*step], arr[begin_idx + (marker-1)*step]);
            marker--;
        }
    
    }
 
}


void shell_sort(unsigned (&arr)[N_const], unsigned N){
    unsigned divider = 2;
    while (N/divider > 1){
        for (unsigned begin_idx = 0; begin_idx <= N%(N/divider); begin_idx++){
            check(arr, N, N/divider, begin_idx);
        }
        
        divider *= 2;
    }
    check(arr, N, 1, 0);
}

unsigned a[N_const] = {0};

int main(){
    srand(999);
    std::ofstream Fout;
    Fout.open("part 3 output s1.txt");
    Fout.close();
    Fout.open("part 3 s1 swaps.txt");
    Fout.close();
    for (unsigned N = 100; N <= N_const; N += 100) {
        n_swaps = 0;
        for (int i = 0; i < N; i++){
            a[i] = randomizer(0, N);
        }

        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 100000; cnt!= 0; --cnt){
            shell_sort(a, N);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        Fout.open("part 3 output s1.txt", std::ios_base::app);
        Fout << N << ' ' << time_span.count() << std::endl;
        Fout.close();
        Fout.open("part 3 s1 swaps.txt", std::ios_base::app);
        Fout << N << ' ' << n_swaps << std::endl;
        Fout.close();

    }
    return 0;
}