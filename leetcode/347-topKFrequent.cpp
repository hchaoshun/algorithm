class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using E = pair<int, int>;
        priority_queue<E, vector<E>, greater<E>> min_heap;
        unordered_map<int, int> counter;
        for (auto &n : nums)
            counter[n]++;
        for (auto iter = counter.begin(); iter != counter.end(); ++iter) {
            auto p = make_pair(iter->second, iter->first);
            if (min_heap.size() == k) {
                if (p < min_heap.top()) continue;
                min_heap.pop();
            }
            min_heap.push(std::move(p));
        }
        vector<int> res(min_heap.size());
        k = res.size();
        while (!min_heap.empty()) {
            res[--k] = min_heap.top().second;
            min_heap.pop();
        }
        return res;
    }
};
