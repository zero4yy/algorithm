#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        for(Node *cur = head; cur; cur = cur->next->next) {
            Node *tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
        }

        for(Node *cur = head; cur; cur = cur->next->next) {
            if(cur->random) {
                cur->next->random = cur->random->next;
            }
        }
        
        Node *new_head = head->next;
        Node *cur = head;

        for(; cur->next->next; cur = cur->next) {
            Node *new_cur = cur->next;
            cur->next = new_cur->next;
            new_cur->next = new_cur->next->next;
        }
        cur->next = nullptr;

        return new_head;
    }
};

int main() {

    return 0;
}