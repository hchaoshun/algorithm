/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode *slow = pHead, *fast = pHead;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (fast == nullptr || fast->next == nullptr) return nullptr;
        int len = 1;
        fast = fast->next;
        while (slow != fast) {
            len++;
            fast = fast->next;
        }
        
        fast = pHead;
        slow = pHead;
        while (len-- > 0) fast = fast->next;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (pHead == nullptr || pHead->next == nullptr) return nullptr;
        ListNode *p1 = pHead;
        ListNode *p2 = pHead->next;
        while (p2 != nullptr) {
            p1->next = nullptr;
            p1 = p2;
            p2 = p2->next;
        }
        return p1;
    }
};
