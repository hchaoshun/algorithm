class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t n = s.size();
        for (size_t i = 0; i < n/2; i++) {
            swap(s[i], s[n-i-1]);
        }
    }
};
