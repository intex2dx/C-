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


void remove_key(Node *&head_ref, int key){
    if (head_ref == nullptr) return;
    if (head_ref->key == key) {
        Node* new_head = head_ref->next;
        delete head_ref;
        head_ref = new_head;
        return;
    }
    Node* current = head_ref;
    while (current->next != nullptr){
        if (current->next->key == key){
            Node* new_node = current->next->next;
            delete current->next;
            current->next = new_node;
            return;
        }
        current = current->next;
    }
}
using std::cout;
using std::endl;

int main() {
    Node *HEAD = nullptr;
    push_back(HEAD, 0);
    push_back(HEAD, 1);
    push_back(HEAD, 2);
    remove_key(HEAD, 0);
    remove_key(HEAD, 1);
    remove_key(HEAD, 2);
    remove_key(HEAD, 3);
    if (HEAD == nullptr) {
        cout << "OK" << endl;
    }
    return 0;
}