//状态方程和最大连续子数组类似，不同的同时维护一个最小乘积，当遇到负数时，交换最大值和最小值
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fma = 1, fmi = 1, result = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) swap(fma, fmi);
            fma = max(fma * nums[i], nums[i]);
            fmi = min(fmi * nums[i], nums[i]);
            result = max(result, fma);
        }
        return result;
    }
};
