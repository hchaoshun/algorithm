//用hash表存储元素的使用情况是解决问题的关键
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> used;
        for (auto num : nums)
            used[num] = false;
       
        int result = 0;
        for (auto num : nums) {
            if (used[num]) continue;
            int longest = 1;
            used[num] = true;
            for (int j = num+1; used.find(j) != used.end(); ++j) {
                used[j] = true;
                ++longest;
            }
            for (int j = num-1; used.find(j) != used.end(); --j) {
                 used[j] = true;
                ++longest;
            }
            result = max(result, longest);
        }
        return result;
    }
};
