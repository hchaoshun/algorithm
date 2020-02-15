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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = 0, len2 = 0;
        ListNode *pBak1 = pHead1, *pBak2 = pHead2;
        while (pBak1 != nullptr) {
            len1++;
            pBak1 = pBak1->next;
        }
        while (pBak2 != nullptr) {
            len2++;
            pBak2 = pBak2->next;
        }
        int delta = abs(len1 - len2);
        if (len1 > len2) {
            while (delta-- > 0)
                pHead1 = pHead1->next;
        } else if (len2 > len1) {
            while (delta-- > 0)
                pHead2 = pHead2->next;
        }
        
        while (pHead1 != nullptr && pHead2 != nullptr) {
            if (pHead1 == pHead2) return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return nullptr;
    }
};
