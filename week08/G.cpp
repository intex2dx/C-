#include <iostream>
#include <string>

int get_argument(){
    std::string input;
    std::getline(std::cin, input,' ');
    if (input == "*") return get_argument() * get_argument();
    if (input == "+") return get_argument() + get_argument();
    return std::stoi(input);
}

int main(){
    int res = get_argument();
    std::string stop;
    std::cin >> stop;
    std::cout << res;
}