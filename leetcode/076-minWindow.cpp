//滑动窗口思想
//1. 初始化 left = right = 0，把索引闭区间 [left, right] 称为一个「窗口」
//2. 先不断地增加 right 指针扩大窗口 [left, right]，直到窗口中的字符串符合要求（包含了 T 中的所有字符）
//3. 此时停止增加 right，转而不断增加 left 指针缩小窗口 [left, right]，
//   直到窗口中的字符串不再符合要求（不包含 T 中的所有字符了）。同时，每次增加 left，我们都要更新一轮结果。
//4. 重复第 2 和第 3 步，直到 right 到达字符串 S 的尽头

class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, len = INT_MAX;
        int left = 0, right = 0;
        int match = 0;
        unordered_map<char, int> needs;
        unordered_map<char, int> windows;
        for (auto &c : t) needs[c]++;

        while (right < s.size()) {
            char cr = s[right];
            if (needs.count(cr) > 0) {
                windows[cr]++;
                if (windows[cr] == needs[cr]) {
                    match++;
                }
            }
            right++;

            while (match == needs.size()) {
               if (right - left < len) {
                   start = left;
                   len = right - left;
               }
               char cl = s[left];
               if (needs.count(cl) > 0) {
                   windows[cl]--;
                   if (windows[cl] < needs[cl]) {
                       match--;
                   }
               }
               left++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
