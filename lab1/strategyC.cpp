#include <fstream>
#include <chrono>
#include <stdlib.h> 
#include <time.h>
#include <random>
#include <iostream>

#ifndef N_const
#define N_const 100000
#endif

using namespace std;

int a[N_const] = {0};
int cnt[N_const] = {0};

void swap(int &lha, int &rha){
    int cmp = lha;
    lha = rha;
    rha = cmp;
}

int randomizer(int left, int right){
    srand(time(NULL));
    int num = left + rand()%(right - left + 1);
    return num;
}
bool linear_search(int (&array)[N_const], int N, int elem){
    int ans = 0;
    while (array[ans] != elem & ans < N){
        ans++;
    }
    if (ans == N) return false;
    else {
        cnt[ans] += 1;
        if (ans != 0 & cnt[ans] > cnt[ans - 1]) swap(array[ans-1], array[ans]);
        return true;
    };
}



int main(){
    std::ofstream Fout;
    Fout.open("outC1.txt");
    Fout.close();
    for (int N = 5000; N <= N_const; N += 5000) {
        a[0] = randomizer(0, N);
        for (int i = 1; i < N; i++){
                a[i] = randomizer(0, N);}
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 100000; cnt!= 0; --cnt){
            int elem = cnt%N;
            bool ans = linear_search(a, N, elem);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        Fout.open("outC1.txt", std::ios_base::app);
        Fout << N << ' ' << time_span.count() << std::endl;
        Fout.close();
    }
    return 0;
}