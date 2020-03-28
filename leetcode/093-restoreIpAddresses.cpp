//dfs，注意ip的有效性
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> path;
        dfs(s, result, path, 0);
        return result;
    }

    void dfs(string s, vector<string> &result, vector<string> &path, int index) {
        //注意index必须走到s的末尾
        if (path.size() == 4 && index == s.size()) {
            result.push_back(path[0] + '.' + path[1] + '.' 
            + path[2] + '.' + path[3]);
            return;
        }
        //开始时s的长度最长为12，每加一个段，长队最多减少3
        //比如最开始长度上界为12，走第一步上界为9，第二步上界为6
        if (s.size() - index > (4 - path.size()) * 3)
            return;
        //开始时s的长度最短为4，每加一个段，长队最少减少1
        if (s.size() - index < 4 - path.size())
            return;

        int num = 0;
        for (size_t i = index; i < index + 3; i++) {
            num = num * 10 + (s[i] - '0');
            if (num < 0 || num > 255) break;
            path.push_back(to_string(num));
            dfs(s, result, path, i + 1);
            path.pop_back();
            //ip每一个段不允许前缀为0，但允许单个0
            //if判断放在此处原因：当num为0时，上面三行代码对应单个0情况
            //下面是前缀为0的情况
            if (num == 0) break;
        }

    }
};
