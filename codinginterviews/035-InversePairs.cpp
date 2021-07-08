//冒泡排序，会超时
class Solution {
public:
    int InversePairs(vector<int> data) {
        int result = bubbleSort(data, data.size());
        return result % 1000000007;
    }
     
private:
    static int bubbleSort(vector<int> &data, int n) {
        int count = 0;
        for (bool sorted = false; sorted = !sorted; n--) {
            for (int i = 1; i < n; i++) {
                if (data[i-1] > data[i]) {
                    swap(data[i-1], data[i]);
                    count++;
                    sorted = false;
                }
            }
        }
        return count;
    }
};

//归并排序
class Solution {
public:
    int InversePairs(vector<int> data) {
        if (data.size() == 0) return 0;
        vector<int> temp(data.size(), 0);
        return mergeSort(data, 0, data.size(), temp) % 1000000007;
    }
    
 private:
    static long long mergeSort(vector<int> &data, int lo, int hi, vector<int> &temp) {
        long long count = 0;
        if (hi - lo < 2) return count;
        int mid = (lo + hi) >> 1;
        count += mergeSort(data, lo, mid, temp);
        count += mergeSort(data, mid, hi, temp);
        count += merge(data, lo, mid, hi, temp);
        return count;
    }
    
    static long long merge(vector<int> &data, int lo, int mid, int hi, vector<int> &temp) {
        long long count = 0;
        int i = mid - 1;
        int j = hi - 1;
        int k = 0;
        while (i >= lo && j >= mid) {
            if (data[i] > data[j]) {
                count += j - mid + 1;
                temp[k++] = data[i--];
            } else {
                temp[k++] = data[j--];
            }
        }
        
        while (i >= lo) {
            temp[k++] = data[i--];
        }
        while (j >= mid) {
            temp[k++] = data[j--];
        }
        for (int i = 0; i < k; i++) {
            data[hi - i - 1] = temp[i];
        }
        return count;
    }
};

class Solution {
public:
    int InversePairs(vector<int> data) {
        return MergeSort(data, 0, data.size()) % 1000000007;
    }

private:
    long long MergeSort(vector<int> &data, int lo, int hi) {
        long long count = 0;
        if (hi - lo < 2) return count;
        int mid = (lo + hi) >> 1;
        count += MergeSort(data, lo, mid);
        count += MergeSort(data, mid, hi);
        count += Merge(data, lo, mid, hi);
        return count;
    }

    long long Merge(vector<int> &data, int lo, int mid, int hi) {
        //需要统计完才能排序
        vector<int> tmp(hi - lo, 0);
        int i = mid - 1, j = hi - 1;
        int k = 0;
        long long count = 0;
        while (i >= lo && j >= mid) {
            if (data[i] > data[j]) {
                count += j - mid + 1;
                tmp[k++] = data[i--];
            } else {
                tmp[k++] = data[j--];
            }
        }
        while (i >= lo) tmp[k++] = data[i--];
        while (j >= mid) tmp[k++] = data[j--];
        for (int i = 0; i < k; ++i) {
            data[i+lo] = tmp[k-i-1];
        }
        return count;
    }
};
