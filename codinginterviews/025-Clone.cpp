/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (pHead == nullptr) return nullptr;
        RandomListNode *bakHead = pHead;
        RandomListNode *newHead = new RandomListNode(pHead->label);
        RandomListNode *bakNewHead = newHead;
        unordered_map<RandomListNode*, RandomListNode*> hmap;
        hmap[pHead] = newHead;
        
        while (pHead->next != nullptr) {
            pHead = pHead->next;
            newHead->next = new RandomListNode(pHead->label);
            newHead = newHead->next;
            hmap[pHead] = newHead;
        }
        
        RandomListNode *result = bakNewHead;
        while (bakHead != nullptr) {
            bakNewHead->random = hmap[bakHead->random];
            bakNewHead = bakNewHead->next;
            bakHead = bakHead->next;
        }
        return result;
    }
};
