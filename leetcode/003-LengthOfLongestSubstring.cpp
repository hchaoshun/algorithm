//遍历遇到重复值时，记录此时max，然后从前一个重复值+1作为起始
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int find[256];
        memset(find, -1, sizeof(find));
        int start = 0;
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            //注意如果没有后面的条件start可能会回退
            //考虑abba，当走到最后一个a是，start会从2退到1，显然错误
            //start应该总是小于find[s[i]]
            if (find[s[i]] != -1 && start <= find[s[i]]) {
                max_len = max(max_len, i - start);
                start = find[s[i]] + 1;
            }
            find[s[i]] = i;
        }
        return max((int)s.size() - start, max_len); //考虑到没有重复的情况
    }
};
