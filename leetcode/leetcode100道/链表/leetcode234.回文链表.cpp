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
    bool isPalindrome(ListNode* head) {
        ListNode *h = head;
        const int N = 100010;
        int a[N], cnt = 0;
        while(h != nullptr) {
            a[cnt++] = h->val;
            h = h->next;
        }
        
        // for(int i = 0, j = cnt - 1;)
    }
};
class Solution1
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *h = head;
        stack<int> st;
        if (h->next == nullptr)
            return true;
        while (h != nullptr)
        {
            st.push(h->val);
            h = h->next;
        }

        h = head;
        while (h != nullptr)
        {
            if (st.top() == h->val)
            {
                st.pop();
                h = h->next;
            }
            else
                return false;
        }
        return true;
    }
};

int main() {

    return 0;
}