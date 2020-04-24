class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.compare("0") == 0 || num2.compare("0") == 0) return "0";
        string result;
        //vector<string> result_num;
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num2.size(); i++) {
            string tmp;
            int carry = 0;
            for (int j = num1.size() - 1; j >= 0; j--) {
                int num = (num1[j] - '0') * (num2[i] - '0');
                int val = (num + carry) % 10;
                carry = (num + carry) / 10;
                tmp += to_string(val);
            }
            if (carry != 0) tmp += to_string(carry);
            reverse(tmp.begin(), tmp.end());
            for (int k = 0; k < i; k++)
                tmp += "0";
            result = add_string(result, tmp);
        }
        return result;
    }

private:
    static string add_string(string str1, string str2) {
        string result;
        string::reverse_iterator iter1 = str1.rbegin();
        string::reverse_iterator iter2 = str2.rbegin();
        int carry = 0;
        while (iter1 != str1.rend() || iter2 != str2.rend()) {
            int v1 = iter1 == str1.rend() ? 0 : *iter1 - '0';
            int v2 = iter2 == str2.rend() ? 0 : *iter2 - '0';
            int val = (v1 + v2 + carry) % 10;
            carry = (v1 + v2 + carry) / 10;
            result += to_string(val);
            if (iter1 != str1.rend()) iter1++;
            if (iter2 != str2.rend()) iter2++;
        }
        if (carry != 0) result += to_string(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};
