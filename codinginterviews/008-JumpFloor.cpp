class Solution {
public:
    int jumpFloor(int number) {
        int v = 0, w = 1;
        while (number--) {
            w = w + v;
            v = w - v;
        }
        return w;
    }
};
