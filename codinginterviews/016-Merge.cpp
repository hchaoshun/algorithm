/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode dummy(-1);
        ListNode *p = &dummy;
        while (pHead1 != nullptr && pHead2 != nullptr) {
            if (pHead1->val < pHead2->val) {
                p->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                p->next = pHead2;
                pHead2 = pHead2->next;
            }
            p = p->next;
        }
        p->next = (pHead1 == nullptr) ? pHead2 : pHead1;
        return dummy.next;
    }
};
