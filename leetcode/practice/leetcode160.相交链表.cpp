#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 
class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            int alen = 0, blen = 0;
            ListNode * a = headA;
            ListNode * b = headB;
            while(a != nullptr) {
                a = a->next; alen++;
            }
            while(b != nullptr) {
                b = b->next; blen++;
            }
            if(alen < blen) {
                int ch = blen - alen;
                while(ch --) headB = headB->next;
            } else {
                int ch = alen - blen;
                while(ch --) headA = headA->next;
            }
    
            while(headA != headB) {
                headA = headA->next;
                headB = headB->next;
            }
            
            return headA;
        }
    };

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        while(A != B) {
            A = (A != nullptr) ? A->next : headB;
            B = (B != nullptr) ? B->next : headA;
        }
        return A;
    }
};

int main() {

    return 0;
}