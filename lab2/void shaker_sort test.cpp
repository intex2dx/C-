#include <stdlib.h> 
#include <random>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#ifndef N_const
#define N_const 1000
#endif

unsigned a[N_const];
unsigned b[N_const];

int randomizer(int left, int right){
    int num = left + ((rand() << 15) + rand())%(right - left + 1);
    return num;
}

void swap(unsigned& lha, unsigned&rha){
        int tmp = lha;
        lha = rha;
        rha = tmp;
}

void forward_step(unsigned (&arr)[N_const], unsigned N, unsigned const begin_idx, unsigned const end_idx){
    for (int i = begin_idx; i < end_idx; i++){
        if (arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
    }

}
void backward_step(unsigned (&arr)[N_const], unsigned N, unsigned const begin_idx, unsigned const end_idx){
    for (int i = end_idx; i > begin_idx; i--){
        if (arr[i] < arr[i-1]) swap(arr[i], arr[i-1]);
    }
}
void shaker_sort(unsigned (&arr)[N_const], unsigned N,unsigned const begin_idx, unsigned const end_idx){
    if (begin_idx < end_idx){
        forward_step(arr, N, begin_idx, end_idx);
        backward_step(arr,N, begin_idx, end_idx-1);
        shaker_sort(arr,N, begin_idx+1, end_idx-1);
    }
}


int main(){
    srand(999);
    ofstream Fout;
    Fout.open("p1 results.txt");
    Fout.close();
    bool t = true;
    for (unsigned N = 100; N < N_const;N+=100){
        for (unsigned cnt = 0; cnt < 10; cnt++){
            for (int i = 0; i < N; i++) a[i] = b[i] = randomizer(0, N);
            shaker_sort(a, N, 0, N-1);
            sort(b, b+N);
            for (int i = 0; i < N; i++){
                if (a[i] != b[i])
                {
                    t = false;
                    Fout.open("p1 results.txt", ios_base::app);
                    Fout << "Failed on N = " << N << endl;
                    Fout.close(); 
            }
        }
    }}
    Fout.open("p1 results.txt", ios_base::app);
    if (t) Fout << "OK";
    else Fout << "F";
    Fout.close();
}