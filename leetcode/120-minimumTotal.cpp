//dp问题,自底向上记录记录最小和
//f[i][j]表示i,j位置到低的最小路径和，则f[i][j] = f[i][j] + min(f[i+1][j], f[i+1]j+1])
//每一个节点的下一个临近位置只能是j和j+1
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < i + 1; j++) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
