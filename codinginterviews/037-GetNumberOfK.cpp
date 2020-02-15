class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int count = 0;
        int pos = binarySearch(data, k);
        if (pos == -1) return count;
        for (int i = pos; i < data.size(); i++) {
            if (data[i] == k) count++;
            else break;
        }
        for (int j = pos - 1; j >= 0; j--) {
            if (data[j] == k) count++;
            else break;
        }
        return count;
    }
    
private:
    int binarySearch(vector<int> data, int k) {
        int lo = 0, hi = data.size();
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (data[mid] == k) return mid;
            else if (data[mid] < k) lo = mid + 1;
            else hi = mid;
        }
        return -1;
    }
};
