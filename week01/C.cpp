#include <iostream>

using namespace std;

int main(){
    int n=0, m=0;
    cin>>n;
    m = 1;
    for (int i=1; i<=n;i++) m *= i;
    cout<<m<<endl;
    return 0;
}
