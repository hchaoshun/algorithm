/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //两个指针分别记录小于x的节点和大于等于x的节点，最后将两个指针连接起来
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left_dummy(-1);
        ListNode right_dummy(-1);
        ListNode *left_cur = &left_dummy;
        ListNode *right_cur = &right_dummy;

        for (ListNode *cur = head; cur != nullptr; cur = cur->next) {
            if (cur->val < x) {
                left_cur->next = cur;
                left_cur = cur;
            } else {
                right_cur->next = cur;
                right_cur = cur;
            }
        }

        left_cur->next = right_dummy.next;
        right_cur->next = nullptr;
        right_dummy.next = nullptr;
        return left_dummy.next;
    }
};
