#include <iostream>

struct Node
{
    Node *prev = nullptr;
    Node *next = nullptr;
    int key    = 0;
};

struct List
{
    Node *HEAD  = nullptr;
    Node *TAIL  = nullptr;
    Node *NIL   = nullptr;
    size_t size = 0;
};

List *create_empty_list(){
    List* list = new List;
    Node* nil = new Node;
    list->NIL = nil;
    return list;
}


using std::cout;
using std::endl;

int main() {
    List *list = create_empty_list();
    if ((list->HEAD == nullptr) & (list->TAIL == nullptr) & (list->NIL != nullptr)) {
        cout << "OK" << endl;
    }
    delete list->NIL;
    delete list;
    return 0;
}