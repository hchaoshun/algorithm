class Solution {
public:
    int Fibonacci(int n) {
        int v = 0, w = 1;
        while (n--) {
            w = w + v;
            v = w - v;
        }
        return v;
    }
};
