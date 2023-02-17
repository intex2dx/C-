#include <iostream>

using namespace std;

bool my_func(int a) {
    bool ans;
    if (a % 4 ==0 & a%100 !=0) ans = true;
    else if (a % 400 == 0) ans = true;
    else ans = false;
    return ans;

}

bool correct_func(int a){
    bool ans;
    if (a % 4 == 0) {
        if (a % 400 == 0) {
            ans = true;
        } else if (a % 100 == 0) {
            ans = false;
        } else {
            ans = true;
        }
    } else {
        ans = false;
    }
    return ans;
}

int main(){
    int t = 1;
    for (int i=0; (i<10000) & (t != 0); i++){
        bool my_ans = my_func(i);
        bool correct_ans = correct_func(i);
        if (my_ans != correct_ans){
            cout << "Failed " << "i" << endl;
            t = 0;
        }
    }
    if (t==1) cout <<"OK";
    return 0;
}