//递归,只要左边括号数和右边括号数相等，就一定匹配
//左边小于n添加左边
//右边小于左边添加右边
//满足上面两条能保证匹配正确
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        if (n > 0) generate(result, path, n, 0, 0);
        return result;
    }
    
private:
    void generate(vector<string> &result, string &path, int n, int left, int right) {
        if (left == n) {
            string s(path);
            s.append(n - right, ')');
            result.push_back(s);
            return;
        }
        
        path.push_back('(');
        generate(result, path, n, left + 1, right);
        path.pop_back();
        
        if (right < left) {
            path.push_back(')');
            generate(result, path, n, left, right + 1);
            path.pop_back();
        }
    }
};

//递归生成所有可能的情况，然后逐一判断
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        generate(result, path, 0, n * 2);
        return result;
    }

private:
    void generate(vector<string> &result, string &path, int current_num, int n) {
        if (path.size() == n) {
            if (validate(path)) {
                result.push_back(path);
            }
            return;
        }
        path.push_back('(');
        generate(result, path, current_num + 1, n);
        path.pop_back();
        path.push_back(')');
        generate(result, path, current_num + 1, n);
        path.pop_back();
    }

    bool validate(const string& path) {
        stack<char> s;
        for (auto c : path) {
            if (c == '(') s.push(c);
            else {
                if (s.empty()) return false;
                else s.pop();
            }
        }
        return s.empty();
    }
};

//在上一步的基础上优化，回溯
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        generate(result, path, 0, 0, n);
        return result;
    }

private:
    void generate(vector<string> &result, string &path, int left, int right, int n) {
        if (path.size() == 2 * n) {
            if (validate(path)) {
                result.push_back(path);
            }
            return;
        }
        if (left < n) {
            path.push_back('(');
            generate(result, path, left + 1, right, n);
            path.pop_back();
        }
        if (right < n) {
            path.push_back(')');
            generate(result, path, left, right + 1, n);
            path.pop_back();
        }
    }

    bool validate(const string& path) {
        stack<char> s;
        for (auto c : path) {
            if (c == '(') s.push(c);
            else {
                if (s.empty()) return false;
                else s.pop();
            }
        }
        return s.empty();
    }
};
