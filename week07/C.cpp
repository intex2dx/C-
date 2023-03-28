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

List *create_empty_list() {
    List *list = new List;
    Node *nil  = new Node;
    list->NIL  = nil;
    return list;
}

List* push_front(List *list_ptr, int new_key){
    if (list_ptr == nullptr) return nullptr;
    Node *head = new Node;
    head->key = new_key;
    head->next = list_ptr->HEAD;
    list_ptr->HEAD = head;
    if (list_ptr->HEAD->next == nullptr) list_ptr->TAIL = head; 
    return list_ptr;
    }

    using std::cout;
    using std::endl;

    int main() {
        List *list = create_empty_list();
        list       = push_front(list, 0);
        if (list->HEAD == nullptr) cout << "F";
        if ((list->HEAD->key == 0) & (list->TAIL->key == 0)) {
            cout << "OK" << endl;
        }
        delete list->HEAD;
        delete list->NIL;
        delete list;
        return 0;
    }