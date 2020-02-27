class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count = 0;
        dfs(count, threshold, rows, cols, visited, 0, 0);
        return count;
    }
    
private:
    void dfs(int &count, int threshold, int rows, int cols, vector<vector<bool>> &visited, 
             int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) return;
        if (visited[i][j]) return;
        visited[i][j] = true;
        if (Sum(i) + Sum(j) <= threshold) count++;
        else return;
        dfs(count, threshold, rows, cols, visited, i + 1, j);
        dfs(count, threshold, rows, cols, visited, i - 1, j);
        dfs(count, threshold, rows, cols, visited, i, j + 1);
        dfs(count, threshold, rows, cols, visited, i, j - 1);
    }
    
private:
    int Sum(int i) {
        int result = 0;
        while (i != 0) {
            result += i % 10;
            i /= 10;
        }
        return result;
    }
};
