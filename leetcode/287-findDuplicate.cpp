class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        int len = 1;
        slow = nums[slow];
        while (slow != fast) {
            slow = nums[slow];
            len++;
        }
        slow = nums[0], fast = nums[0];
        for (int i = 0; i < len; i++) {
            fast = nums[fast];
        }
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
