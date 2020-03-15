//维护一个单调递增的栈s，使得栈顶元素的index代表位置总是栈中最大元素
//依次遍历元素寻找面积最大值
//当i比栈顶还大的元素，i进栈，继续遍历
//当i比栈顶小的元素,弹出栈顶top，计算面积：
//此时i代表右边界位置(因为他是右边第一个小于top的index),弹出后的s.top代表左边界(因为他是左边最后一个小于top的index)
//area = heights[top] * (i - (s.top() + 1)
//继续循环直到栈为空为止
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> s;
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int top = s.top();
                s.pop();
                max_area = max(max_area, heights[top] * (s.empty() ? i : (i - s.top() - 1)));
            }
            s.push(i);
        }
        return max_area;
    }
};
