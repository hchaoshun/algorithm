class Solution {
public:
    string ReverseSentence(string str) {
        string result;
        stack<char> s1, s2;
        for_each(str.begin(), str.end(), [&s1](char c) { s1.push(c); });
        while (!s1.empty()) {
            //注意s1为空的情况
            while (!s1.empty() && s1.top() != ' ') {
                s2.push(s1.top());
                s1.pop();
            }
            while (!s2.empty()) {
                result += s2.top();
                s2.pop();
            }
            if (!s1.empty()) {
              result += s1.top();
              s1.pop();
            }
            //std::cout << result << std::endl;
        }
        return result;
    }
};
