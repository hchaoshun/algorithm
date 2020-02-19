class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if (array.size() < 2) return result;
        vector<int>::iterator first = array.begin();
        vector<int>::iterator last = array.end() - 1;
        while (first != last) {
            if (*first + *last == sum) {
                result.push_back(*first);
                result.push_back(*last);
                break;
            } else if (*first + *last < sum) {
                first++;
            } else {
                last--;
            }
        }
        return result;
    }
};
