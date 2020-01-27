class Solution {
public:
    //为了负数时候避免死循环，不右移数字n，转而去移动测试位
     int  NumberOf1(int n) {
         unsigned int flag = 1;
         int count = 0;
         while (flag != 0) {
             if (flag & n != 0)
                 ++count;
             flag <<= 1;
         }
         return count;
     }
};
