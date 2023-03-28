void push_back(Node *&head_ref, int new_key){
    if (head_ref == nullptr){
        head_ref = new Node;
        head_ref->key = new_key;
        return;
    }
    Node* current = head_ref;
    while (current->next != nullptr){
        current = current->next;
    }
    current->next = new Node;
    current->next->key = new_key;
}