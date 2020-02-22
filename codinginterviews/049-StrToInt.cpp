class Solution {
public:
    int StrToInt(string str) {
        //考虑到result可能会大于INT_MAX，所以设置为long long,
        //比较之后最后再转换过来
        long long result = 0;
        if (str.size() == 0) return result;
        bool minus = false;
        string::iterator iter = str.begin();
        if (*iter == ' ') iter++;
        else if (*iter == '+') iter++;
        else if (*iter == '-') {
            minus = true;
            iter++;
        }
        while (iter != str.end()) {
            if (*iter >= '0' && *iter <= '9') {
                result = result * 10 + (*iter - '0');
                iter++;
            } else {
                return 0;
            }
            
            if (minus == false) {
                if (result > INT_MAX) return 0;
            } else {
                if ((result - 1) > INT_MAX) return 0;
            }
        }
        
        result = (minus == true) ? -result : result;
        return (int)result;
    }
};
