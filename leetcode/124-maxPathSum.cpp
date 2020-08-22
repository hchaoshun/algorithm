/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //和543类似
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_num = INT_MIN;
        dfs(root, max_num);
        return max_num;
    }

private:
    int dfs(TreeNode *root, int& max_num) {
        if (root == nullptr) return 0;
        //注意左右递归时不能加root->val本身值，因为在第3布计算max_num才加
        int left = max(0, dfs(root->left, max_num));
        int right = max(0, dfs(root->right, max_num));
        max_num = max(max_num, left + right + root->val);
        return max(left, right) + root->val;
    }
};

