#include <fstream>
#include <chrono>
#include <stdlib.h> 
#include <time.h>
#include <random>

#ifndef N_const
#define N_const 5000
#endif

// вторая часть тупой поиск

bool search(int (&array)[N_const], int N, int summ){
    int left=0, right=N-1;
    while (left != right){
        if (array[left] + array[right] == summ) return true;
        else if (array[left] + array[right] > summ) right--;
        else left++;
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

int randomizer(int left, int right){
    int num = left + ((rand() << 15) + rand())%(right - left + 1);
    return num;
}

int a[N_const] = {0};

int main(){
    srand(time(NULL));
    std::ofstream Fout;
    Fout.open("otpt1.txt");
    Fout.close();
    for (int N = 500; N <= N_const; N += 500) {
        for (int i = 0; i < N; i++){
                a[i] = randomizer(0, N);}
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 100000; cnt!= 0; --cnt){
            int summ = randomizer(0, 2*N);
            int ans = stupid_search(a, N, summ);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        Fout.open("otpt1.txt", std::ios_base::app);
        Fout << N << ' ' << time_span.count() << std::endl;
        Fout.close();
    }
    return 0;
}