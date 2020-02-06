class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), [](const int a, const int b) {
            const string left = to_string(a) + to_string(b);
            const string right = to_string(b) + to_string(a);
            return left < right;
        });
        string result;
        for_each(numbers.begin(), numbers.end(), [&result](const int num) {
            result += to_string(num);
        });
        return result;
    }
};
