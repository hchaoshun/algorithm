//注意第K大的元素是排序数组中从右往左数第k个元素
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums, k, 0, nums.size());
    }

private:
    template <typename T>
    int quickSort(vector<T> &nums, int k, int lo, int hi) {
        int mid = partition(nums, lo, hi - 1);
        if (mid == (nums.size() - k))
            return nums[mid];
        else if (mid < (nums.size() - k))
            return quickSort(nums, k, mid+1, hi);
        else 
            return quickSort(nums, k, lo, mid);
    }

    template <typename T>
    int partition(vector<T> &nums, int lo, int hi) {
        swap(nums[lo], nums[lo + rand()%(hi - lo + 1)]);
        T pivot = nums[lo];
        while (lo < hi) {
            while (lo < hi && pivot <= nums[hi]) hi--;
            nums[lo] = nums[hi];
            while (lo < hi && nums[lo] <= pivot) lo++;
            nums[hi] = nums[lo]; 
        }
        nums[lo] = pivot;
        return lo;
    }
};
