//维护一个大顶堆，每次从堆中取top结果
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> result;
        priority_queue<pair<int, int>> pq;
        if (size <= 0 || num.size() < size) {
            return result;
        }
        for (int i = 0; i < size - 1; ++i) {
            pq.push({num[i], i});
        }
        for (int i = size - 1; i < num.size(); ++i) {
            pq.push({num[i], i});
            pair<int, int> max_r = pq.top();
            // 当堆中最大元素不在窗口中时弹出
            while (max_r.second < i - size + 1) {
                pq.pop();
                max_r = pq.top();
            }
            result.push_back(max_r.first);
        }
        return result;
    }
};
