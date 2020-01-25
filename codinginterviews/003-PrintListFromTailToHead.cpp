/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        stack<int> s;
        while (head != nullptr) {
            s.push(head->val);
            head = head->next;
        }
        while (!s.empty()) {
            int num = s.top();
            s.pop();
            result.push_back(num);
        }
        return result;
    }
};
