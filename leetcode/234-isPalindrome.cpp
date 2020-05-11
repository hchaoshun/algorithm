class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *p2 = reverseList(slow);
        ListNode *p1 = head;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val == p2->val) {
                p1 = p1->next;
                p2 = p2->next;
            } else {
                return false;
            }
        }
        return true;
    }

private:
    ListNode *reverseList(ListNode *head) {
        ListNode *p1 = nullptr, *p2 = head;
        while (p2 != nullptr) {
            ListNode *p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }
};
