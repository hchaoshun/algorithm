class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        if (sum < 3) return result;
        vector<int> tmp;
        int begin = 1, end = 2;
        int cur_sum = begin + end;
        int mid = (sum + 1) / 2;
        while (begin < mid && end < sum) {
            if (cur_sum == sum) {
                for (int i = begin; i <= end; i++) {
                    tmp.push_back(i);
                }
                result.push_back(tmp);
                tmp.clear();
                end++;
                cur_sum += end;
            } else if (cur_sum < sum) {
                end++;
                cur_sum += end;
            } else {
                cur_sum -= begin;
                begin++;
            }
        }
        return result;
    }
};
