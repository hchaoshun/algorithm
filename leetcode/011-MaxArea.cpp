//注意，此题思路和42.接雨水完全不一样,此题用贪心算法
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = height.size() - 1;
        int result = INT_MIN;
        while (left < right) {
            result = max(result, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) ++left;
            else --right;
        }
        return result;
    }
};
