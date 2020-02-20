class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if (n < 1 || m < 1) return -1;
        vector<int> child;
        for (int i = 0; i < n; i++)
            child.push_back(i);
        int num_n = 0;
        while (child.size() > 1) {
            for (int i = 1; i< m; i++) {
                num_n++;
                num_n %= child.size();
            }
            child.erase(child.begin() + num_n);
        }
        return child[0];
    }
};
