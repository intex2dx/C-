#include <iostream>
#include <cmath>

using namespace std;

bool req(int number, int length){
    if (length == 0 | length == 1) return true;
    else {
        int divider = pow(10, length - 1);
        int end = number % 10;
        int start = number / divider;
        if (end != start) return false;  
        else {
            number -= divider * start;
            number /= 10;
            return req(number, length - 2);
        }
    }
}

int main(){
    int n, numb, length = 0;
    cin >> n;
    numb = n;

    while (numb != 0) {
        numb /= 10;
        length += 1;
    }
    if (n == 0) length = 1;
    if (req(n, length)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}