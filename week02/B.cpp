#include <iostream>

using namespace std;

int main(){
    int ans=0;
    int z=0;
    cin >> z;
    while (z != 0) {
        if (z % 2 == 0) ans += 1;
        cin >> z;
    }
    cout << ans << endl;
    return 0;
}