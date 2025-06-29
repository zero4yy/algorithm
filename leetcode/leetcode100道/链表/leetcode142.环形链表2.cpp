#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* h = head;
        unordered_set<ListNode*> vt;
        while(h != nullptr) {
            if(vt.contains(h)) return h;

            vt.insert(h);

            h = h->next;
        }

        return nullptr;
    }
};
// 快慢指针
class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        
    }
};
int main() {

    return 0;
}