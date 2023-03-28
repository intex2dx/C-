#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Time{
    int seconds = 0;
    int minutes = 0;
    int hours = 0;
};

Time addition(Time first, Time second){
    Time result;
    result.seconds = first.seconds + second.seconds;
    result.minutes = first.minutes + second.minutes + result.seconds / 60;
    result.seconds %= 60;
    result.hours = first.hours + second.hours + result.minutes / 60;
    result.minutes %= 60;
    result.hours %= 24;
    return result;
}

int main(){
    Time start, duration;
    cin >> start.hours;
    cin >> start.minutes;
    cin >> start.seconds;
    cin >> duration.hours;
    cin >> duration.minutes;
    cin >> duration.seconds;
    Time result = addition(start, duration);
    cout << result.hours << ":" << result.minutes << ":" << result.seconds;
    cout << endl;
    return 0;
}