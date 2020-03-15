//复用84题的方法，对每一行都求出每个元素对应的高度，这个高度就是对应的连续1的长度，
//然后对每一行都更新一次最大矩形面积。那么这个问题就变成了Largest Rectangle in Histogram
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int area = 0;
        vector<int> heights(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights[j] = (matrix[i][j] == '1' ? heights[j] + 1 : 0);
            }
            area = max(area, largestArea(heights));
        }
        return area;
    }

    int largestArea(vector<int> heights) {
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
