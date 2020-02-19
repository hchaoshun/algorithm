class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.size() == 0 || n <= 0) return str;
        return str.substr(n % str.size()) + str.substr(0, n % str.size());
    }
};
