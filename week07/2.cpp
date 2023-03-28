void push_front(Node *&head_ref, int new_key) {
    if head_ref == nullptr {
        head_ref = new Node;
        head_ref->key = new_key;
        return;
    }
    Node* new_head = new Node;
    new_head->key = new_key;
    new_head->next = head_ref;
    head_ref = new_head;
 }