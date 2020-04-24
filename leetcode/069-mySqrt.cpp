//二分查找
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int left = 1, right = x / 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long res = (long long)mid * mid;
            if (res < x) left = mid+1;
            else if (x < res) right = mid-1;
            else return mid;
        }
        return right;
    }
};
