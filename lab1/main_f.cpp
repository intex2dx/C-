#include <fstream>
#include <chrono>
#include <stdlib.h> 
#include <time.h>
#include <random>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main(){
    cout << endl;
    string a[14] = {
        "test1.exe",
        "test2.exe",
        "test3.exe",
        "test4.exe",
        "tst1.exe",
        "tst2.exe",
        "base_strategy.exe",
        "base_strategy nonnormal.exe",
        "strategyA.exe",
        "strategyA nonnormal.exe",
        "strategyB.exe",
        "strategyB nonnormal.exe",
        "strategyC.exe",
        "strategyC nonnormal.exe"
    };
    for (int i = 8; i < 14; i++){
        cout << a[i] << " started..." << endl;
        system(("C:\\C++\\C-\\lab1\\" + a[i]).c_str());
        cout << a[i] << " finished." << endl;
        cout << endl;
    }
    return 0;
}