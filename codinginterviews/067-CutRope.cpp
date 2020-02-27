//dp问题.max_num = max(f(i) * f(n - i)) 0 < i <  n
class Solution {
public:
    int cutRope(int number) {
        if (number < 2) return 0;
        if (number == 2) return 1;
        if (number == 3) return 2;
        int dp[number+1];
        memset(dp, 0, sizeof(dp));
        //下面三个数存储的是第一刀剪下的长度
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= number; i++) {
            int max_num = 0;
            for (int j = 1; j <= i/2; j++) {
                max_num = max(max_num, dp[j] * dp[i - j]);
            }
            dp[i] = max_num;
        }
        return dp[number];
    }
};
