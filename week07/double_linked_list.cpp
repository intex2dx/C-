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
    list->HEAD = nil;
    list->TAIL = nil;
    return list;
}

List *push_front(List *list_ptr, int new_key) {
    if (list_ptr == nullptr) return nullptr;
    list_ptr->size += 1;
    Node *head           = new Node;
    head->key            = new_key;
    head->next           = list_ptr->HEAD;
    head->prev           = list_ptr->NIL;
    list_ptr->HEAD->prev = head;
    list_ptr->HEAD       = head;
    if (list_ptr->HEAD->next == list_ptr->NIL) {
        list_ptr->TAIL = head;
    } else if (list_ptr->HEAD->next->next == list_ptr->NIL) {
        list_ptr->TAIL = list_ptr->HEAD->next;
    }
    return list_ptr;
}

List *push_back(List *list_ptr, int new_key) {
    if (list_ptr == nullptr) return nullptr;
    list_ptr->size += 1;
    Node *tail           = new Node;
    tail->next           = list_ptr->NIL;
    tail->prev           = list_ptr->TAIL;
    tail->key            = new_key;
    list_ptr->TAIL->next = tail;
    list_ptr->TAIL       = tail;
    if (list_ptr->TAIL->prev == list_ptr->NIL)
        list_ptr->HEAD = tail;
    else if (list_ptr->TAIL->prev->prev == list_ptr->NIL)
        list_ptr->HEAD = list_ptr->TAIL->prev;
    return list_ptr;
}

List *insert_after(List *list_ptr, Node *prev_ptr, int new_key) {
    if (list_ptr == nullptr) return nullptr;
    if ((prev_ptr == nullptr) | (prev_ptr == list_ptr->NIL)) return list_ptr;
    Node *new_elem       = new Node;
    new_elem->key        = new_key;
    new_elem->prev       = prev_ptr;
    new_elem->next       = prev_ptr->next;
    prev_ptr->next       = new_elem;
    new_elem->next->prev = new_elem;
    if (prev_ptr == list_ptr->TAIL) list_ptr->TAIL = new_elem;
    return list_ptr;
}

void print_list(const List *list_ptr) {
    if (list_ptr != nullptr) {
        if (list_ptr->HEAD != list_ptr->NIL) {
            Node *current = list_ptr->HEAD;
            bool t        = true;
            while (current != list_ptr->TAIL) {
                if (t) {
                    std::cout << current->key;
                    t = false;
                } else
                    std::cout << " " << current->key;

                current = current->next;
            }
            if (t)
                std::cout << current->key;
            else
                std::cout << " " << current->key;
        }
    }
    std::cout << std::endl;
}

void clear_list(List *list_ptr) {
    if (list_ptr == nullptr) return;
    Node *current = list_ptr->HEAD;
    while (current != list_ptr->NIL) {
        Node *new_current = current->next;
        delete current;
        current = new_current;
    }
    list_ptr->HEAD = list_ptr->NIL;
    list_ptr->TAIL = list_ptr->NIL;
    list_ptr->size = 0;
}

void destroy_list(List *list_ptr) {
    if (list_ptr == nullptr) return;
    Node *current = list_ptr->HEAD;
    while (current != list_ptr->NIL) {
        Node *new_current = current->next;
        delete current;
        current = new_current;
    }
    delete list_ptr->NIL;
    delete list_ptr;
}

Node *find_key(List *list_ptr, int key) {
    Node *current = list_ptr->HEAD;
    while ((current->key != key) & (current != list_ptr->NIL))
        current = current->next;
    return current;
}