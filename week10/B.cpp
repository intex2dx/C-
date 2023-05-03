#include <iostream>

using namespace std;

int main(){
    int prices[10]   = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int a[10] = {1,5,8,9,10,17,17,20,24, 30};
    int variants[10] = {0};
    int n;
    cin>>n;
    if (n > 10){
        int i = 11;
        while (i <= n){
            int last = a[9];
            for (int j = 0; j < 10; j++){
                variants[j] = a[9-j] + prices[j];
            }
            int maximum = 0;
            for (int j = 0; j< 10; j++){
                maximum = max(maximum, variants[j]);
            }
            a[9] = maximum;
            for (int j = 0; j < 8; j++){
                a[j] = a[j+1];
            }
            a[8] = last;
            i++;
        }
        cout << a[9];
    }
    else cout<<a[n];
}