//注意x reverse可能会overflow
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int tmp = x;
        long long y = 0;
        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        if (y > INT_MAX) return false;
        return y == tmp;
    }
};
