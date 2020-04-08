class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, int> count;
        int res = 0;
        for (int i = 0; i < n; i++) {
            count[nums[i]]++;
            if (count[nums[i]] > n/2) {
                res = nums[i];
                break;
            }
        }
        return res;
    }
};
