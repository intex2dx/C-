#include <iostream>

struct Node
{
    int key    = 0;
    Node *next = nullptr;
};

void push_front(Node *&head_ref, int new_key) {
    Node *new_head = new Node;
    new_head->key  = new_key;
    new_head->next = head_ref;
    head_ref       = new_head;
}

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

void insert_after(Node *&prev_ref, int new_key) {
    if (prev_ref == nullptr) {
        return;
    }
    Node *new_node = new Node;
    new_node->key  = new_key;
    new_node->next = prev_ref->next;
    prev_ref->next = new_node;
}

void destroy_list(Node *&head_ref) {
    while (head_ref != nullptr) {
        Node *current = head_ref;
        head_ref      = head_ref->next;
        delete current;
    }
}

void print_list(Node *head_ref) {
    if (head_ref == nullptr) {
        std::cout << std::endl;
        return;
    }
    std::cout << head_ref->key;
    Node *current = head_ref;
    while (current->next != nullptr) {
        std::cout << " " << current->next->key;
        current = current->next;
    }
    std::cout << std::endl;
}

Node *find(Node *head_ref, int key) {
    Node *current = head_ref;
    while (current != nullptr) {
        if (current->key == key) break;
        current = current->next;
    }
    return current;
}

void remove_key(Node *&head_ref, int key) {
    if (head_ref == nullptr) return;
    if (head_ref->key == key) {
        Node *new_head = head_ref->next;
        delete head_ref;
        head_ref = new_head;
        return;
    }
    Node *current = head_ref;
    while (current->next != nullptr) {
        if (current->next->key == key) {
            Node *new_node = current->next->next;
            delete current->next;
            current->next = new_node;
            return;
        }
        current = current->next;
    }
}

int main(){
    char c;
    Node* head_ref = nullptr;
    bool t = true;
    for (c = std::getchar(); (c != '\n') & (c != '\0'); c = std::getchar()) {
        if (c == '(') {
            push_front(head_ref, 0);}

        if (c == '<') push_front(head_ref, 1);
        if (c == '[') push_front(head_ref, 2);
        if (c == '{') push_front(head_ref, 3);
        if (c == ')') {
            if ((head_ref == nullptr) | (head_ref->key != 0)) {
                t = false;
                break;
            }
            head_ref = head_ref->next;
            
        }
        if (c == '>') {
            if ((head_ref == nullptr) | (head_ref->key != 1)) {
                t = false;
                break;
            }
            head_ref = head_ref->next;
        }
        if (c == ']') {
            if ((head_ref == nullptr) | (head_ref->key != 2)) {
                t = false;
                break;
            }
            head_ref = head_ref->next;
        }
        if (c == '}'){
            if ((head_ref == nullptr) | (head_ref->key != 3)) {
                t = false;
                break;
            }
            head_ref = head_ref->next;
        }
    }
    if ((t) & (head_ref == nullptr))
        std::cout << "YES";
    else
        std::cout << "NO";
    std::cout << std::endl;
    destroy_list(head_ref);
    }

