class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        const int row = matrix.size();
        if (row == 0) return result;
        const int col = matrix[0].size();
        int left = 0, right = col;
        int up = 0, down = row;
        int max_count = row * col, count = 0;
        while (count < max_count) {
            for (int i = left; i < right && count < max_count; ++i) {
                result.push_back(matrix[up][i]);
                count++;
            }
            up++;
            for (int i = up; i < down && count < max_count; ++i) {
                result.push_back(matrix[i][right-1]);
                count++;
            }
            right--;
            for (int i = right-1; i >= left && count < max_count; --i) {
                result.push_back(matrix[down-1][i]);
                count++;
            }
            down--;
            for (int i = down-1; i >= up && count < max_count; --i) {
                result.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }
        return result;
    }
};
