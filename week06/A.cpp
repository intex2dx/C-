#include <iostream>

struct Students{
    std::string name;
    int score;
};

int main(){
    Students sp[10];
    for (int i = 0; i < 10; i++) {
        std::cin >> sp[i].name;
        std::cin >> sp[i].score;
    }
    bool t = 1;
    int M;
    std::cin >> M;
    for (int i = 0; i < 10; i++){
        if (sp[i].score >= M){
            if (t) {
                std::cout << sp[i].name;
                t = 0;
    }
            else std::cout << " " << sp[i].name;
}}
    std::cout << std::endl;
    return 0;
}