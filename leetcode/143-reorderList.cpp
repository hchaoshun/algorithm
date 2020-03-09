/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //将链表从中间拆开，然后归并
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode *slow = head, *fast = head;
        ListNode *tmp = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        tmp->next = nullptr;
        fast = reverseList(slow);
        slow = head;
        while (slow != nullptr && fast != nullptr) {
            ListNode *slow1 = slow->next;
            ListNode *fast1 = fast->next;
            slow->next = fast;
            if (slow1 != nullptr)
                fast->next = slow1;
            slow = slow1;
            fast = fast1;
        }
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
