//会超时
class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        bool minus = false;
        if (n < 0) {
            minus = true;
            n = -n;
        }
        for (int i = 0; i < n; i++) {
            result *= x;
        }
        return minus ? 1.0 / result : result;
    }
};

//分而治之，注意int的范围
//x^n = x^(n/2) * x^(n/2) * x^(n%2)
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N >= 0) return Pow(x, N);
        else return 1.0 / Pow(x, -N);
    }

private:
    double Pow(double x, long n) {
        if (n == 0) return 1;
        double v = Pow(x, n/2);
        if (n % 2 == 0) return v * v;
        else return v * v * x;
    }
};
