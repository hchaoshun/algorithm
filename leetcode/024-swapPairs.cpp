/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //依次遍历交换两个指针
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy = ListNode(-1);
        dummy.next = head;
        ListNode *p1 = &dummy;
        ListNode *p2 = nullptr;
        while (p1->next != nullptr && p1->next->next != nullptr) {
            p2 = p1->next;
            p1->next = p2->next;
            p2->next = p2->next->next;
            p1->next->next = p2;
            p1 = p2;
        }
        return dummy.next;
    }
};
