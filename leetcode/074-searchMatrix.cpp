//matrix[x][y] = array[x*n + y]
//array[x] = matrix[x/n][x%n]
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int first = 0;
        int last = m*n;
        while (first < last) {
            int mid = first + (last - first) / 2;
            int num = matrix[mid/n][mid%n];
            if (num == target) return true;
            else if (target < num) last = mid;
            else first = mid + 1;
        }
        return false;
    }
};
