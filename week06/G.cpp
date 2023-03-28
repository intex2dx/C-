#include <iostream>
// #include <fstream>

// std::ifstream Fin;

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Atom{
    string name;
    int A;
    int Z;
};

Atom react(string name, string reac, Atom* sp, int N){
    Atom reagent;
    for (int i = 0; i < N; i++){
        if (sp[i].name == name) {
            reagent.A = sp[i].A;
            reagent.Z = sp[i].Z;
            break;
        } 
    }
    if (reac == "beta-") reagent.Z += 1;
    else if (reac == "beta+") reagent.Z -= 1;
    else if (reac == "alpha") {
        reagent.A -= 4;
        reagent.Z -= 2;
    }
    return reagent;
}

int main(){
    // Fin.open("input.txt");
    int N;
    cin >> N;
    Atom* sp = new Atom[N];
    for (int i = 0; i < N; i++){
        cin >> sp[i].name;
        cin >> sp[i].A;
        cin >> sp[i].Z;
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++){
        string name, reac;
        cin >> name;
        cin >> reac;
        Atom result = react(name, reac, sp, N);
        bool t = true;
        for (int j = 0; j < N; j++){
            if ((sp[j].A == result.A) & (sp[j].Z == result.Z)) {
                result.name = sp[j].name;
                t = false;
                break;
            }
        }
        if (t)
            cout << "NO DATA ";
        else
            cout << result.name << " ";
    }


    delete [] sp;
    cout << endl;
    // Fin.close();
    return 0;
}