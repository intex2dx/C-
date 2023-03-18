#include <iostream>

using std::cin;
using std::cout;

void swap(int& lha, int&rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void input_array(int *ptr, size_t N){
    for (int i = 0; i < N; i++) cin >> ptr[i];
}
void reverse(int *ptr, size_t N) {
    for (int i = 0; i <= N/2; i++){
        swap(*(ptr + i), *(ptr + N - i - 1));
    }
}
void print(const int *ptr, size_t N){
    for (int i = 0; i < N; i++) cout << ptr[i] << ' ';
}


int main() {
    int N    = 0;
    int *ptr = nullptr;
    cin >> N;
    ptr = new int[N];

    input_array(ptr, N);
    reverse(ptr, N);
    print(ptr, N);
    return 0;
}