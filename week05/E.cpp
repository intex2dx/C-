#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool reserve_memory(int *ptr, size_t N){
    if (ptr == nullptr){
        ptr = new int[N];
        return true;
    }
    return false;
}
void free_memory(int *ptr){
    delete [] ptr;
}

int main() {
    int N = 0;
    int *ptr = nullptr;
    cin >> N;
    cout << reserve_memory(ptr, N) << endl;
    free_memory(ptr);
    return 0;
}