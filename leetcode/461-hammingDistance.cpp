class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        size_t count = 0;
        while (z) {
            count += z & 1;
            z = z >> 1;
        }
        return count;
    }
};
