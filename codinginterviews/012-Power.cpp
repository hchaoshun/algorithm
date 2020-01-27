class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent < 0) {
            base = 1.0 / base;
            exponent = -exponent;
        }
        double result = 1;
        while (exponent-- > 0) result *= base;
        return result;
    }
};
