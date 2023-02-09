#include <iostream>

using namespace std;

bool is_2_gegree(int n){
    if (n > 2 & n%2 == 0){
        return is_2_gegree(n/2);
    }
    else if (n == 2) return true;
    else return false;
}

int main(){
    int n;
    cin >> n;
    if (is_2_gegree(n)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}