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
    bool hasCycle(ListNode* head) {
        ListNode* h = head;
        unordered_set<ListNode*> vt;
        while(h != nullptr) {
            if(vt.contains(h)) return true;

            vt.insert(h);

            h = h->next;
        }

        return false;
    }
};
// 快慢指针
class Solution2 {
public:
    bool hasCycle(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }
};
int main() {

    return 0;
}