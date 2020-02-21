class Solution {
public:
    int Add(int num1, int num2) {
        int temp;
        while (num2 != 0) {
            temp = num1 ^ num2; //用^模拟不带进位加法
            num2 = (num1 & num2) << 1; //用&然后右移模拟进位
            num1 = temp;
        } //没有进位时就是最终结果
        return num1;
    }
};
