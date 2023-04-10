#include <iostream>



struct Node {
    std::string name;
    Node *next = nullptr;
    Node* prev = nullptr;
};

struct Pair
{
    std::string died_name;
    Node *start;
};

Node* pbfrt(Node *head_ref, std::string new_name) {
    Node* new_node = new Node;
    new_node->name = new_name;
    if (head_ref == nullptr) {
        new_node->next = new_node;
        new_node->prev = new_node;
        head_ref = new_node;
    }
    else {
        new_node->next = head_ref;
        Node* prehead = head_ref->prev;
        new_node->prev = prehead;
        head_ref->prev = new_node;
        prehead->next = new_node;
        
        }
    return head_ref;
}

// Node* search_name(Node* head_ref, std::string name){
//     Node* current = head_ref;
//     while (current->name != name) current = current->next;
//     return current;
// }

Pair remove_next(Node *current_start, int turn){
    Pair res;
    if (current_start == nullptr) {
        res.died_name = "";
        res.start = nullptr;
        return res;
    }
    Node* current = current_start;
    for (int i = 1; i < turn; i++){
        current = current->next;
    }
    res.died_name = current->name;
    if (current->next == current){   
        res.start     = nullptr;
        delete current;
        
        return res;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    res.start = current->next;
    delete current;
    return res;
}

int main(){
    int N, k, ans = 1;
    Node* head = nullptr;
    std::string name;
    std::cin >> N;
    for (int i = 0; i < N; i++){
        std::string new_name;
        std::cin >> new_name;
        head = pbfrt(head, new_name);
    }
    std::cin >> k;
    std::cin >> name;
    Pair res_pair = remove_next(head, k);
    while (res_pair.died_name != name) {
        res_pair = remove_next(res_pair.start, k);
        ans++;
    }
    std::cout<<ans;
}