#include <iostream>
// #include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Students
{
    string name;
    int score;
};

void swap(Students &lha, Students &rha) {
    Students tmp = lha;
    lha     = rha;
    rha     = tmp;
}

bool less(Students first, Students second){
    return (first.score < second.score) | ((first.score == second.score) & (first.name < second.name));
}

bool gtr(Students first, Students second){
    return (first.score > second.score) | ((first.score == second.score) & (first.name > second.name));
}

void qsort(Students* array,  int ind_left_base, int ind_right_base) {
    if (ind_left_base < ind_right_base) {
        Students pivot    = array[(ind_left_base + ind_right_base) / 2];
        int ind_left = ind_left_base, ind_right = ind_right_base;
        while (ind_left <= ind_right) {
            while (less(array[ind_left],pivot))
                ind_left++;
            while (gtr(array[ind_right], pivot))
                ind_right--;
            if (ind_left >= ind_right) break;
            swap(array[ind_left++], array[ind_right--]);
        }

        qsort(array, ind_left_base, ind_right);
        qsort(array, ind_right + 1, ind_right_base);
    }
}

int main(){
    // std::ifstream Fin;
    // Fin.open("input.txt");
    int N, M;
    cin >> N;
    Students* sp = new Students[N]; 
    for (int i = 0; i < 10; i++) {
        cin >> sp[i].name;
        cin >> sp[i].score;
    }
    cin >> M;
    qsort(sp, 0, N-1);
    bool t = 1;
    for (int i = 0; i < N; i++){
        if (sp[i].score >= M) {
            if (t) {
                cout << sp[i].name;
                t = 0;
            }
            else cout << " " << sp[i].name;
        }
    }
    cout << endl;
    // Fin.close();
    delete [] sp;
    return 0;
}
