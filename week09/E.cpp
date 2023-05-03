#include <iostream>

using namespace std;

int main(){
    int N, k ,S;
    cin >> N >> k >> S;
    int*a = new int[S+1];
    for (int i = 0; i < S; i++) cin >> a[i];
    a[S] = N;
    int ans = 0;
    int current = 0;
    int last = -1;
    bool t = true;
    while (current != N){
        int i = S;
        while ((current + k < a[i])&(i > last)) i--;
        if (i == last) {
            t = false;
            break;
        }
        last = i;
        current = a[i];
        if (i !=S) ans++;
    }
    if (t) cout << ans;
    else cout << -1;
    delete [] a;
    }