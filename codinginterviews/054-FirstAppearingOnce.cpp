class Solution {
private:
    string str;
    int count[256];
    
public:
    Solution() : str("") {
        memset(count, 0, sizeof(count));
    }
    
  //Insert one char from stringstream
    void Insert(char ch) {
        str += ch;
        count[int(ch)]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for (int i = 0; i < str.size(); i++) {
            if (count[int(str[i])] == 1)
                return str[i];
        }
        return '#';
    }

};
