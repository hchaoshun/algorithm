//维护一个大顶堆
class Solution {
public:
    using Pair = pair<int, int>;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.size() == 0 || k <= 0) return result;
        priority_queue<Pair> max_heap;
        for (int i = 0; i < k-1; i++) max_heap.push({nums[i], i});
        for (int i = k-1; i < nums.size(); i++) {
            max_heap.push({nums[i], i});
            Pair p = max_heap.top();
            while (p.second < i - k + 1) {
                max_heap.pop();
                p = max_heap.top();
            }
            result.push_back(p.first);
        }
        return result;
    }
};
