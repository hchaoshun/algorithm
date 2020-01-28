class Solution {
public:
    //考虑指针越界情况
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (k == 0) return nullptr;
        ListNode *p1 = pListHead, *p2 = pListHead;
        while (--k > 0 && p2 != nullptr) {
            //if (p2 == nullptr) return nullptr;
            p2 = p2->next;
        }
        if (p2 == nullptr) return nullptr;
        while (p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
