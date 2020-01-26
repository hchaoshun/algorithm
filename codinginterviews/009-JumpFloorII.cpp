class Solution {
public:
    //f(n) = 2f(n-1)
    int jumpFloorII(int number) {
        if (number == 1) return 1;
        return 2 * jumpFloorII(number - 1);
    }
};
