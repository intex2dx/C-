#include <iostream>

struct Node
{
    int key    = 0;
    Node *next = nullptr;
};

void push_front(Node *&head_ref, int new_key) {
    if (head_ref == nullptr) {
        head_ref      = new Node;
        head_ref->key = new_key;
        return;
    }
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

Node *read_list(Node *head) {
    int new_key;
    std::cin >> new_key;
    if (new_key == 0) return head;
    head      = new Node;
    head->key = new_key;
    std::cin >> new_key;
    Node *current = head;
    while (new_key != 0) {
        current->next      = new Node;
        current->next->key = new_key;
        current            = current->next;
        std::cin >> new_key;
    }
    return head;
}

Node *reverse(Node *head) {
    if (head == nullptr) return nullptr;
    Node *current      = head;
    Node *current_next = head->next;
    head->next         = nullptr;
    while (current_next != nullptr) {
        Node *new_current_next = current_next->next;
        current_next->next     = current;
        current                = current_next;
        current_next           = new_current_next;
    }
    return current;
}



int find_middle(const Node *head){
    int k = 1;
    int middle = 0;
    Node* current_next = head->next;
    while (current_next != nullptr) {
        if (k%2 == 0) middle++;
        current_next = current_next->next;
        k+=1;
    }
    if (k%2 == 0) middle++;
    return middle;
}

int main(){
    Node *head = nullptr;
    head     = read_list(head);
    std::cout << find_middle(head);
    destroy_list(head);
    return 0;
}
