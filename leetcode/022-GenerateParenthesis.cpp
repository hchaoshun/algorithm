//递归
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
