#include <iostream>

int main(){
    int summ = 0;
    char c;
    for (c = std::getchar(); (c!='\n')&(c!='\0'); c = std::getchar()){
        if (c == '(') summ++;
        else summ--;
        if (summ < 0) break;  
    }
    if (summ == 0) std::cout<<"YES";
    else std::cout<<"NO";
    std::cout<<std::endl;
}