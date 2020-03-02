//自左向右的贪心算法
//不断记录从左边0号index元素向右能访问到的最远的index(每一个位置能访问到的距离是i + nums[i])
//但首先要确保当前的元素是可能访问到的(i <= m)
//一旦找到max >= len - 1,则终止
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 2) return true;
        const int n = nums.size();
        int m = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i > m) return false;
            m = max(m, i + nums[i]);
            if (m >= n - 1) return true;
        }
        return m >= n - 1;
    }
};
