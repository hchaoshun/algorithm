/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.begin(), preorder.end(),
                        inorder.begin(), inorder.end());
    }
private:
    template <typename Iter>
    TreeNode *buildTree(Iter pre_begin, Iter pre_end, Iter in_begin, Iter in_end) {
        if (pre_begin == pre_end) return nullptr;
        if (in_begin == in_end) return nullptr;
        
        TreeNode *root = new TreeNode(*pre_begin);
        Iter pivot = find(in_begin, in_end, *pre_begin);
        int left_size = distance(in_begin, pivot);
        root->left = buildTree(next(pre_begin), next(pre_begin, left_size + 1),
                             in_begin, next(in_begin + left_size));
        root->right = buildTree(next(pre_begin, left_size + 1), pre_end, next(pivot),
                               in_end);
        return root;
    }
};
