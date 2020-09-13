class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    size_t row = grid.size();
    size_t col = grid[0].size();

    vector<vector<bool>> visited(row, vector<bool>(col, false));
    size_t count = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        //从陆地开始dfs
        if (!visited[i][j] && grid[i][j] == '1') {
          ++count;
          dfs(grid, visited, i, j, row, col);
        }
      }
    }
    return count;
  }

 private:
  void dfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited,
           int i, int j, const int row, const int col) {
    //越界，返回
    if (i < 0 || i >= row || j < 0 || j >= col) return;
    //不是陆地，返回
    if (grid[i][j] == '0') return;
    //已经走过，返回
    if (visited[i][j]) return;
    visited[i][j] = true;
    dfs(grid, visited, i+1, j, row, col);
    dfs(grid, visited, i-1, j, row, col);
    dfs(grid, visited, i, j+1, row, col);
    dfs(grid, visited, i, j-1, row, col);
  }
};
