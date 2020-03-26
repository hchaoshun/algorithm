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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode*> first, second;
        first.push(root);
        while (!first.empty()) {
            TreeNode *node = first.top();
            first.pop();
            second.push(node);
            if (node->left != nullptr) first.push(node->left);
            if (node->right != nullptr) first.push(node->right);
        }
        while (!second.empty()) {
            result.push_back(second.top()->val);
            second.pop();
        }
        return result;
    }
};
