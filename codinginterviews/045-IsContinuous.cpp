class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() == 0) return false;
        sort(numbers.begin(), numbers.end());
        int count0 = count(numbers.begin(), numbers.end(), 0);
        int num = 0;
        vector<int>::iterator iter = find_if(numbers.begin(), numbers.end(),
                                            [](const int n) { return n != 0; });
        ++iter;
        while (iter != numbers.end()) {
            int delta;
            if ((delta = (*iter - *prev(iter))) <= 0)
                return false;
            else {
                num += delta - 1;
            }
            ++iter;
        }
        return count0 >= num;
    }
};
