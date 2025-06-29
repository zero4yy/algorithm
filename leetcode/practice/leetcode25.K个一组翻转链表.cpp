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


// 参考https://leetcode.cn/problems/reverse-nodes-in-k-group/solutions/1992228/you-xie-cuo-liao-yi-ge-shi-pin-jiang-tou-plfs
class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode *h = head;
        while(h) {
            n ++;
            h = h->next;
        }

        
        ListNode dummy(0, head);
        ListNode *p0 = &dummy; // p0 保存待反转链表的前一节点
        ListNode *pre = nullptr; // pre 用于反转链表时指向前一个节点
        ListNode *cur = p0->next;
        ListNode *nxt;
        while(n >= k) {
            n -= k;
            for(int i = 0; i < k; i++) {
                nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }

            nxt = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = nxt;
        }
        return dummy.next;
    }
};

int main() {

    return 0;
}

