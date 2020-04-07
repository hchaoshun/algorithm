class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums.begin(), nums.end());
    }

    template <typename RandomAccessIterator>
    TreeNode *constructBST(RandomAccessIterator first, RandomAccessIterator last) {
        auto len = distance(first, last);
        if (len < 1) return nullptr;
        auto mid = len >> 1;
        TreeNode *root = new TreeNode(*(first + mid));
        root->left = constructBST(first, first + mid);
        root->right = constructBST(first + mid + 1, last);
        return root;
    }
};
