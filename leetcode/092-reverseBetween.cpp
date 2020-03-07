/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //头插法，每次将下一个节点插入头结点
 //1-2-3-4-5
 //1-3-2-4-5
 //1-4-3-2-5
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy;
        for (int i = 1; i < m; i++)
            prev = prev->next;
        ListNode *curr = prev->next;
        for (int i = m; i < n; i++) {
            ListNode *succ = curr->next;
            curr->next = succ->next;
            succ->next = prev->next;
            prev->next = succ;
        }
        return dummy.next;
    }
};
