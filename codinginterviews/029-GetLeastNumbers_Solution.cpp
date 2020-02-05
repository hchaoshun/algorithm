//top k problem
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if (input.size() == 0 || k > input.size()) return result;
        
        make_heap(input.begin(), input.end(), greater<int>());
        for (int i = 0; i < k; i++) {
            result.push_back(input[0]);
            pop_heap(input.begin(), input.end(), greater<int>());
            input.pop_back();
        }
        return result;
    }
};
