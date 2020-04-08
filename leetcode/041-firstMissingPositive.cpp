//由于我们需要依次判断某一个正整数是否在这个数组里，我们可以先把这个数组中所有的元素放进哈希表。接下来再遍历的时候，就可以以 O(1)O(1) 的时间复杂度判断某个正整数是否在这个数组。
//由于题目要求我们只能使用常数级别的空间，而哈希表的大小与数组的长度是线性相关的，因此空间复杂度不符合题目要求。

//用数组代替哈希表，桶排序
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bucketSort(nums);
        for (int i = 0; i < nums.size(); i++) {
            if (i != nums[i]-1)
                return i+1;
        }
        return nums.size() + 1;
    }

private:
    static void bucketSort(vector<int> &nums) {
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] != i+1) {
                //不能用i == nums[i]-1判断，考虑到若i != nums[i]-1,而nums[i] == nums[nums[i]-1]，将会陷入死循环
                if (nums[i] <= 0 || nums[i] > n || nums[i] == nums[nums[i]-1])
                    break;
                swap(nums[i], nums[nums[i]-1]);
            }
        }
    }
};
