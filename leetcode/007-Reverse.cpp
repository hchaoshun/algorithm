//注意数据溢出
class Solution {
public:
    int reverse(int x) {
        long long tmp = x;
        long long result = 0;
        bool flag = false;
        if (x < 0) {
            flag = true;
            tmp = -tmp;
        }
        
        while (tmp > 0) {
           result = result * 10 + tmp % 10;
           tmp /= 10;
        }
        if (flag == true) {
            return -result < INT_MIN ? 0 : -result;
        } else {
            return result > INT_MAX ? 0 : result;
        }
    }
};
