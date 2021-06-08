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


//2021-06-04
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int push = 0, pop = 0;
        stack<int> s;
        while (pop < popV.size()) {
            if (push < pushV.size() && pushV[push] != popV[pop]) {
                if (!s.empty() && popV[pop] == s.top()) {
                    s.pop();
                    ++pop;
                } else {
                    s.push(pushV[push]);
                    ++push;
                }
            } else if (push < pushV.size() && pushV[push] == popV[pop]) {
                ++push;
                ++pop;
            } else {
                if (!s.empty() && s.top() == popV[pop]) {
                    s.pop();
                    ++pop;
                }  else {
                    return false;
                }
            }    
        }
        return s.empty();
    }
};
