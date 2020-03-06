class Solution {
 public:
  int romanToInt(string s) {
    int result = 0;
    for (size_t i = 0; i < s.size(); i++) {
      if (i > 0 && (mapping[s[i]] > mapping[s[i-1]])) {
        //前面一个数已经加了，再减回去，所以2*
        result += mapping[s[i]] - 2 * mapping[s[i-1]];
      } else {
        result += mapping[s[i]];
      }
    }
    return result;
  }
 private:
  unordered_map<char, int> mapping = {
      {'I' , 1},
      {'V' , 5},
      {'X' , 10},
      {'L' , 50},
      {'C' , 100},
      {'D' , 500},
      {'M' , 1000}
  };
};
