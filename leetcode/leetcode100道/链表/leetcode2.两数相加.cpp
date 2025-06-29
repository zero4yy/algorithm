#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       // 342 + 465 = 807 243 + 564 = 
       // 125 + 367 = 492 
       // 5-2-1
       // 7-6-3
       // 2-9-4
       ListNode *ans = l1;
       int cnt = 0;
        while(l1 && l2) {
            int sum = l1->val + l2->val + cnt;
            l1->val = sum % 10;
            cnt = sum / 10;

            l1 = l1->next, l2 = l2->next;
        }

        if(l1 == nullptr) l1 = l2;
        while(l1) {
            int sum = l1->val + cnt;
            l1->val = sum % 10;
            cnt = sum / 10;

            l1 = l1->next;
        }

        if(cnt == 1) {
            ListNode *node = new ListNode(0);
            l1->next = node;
        }

        return ans;
    }
};

int main() {


    return 0;
}