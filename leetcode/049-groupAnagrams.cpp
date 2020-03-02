class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> group;
        for (const auto & s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            group[key].push_back(s);
        }
        for (auto iter = group.begin(); iter != group.end(); iter++) {
            result.push_back(iter->second);
        }
        return result;
    }
};
