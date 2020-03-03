//todo 时间复杂度太大，找时间优化
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>::iterator it = intervals.begin();
        while (it != intervals.end()) {
            if ((*it)[0] > newInterval[1]) {
                intervals.insert(it, newInterval);
                return intervals;
            } else if ((*it)[1] < newInterval[0]) {
                it++;
            } else {
                newInterval[0] = min(newInterval[0], (*it)[0]);
                newInterval[1] = max(newInterval[1], (*it)[1]);
                it = intervals.erase(it);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;

    }
};
