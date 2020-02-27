//dfs问题
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str) {
        bool *visited = new bool[rows * cols]();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(matrix, visited, rows, cols, i, j, 0, str)) {
                    return true;
                }
            }
        }
        delete []visited;
        return false;
    }

private:
    bool dfs(char *matrix, bool *visited, int rows, int cols, 
            int i, int j, int index, char *str) {
        if (index == strlen(str)) return true;
        //以下三步为剪枝
        if (i < 0 || i >= rows || j < 0 || j >= cols) return false;
        if (visited[i * cols + j]) return false;
        if (matrix[i * cols + j] != str[index]) return false;
        
        visited[i * cols + j] = true;
        bool ret = dfs(matrix, visited, rows, cols, i + 1, j, index + 1, str) ||
                   dfs(matrix, visited, rows, cols, i - 1, j, index + 1, str) ||
                   dfs(matrix, visited, rows, cols, i, j + 1, index + 1, str) ||
                   dfs(matrix, visited, rows, cols, i, j - 1, index + 1, str);
        visited[i * cols + j] = false;
        return ret;
    }
};
