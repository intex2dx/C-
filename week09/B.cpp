#include <iostream>

using namespace std;

int main(){
    int M, N;
    cin >> M;
    cin >> N;
    int a = 1;
    bool t = true;
    while (M != 0){
        int k = (M*a)/(N);
        if (k != 0) {
            for (int i = 0; i < k; i++){
                if (t) {
                    cout << a;
                    t = false;
                }
                else cout << " " << a;
            }
        M = (M*a)%N;
        N = N*a;
        }
        a += 1;
    }

}