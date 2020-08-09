class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const size_t m = matrix.size();
        if (m == 0) return false;
        const size_t n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};
