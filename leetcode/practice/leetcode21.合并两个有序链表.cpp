#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        // ListNode* dum = new ListNode(0);
        ListNode dummy(0); // 创建哑节点 方便操作 伪头节点
        ListNode *tail = &dummy; // tail 指向合并后链表的最后一个节点

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // 连接剩余节点
        tail->next = list1 ? list1 : list2;
        // if(list1) tail->next = list1;
        // if(list2) tail->next = list2;

        return dummy.next; 
    }
};

int main() {
    // 测试代码
    // [1,2,4] [1,3,4]
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution sol;
    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    while (mergedList != nullptr) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}