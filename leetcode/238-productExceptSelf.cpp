//会超时
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        const int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int num = 1;
            for (int j = 0; j < i; j++)
                num *= nums[j];
            for (int k = i+1; k < n; k++)
                num *= nums[k];
            result.push_back(num);
        }
        return result;
    }
};

//动态规划，左右计算两次
//0     1      2      3
//1     2      3      4
//1     1      1*2    1*2*3
//2*3*4 3*4    4      1
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = 1;
        right[n-1] = 1;
        for (int i = 1; i < n; i++) {
            left[i] = left[i-1] * nums[i-1];
            right[n-i-1] = right[n-i] * nums[n-i];
        }
        for (int i = 0; i < n; i++) {
            result.push_back(left[i] * right[i]);
        }
        return result;
    }
};
