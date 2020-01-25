class Solution {
public:
    //二分查找
    int minNumberInRotateArray(vector<int> rotateArray) {
        //  如果把排序数组前面0个元素搬到后面，也就是说其实没有旋转，
        //  那么第0个元素就是最小的元素
        //  因此我们将mid初始化为0
        int mid = 0;
        //第一个指针总是指向前面递增数组的元素，而第二个指针总是指向后面递增数组的元素
        int low = 0, high = rotateArray.size() - 1;
        while (rotateArray[low] >= rotateArray[high]) {
            //  如果前一个元素与后一个元素差一位
            //  说明找到了最大最小的元素
            if (high - low < 2) {
                mid = high;
                break;
            }
            mid = (low + high) >> 1;
            if (rotateArray[mid] >= rotateArray[low]) {
                low = mid;
            } else if (rotateArray[mid] <= rotateArray[high]) {
                high = mid;
            }
        }
        return rotateArray[mid];
    }
};
