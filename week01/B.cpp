#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a=0, b=0, c=0;
    cin>>a>>b>>c;
    if (a!=0) {
    int D = b*b-4*a*c;
    if (D<0) cout<<endl;
    else if (D==0) cout<<(-b/(2*a))<<endl;
    else cout<<((-b-sqrt(D))/(2*a))<<' '<<((-b+sqrt(D))/(2*a))<<endl;}
    else if (b!=0) {
        cout << -c/b << endl;
    }
    else {
        cout << endl;
    }
    return 0;
}
