//是否和下一个节点值相等要分开处理
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p1 = &dummy;
        ListNode *p2 = p1->next;
        while (p2 != nullptr && p2->next != nullptr) {
            if (p2->val == p2->next->val) {
                int v = p2->val;
                while (p2 != nullptr && p2->val == v)
                    p2 = p2->next;
                p1->next = p2;
            } else {
                p1 = p2;
                p2 = p2->next;
            }
        }
        return dummy.next;
    }
};
