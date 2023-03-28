#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Segment{
    int start = 0;
    int end = 0;
    int is_empty = true;
};

void swap(Segment &lha, Segment &rha){
    Segment& tmp = lha;
    lha = rha;
    rha = tmp;
}

Segment cross(Segment first, Segment second){
    if (first.start > second.start) swap(first, second);
    Segment result;
    if (second.start <= first.end){
        result.start = second.start;
        result.end = first.end;
        result.is_empty = false;
    }
    return result;
}

int main(){
   int N;
   cin >> N;
   Segment* sp = new Segment[N];
   for (int i = 0; i < N; i++){
        int start, end;
        cin >> start;
        cin >> end;
        if (start <= end) {
            sp[i].start = start;
            sp[i].end = end;
            sp[i].is_empty = false;
        }
   }
   bool t = true;
   Segment result = sp[0];
   for (int i = 1; i < N; i++){
        if (result.is_empty | sp[i].is_empty) {
            t = false;
            break;
        }
        result = cross(result, sp[i]);
   }
   if (t & !result.is_empty) cout << "YES";
   else cout << "NO";
   cout << endl;
   delete [] sp;
   return 0;
}