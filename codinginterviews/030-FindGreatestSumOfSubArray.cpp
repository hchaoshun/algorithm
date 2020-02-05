class Solution {
public:
    //sum[i] = max(sum[i-1] + a[i], a[i])
    int FindGreatestSumOfSubArray(vector<int> array) {
        int result = INT_MIN, f = 0;
        for (int i = 0; i < array.size(); i++) {
            f = max(f + array[i], array[i]);
            result = max(result, f);
        }
        return result;
    }
};
