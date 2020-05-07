//bfs
//预处理构造wordList中单词的通用状态，这样能找到图的下一个节点 d*g-> (dig, dog), *ot-> (hot dot lot)
class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    size_t len = beginWord.size();
    unordered_map<string, list<string>> allcomb;
    unordered_set<string> visited;
    int level = 0;
    for (auto str : wordList) {
      for (size_t i = 0; i < len; ++i) {
        string key = str.substr(0, i) + "*" + str.substr(i+1, len - i - 1);
        allcomb[key].push_back(str);
      }
    }
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      string new_word = node.first;
      int level = node.second;
      for (size_t i = 0; i < len; ++i) {
        string key = new_word.substr(0, i) + "*" + new_word.substr(i+1, len - i - 1);
        if (allcomb.find(key) != allcomb.end()) {
          for (auto iter = allcomb[key].begin(); iter != allcomb[key].end(); ++iter) {
            if (endWord == *iter) {
              return level + 1;
            }
            if (visited.find(*iter) == visited.end()) {
              visited.insert(*iter);
              q.push({*iter, level + 1});
            }
          }
        }
      }
    }
    return 0;
  }
};
