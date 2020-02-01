class Solution {
public:
    void push(int value) {
        s.push(value);
        if (min_s.empty() || value < min_s.top())
            min_s.push(value);
        else min_s.push(min_s.top());
    }
    void pop() {
        s.pop();
        min_s.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return min_s.top();
    }
private:
    stack<int> s;
    stack<int> min_s;
};
