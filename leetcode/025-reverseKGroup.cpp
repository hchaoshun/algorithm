//以k为一组依次翻转
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pred = &dummy, *end = &dummy;
        ListNode *start = nullptr;
        ListNode *next = nullptr;
        while (pred->next != nullptr) {
            for (int i = 0; i < k && end != nullptr; i++) {
                end = end->next;
            }
            if (end == nullptr) break;
            start = pred->next;
            next = end->next;
            end->next = nullptr;
            end = reverseList(start);
            pred->next = end;
            start->next = next;
            pred = start;
            end = pred;
        }
        return dummy.next;
    }

    ListNode *reverseList(ListNode *root) {
        ListNode *p1 = nullptr;
        ListNode *p2 = root;
        while (p2 != nullptr) {
            ListNode *p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }
};
