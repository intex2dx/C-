#include <iostream>

using namespace std;

int main(){
    long long a[4] = {1,1,4};
    int N;
    cin >> N;
    if (N > 2) {
        int i = 3;
        while (i <= N){
            long long last = a[2];
            a[2] = 2*a[2] + 2 * a[1] - a[0];
            a[0] = a[1];
            a[1] = last;
            i++;
        }
        cout << a[2];
    }
    else{
        cout << a[N];
    }
    

}