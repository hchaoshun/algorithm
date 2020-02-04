class Solution {
public:
    //todo other method?
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        auto iter = find_if(numbers.begin(), numbers.end(), [&numbers](const int num) {
            return 2 * count(numbers.begin(), numbers.end(), num) > numbers.size();
        });
        return iter == numbers.end() ? 0 : *iter;
    }
};
