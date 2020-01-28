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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *p1 = nullptr, *p2 = pHead;
        while (p2 != nullptr) {
            ListNode *tmp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = tmp;
        }
        return p1;
    }
};
