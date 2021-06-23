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
    ListNode* deleteDuplication(ListNode* pHead) {
        ListNode dummy(-1);
        dummy.next = pHead;
        ListNode *p1 = &dummy;
        ListNode *p2 = p1->next;
        
        while (p2 != nullptr && p2->next != nullptr) {
            if (p2->val == p2->next->val) {
                int val = p2->val;
                while (p2 != nullptr && p2->val == val)
                    p2 = p2->next;
                p1->next = p2;
            } else {
                p1 = p2;
                p2 = p2->next;
            }
        }
        return dummy.next;
    }
};

//用flag表示是否需要删除
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        ListNode dummy = ListNode(-1);
        dummy.next = pHead;
        ListNode* p1 = &dummy;
        ListNode* p2 = pHead;
        bool flag = false;
        while (p2 != nullptr) {
            if (p2->next != nullptr && p2->next->val != p2->val) {
                if (flag == true) {
                    p1->next = p2->next;
                    flag = false;
                } else {
                    p1 = p2;
                }

            } else if (p2->next != nullptr && p2->next->val == p2->val) {
               flag = true;
            }
            p2 = p2->next;
        }
        //可能会出现最后一次没有删除
        if (flag == true) {
            p1->next = p2;
        }
        return dummy.next;
    }
};
