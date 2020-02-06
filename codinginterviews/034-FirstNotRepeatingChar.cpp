class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> cache;
        for_each(str.begin(), str.end(), [&cache](const char c) {
            cache[c]++;
        });
        for (int i = 0; i < str.size(); i++) {
            if (cache[str[i]] == 1)
                return i;
        }
        return -1;
    }
};
