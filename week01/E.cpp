#include <iostream>

using namespace std;

int main(){
    int m=0, n=0;
    cin>>m>>n;
    int a = min(m,n), b = max(m, n), r=0;
    while (b%a != 0){
        r = b%a;
        b = a;
        a = r;
    }
    cout << (m*n/a) << endl;
}
