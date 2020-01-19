/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        int lena = 0, lenb = 0;
        while (pa != nullptr) {
            ++lena;
            pa = pa->next;
        }
        while (pb != nullptr) {
            ++lenb;
            pb = pb->next;
        }
        int delta = abs(lena - lenb);
        if (lena > lenb) {
            while (delta--) headA = headA->next;
        } else if (lena < lenb) {
            while (delta--) headB = headB->next;
        }
        while (headA != nullptr && headB != nullptr && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
