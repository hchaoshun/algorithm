//如存在区间[left,right]，使得在[left,right]这个区间的子数组的和为k。换句话说，就是前right项和减去前left项和等于k，即前left项和等于前right项和减去k。
//可以这样做，在扫描数组的同时，假设当前扫到第i位，记录它的前i项和sum，用该和减去k，即sum-k，判断sum-k是否为某个位置的前n项和，若是，更新统计量。

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum;
        int result = 0;
        int sum = 0;
        prefix_sum[0] = 1;
        for (auto n : nums) {
            sum += n;
            if (prefix_sum.find(sum - k) != prefix_sum.end()) result += prefix_sum[sum - k];
            prefix_sum[sum]++;
        }
        return result;
    }
};
