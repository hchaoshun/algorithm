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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p1 = &dummy;
        ListNode *p2 = p1->next;
        while (p2 != nullptr) {
            int v = p2->val;
            while (p2->next != nullptr && p2->next->val == v)
                p2 = p2->next;
            p1->next = p2;
            p1 = p2;
            p2 = p2->next;
        }
        return dummy.next;
    }
};
