class Solution {
public:
    //模拟栈混洗过程
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int push = 0, pop = 0;
        while (push < pushV.size() || pop < popV.size()) {
            if (!s.empty() && s.top() == popV[pop]) {
                s.pop();
                pop++;
            } else {
                s.push(pushV[push++]);
            }
        }
        return s.empty();
    }
};
