#include <iostream>

using namespace std;

int main(){
    int a[6] = {1, 7, 28, 49, 63, 98};
    int ans = 0;
    int M;
    cin >> M;
    int i = 5;
    while (M != 0){
        ans += M/a[i];
        M = M%a[i];
        i--;
    }
    cout << ans;
}