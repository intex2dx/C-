#include <iostream>

using namespace std;

int main(){
    int k;
    cin >> k;
    int* a  = new int[k];
    for (int i = 0; i < k; i++){
        cin >> a[i];
    }
    int M;
    cin >> M;
    int ans = 0;
    int i   = k - 1;
    while (M != 0){
        ans += M/a[i];
        M = M%a[i];
        i--;
    }
    cout << ans;
    delete [] a;
}