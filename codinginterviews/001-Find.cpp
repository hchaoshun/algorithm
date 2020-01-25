class Solution {
public:
    //从左下角或者右上角查找
    bool Find(int target, vector<vector<int> > array) {
        const int row = array.size();
        const int col = array[0].size();
        bool res = false;
        int i = 0, j = col - 1;
        while (i < row && j >=0) {
            if (array[i][j] == target) {
                res = true;
                break;
            } else if (array[i][j] > target) j--;
            else i++;
        }
        return res;
    }
};
