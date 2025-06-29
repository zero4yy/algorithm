#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 1. 迭代
class Solution
{
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *pre = nullptr, *nxt;
        while(cur != nullptr) {
            nxt = cur->next; // 暂存后继节点
            cur->next = pre; // 修改 next 指向
            pre = cur;         // pre 暂存 cur
            cur = nxt;         // cur 访问下一节点
        }
        return pre;
        // 最终 pre 指向尾节点(反转后链表的头节点) cur 指向 nullptr
    }
};

int main() {

    return 0;
}