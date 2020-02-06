class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int result = 0;
        for (int i = 1; i <=n; i++) {
            result += number_1(i);
        }
        return result;
    }

private:
    static int number_1(int num) {
        int count = 0;
        do {
            if (num % 10 == 1)
                count++;
            num /= 10;
        } while (num > 0);
        return count;
    }
};
