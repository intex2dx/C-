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

void remove(Node *&head_ref) {
    while (head_ref != nullptr) {
        Node *current = head_ref;
        head_ref      = head_ref->next;
        delete current;
    }
}

Node* find(Node *head_ref, int key){
    Node* current = head_ref;
    while (current != nullptr){
        if (current->key == key) break;
        current = current->next;
    }
    return current;
    }

    using std::cout;
    using std::endl;

    int main() {
    Node *HEAD = nullptr, *current = nullptr;
    push_back(HEAD, 0);
    push_back(HEAD, 1);
    push_back(HEAD, 2);
    current = find(HEAD, 2);
    if (current->key == 2) {
        cout << "OK" << endl;
    }
    return 0;
    }