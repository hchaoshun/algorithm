class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        for (int i = 0; i <= num; i++) {
            result.push_back(count(i));
        }
        return result;
    }

    int count(int n) {
        int c = 0;
        for (int i = 0; i < sizeof(n)*8; i++) {
            if (n & 1) c++;
            n >>= 1;
        }
        return c;
    }
};

//dp问题
//0: 0000
//1: 0001
//2: 0010
//3: 0011
//4: 0100
//5: 0101
//如果 i 为偶数，那么f(i) = f(i/2)
//如果 i 为奇数，那么f(i) = f(i - 1) + 1
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        for (int i = 0; i <= num; i++) {
            if (i % 2 == 0) dp[i] = dp[i/2];
            else dp[i] = dp[i-1] + 1;
        }
        return dp;
    }
};
