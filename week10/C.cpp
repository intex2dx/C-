#include <iostream>

using namespace std;

int main() {
    int cnt[]
    int 
    int N;
    cin >> N;
    int i = 0;
    while (N > 0){
        cnt[i] = N/(10 - i);
        N = N%(10-i);
        i++;
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < cnt[i]; j++) cout << 10 - i << " ";
    }
    cout << endl;
}