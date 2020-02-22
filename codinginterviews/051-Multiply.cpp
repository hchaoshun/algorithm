class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> result;
        for (int i = 0; i < A.size(); i++) {
            int tmp = 1;
            for (int j = 0; j < i; j++)
                tmp *= A[j];
            for (int k = A.size() - 1; k > i; k--)
                tmp *= A[k];
            result.push_back(tmp);
        }
        return result;
    }
};
