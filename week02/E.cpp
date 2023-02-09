#include <iostream>

using namespace std;

long int fibonacci(int i){
    if (i == 0 | i == 1) return 1;
    else return fibonacci(i-1) + fibonacci(i - 2);
}

int main(){
    int i;
    cin >> i;
    cout << fibonacci(i) << endl;
    return 0;
}