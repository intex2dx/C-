#include <iostream>

using namespace std;

void swap(int &lha, int &rha) {
    int tmp = lha;
    lha     = rha;
    rha     = tmp;
}

void sift_up(int* array, int ind) {
    if (array[ind] > array[ind / 2]) {
        swap(array[ind], array[ind / 2]);
        sift_up(array, ind / 2);
    }
}

void sift_down(int* array, int ind, int end) {
    if (2 * ind + 1 <= end) {
        int ind_max = 2 * ind + 1;
        if ((2 * ind + 2 <= end) & (array[2 * ind + 2] > array[2 * ind + 1])) ind_max = 2 * ind + 2;
        if (array[ind] < array[ind_max]) {
            swap(array[ind], array[ind_max]);
            sift_down(array, ind_max, end);
        }
    }
}

void cheops_sort(int* array, int N) {
    for (int end = 0; end < N; end++) {
        sift_up(array, end);
    }
    for (int end = N - 1; end > 0; end--) {
        swap(array[0], array[end]);
        sift_down(array, 0, end - 1);
    }
}

int main(){
    long long S;
    cin >> S;
    int N;
    cin >> N;
    int* a = new int[N];
    for (int i = 0; i < N; i++) cin >> a[i];
    cheops_sort(a, N);
    int ans = 0;
    for (int i = 0; i < N; i++){
        if (S < a[i]) break;
        S-=a[i];
        ans += 1;
    }
    cout << ans;
    delete [] a;


}