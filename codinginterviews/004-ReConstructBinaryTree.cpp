/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return BuildTree(pre.begin(), pre.end(), vin.begin(), vin.end());
    }
private:
    template <typename Iter>
    TreeNode *BuildTree(Iter pre_begin, Iter pre_end, Iter in_begin, Iter in_end) {
        if (pre_begin == pre_end) return nullptr;
        if (in_begin == in_end) return nullptr;
        auto root = new TreeNode(*pre_begin);
        auto pivot = find(in_begin, in_end, *pre_begin);
        auto len = distance(in_begin, pivot);
        root->left = BuildTree(next(pre_begin), next(pre_begin, len+1), in_begin,
                              next(in_begin, len));
        root->right = BuildTree(next(pre_begin, len+1), pre_end, next(pivot),
                               in_end);
        return root;
    }
};
