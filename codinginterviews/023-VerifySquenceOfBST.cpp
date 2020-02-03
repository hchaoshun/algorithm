class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0) return false;
        return judge(sequence, 0, sequence.size() - 1);
    }

private:
    // 2, 9, 5, 16, 17, 15, 19, 18, 12
    static bool judge(vector<int> vec, int start, int end) {
        if (start >= end) return true; //递归基
        int mid = end - 1;
        // 后一半的元素都比根元素大
        while (vec[mid] > vec[end]) mid--;
        int i = start;
        // 那么前面的元素都应该比根小
        while (i < end && vec[i] < vec[end]) i++;
        if (i < mid) return false;
        //左右子树递归
        return judge(vec, start, mid) && judge(vec, mid+1, end-1);
    }
};
