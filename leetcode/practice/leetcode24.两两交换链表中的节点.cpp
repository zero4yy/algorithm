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

// 1. 迭代
class Solution
{
public:
    ListNode* swapPairs (ListNode* head) {
        ListNode dummy(0, head);
        ListNode *node0 = &dummy;
        ListNode *node1 = head;
        ListNode *node2, *node3;
        while(node1 && node1->next) {
            node2 = node1->next;
            node3 = node2->next;

            node0->next = node2;
            node2->next = node1;
            node1->next = node3;

            node0 = node1;
            node1 = node3;
        }
        
        return dummy.next;
    }
};


// 2.递归
class Solution
{
public:
    ListNode* swapPairs (ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode *node1 = head;
        ListNode *node2 = node1->next;
        ListNode *node3 = node2->next;
        
        node1->next = swapPairs(node3);
        node2->next = node1;

        return node2;
    }
};
int main() {

    return 0;
}