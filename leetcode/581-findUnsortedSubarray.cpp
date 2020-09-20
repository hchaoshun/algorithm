//将数组 numsnums 进行排序，记为 nums_sortednums_sorted 。然后我们比较 numsnums 和 nums\_sortednums_sorted 的元素来决定最左边和最右边不匹配的元素。它们之间的子数组就是要求的最短无序子数组。

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        auto sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int len = nums.size();
        int start = len - 1, end = 0;
        for (int i = 0; i < len; ++i) {
            if (sorted_nums[i] != nums[i]) {
                start = min(start, i);
            }
            if (sorted_nums[len-i-1] != nums[len-i-1]) {
                end = max(end, len-i-1);
            }
        }
        return end - start > 0 ? end - start + 1 : 0;
    }
};
