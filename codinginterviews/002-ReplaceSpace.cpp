class Solution {
public:
    //字符串从后往前处理
	void replaceSpace(char *str,int length) {
        int count = 0;
        int i = 0, j;
        while (str[i] != '\0') {
            if (str[i++] == ' ')
                ++count;
        }
        int len = length + 2 * count;
        for (i = length - 1, j = len - 1; i >= 0 && j >= 0;) {
            if (str[i] == ' ') {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
                i--;
            } else {
                str[j--] = str[i--];
            }
        }
        str[len] = '\0';
	}
};
