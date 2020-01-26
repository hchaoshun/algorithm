class Solution {
public:
    int rectCover(int number) {
        if (number == 0) return 0;
        int v = 0, w = 1;
        while (number--) {
            w = w + v;
            v = w - v;
        }
        return w;
    }
};
