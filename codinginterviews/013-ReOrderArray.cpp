class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> tmp(array);
        array.clear();
        for (vector<int>::iterator iter = tmp.begin();
            iter != tmp.end();) {
            if (*iter % 2 != 0) {
                array.push_back(*iter);
                iter = tmp.erase(iter);
            } else ++iter;
        }
        array.insert(array.end(), tmp.begin(), tmp.end());
    }
};
