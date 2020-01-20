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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (fast == nullptr || fast->next == nullptr) return nullptr;
        int len = 1;
        fast = fast->next;
        while (slow != fast) {
            fast = fast->next;
            ++len;
        }
        slow = head;
        fast = head;
        while (len--) fast = fast->next;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
