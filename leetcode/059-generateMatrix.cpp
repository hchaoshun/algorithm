class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int left = 0, right = n-1, up = 0, down = n-1;
        int count = 1, target = n * n;
        while (count <= target) {
            for (int i = left; i <= right; i++) result[up][i] = count++;
            up++;
            for (int i = up; i <= down; i++) result[i][right] = count++;
            right--;
            for (int i = right; i >= left; i--) result[down][i] = count++;
            down--;
            for (int i = down; i >= up; i--) result[i][left] = count++;
            left++;
        }
        return result;
    }
};
