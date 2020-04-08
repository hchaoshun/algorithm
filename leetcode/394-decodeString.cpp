//用两个栈分别记录数字和字母
class Solution {
public:
    string decodeString(string s) {
        stack<int> stack_num;
        stack<string> stack_str;
        int num = 0;
        string str = "";
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            } else if (c == '[') {
                stack_num.push(num);
                stack_str.push(str);
                num = 0;
                str = "";
            } else if (c == ']') {
                int n = stack_num.top();
                stack_num.pop();
                string tmp;
                for (int i = 0; i < n; i++) {
                    tmp += str;
                }
                str = stack_str.top() + tmp;
                stack_str.pop();
            } else {
                str += c;
            }
            
        }
        return str;
    }
};
