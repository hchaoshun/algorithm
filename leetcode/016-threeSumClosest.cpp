class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int min_gap = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i+1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int gap = abs(sum - target);
                if (gap < min_gap) {
                    min_gap = gap;
                    result = sum;
                }
                if (sum < target) j++;
                else k--;
            }
        }
        return result;
    }
};
