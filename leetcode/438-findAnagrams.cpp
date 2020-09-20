//用hashmap存储char数量，然后用滑动窗口遍历一次
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> needs(26, 0), counter(26, 0);
        for (const auto& i : p) {
            needs[i - 'a']++;
        }
        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            counter[s[r] - 'a']++;
            //刚开始先走到窗口大小位置，后面滑动窗口
            if (r < p.size() - 1) {
                continue;
            }
            if (needs == counter) {
                result.push_back(l);
            }
            counter[s[l] - 'a']--;
            l++;
        }
        return result;
    }
};
