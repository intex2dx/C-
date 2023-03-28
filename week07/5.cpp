
#include <iostream>
struct Node
{
    int key    = 0;
    Node *next = nullptr;
};

void push_back(Node *&head_ref, int new_key) {
    if (head_ref == nullptr) {
        head_ref      = new Node;
        head_ref->key = new_key;
        return;
    }
    Node *current = head_ref;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next      = new Node;
    current->next->key = new_key;
}

void destroy_list(Node *&head_ref) {
    while (head_ref != nullptr){
        Node* current = head_ref;
        head_ref = head_ref->next;
        delete current;
    }
}

using std::cout;
using std::endl;

int main() {
    Node *HEAD = nullptr;
    push_back(HEAD, 0);
    push_back(HEAD, 1);
    push_back(HEAD, 2);
    destroy_list(HEAD);
    if (HEAD == nullptr) {
        cout << "OK" << endl;
    }
    return 0;
}