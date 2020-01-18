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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> curr, next;
        if (root == nullptr) return result;
        curr.push(root);
        while (!curr.empty()) {
            vector<int> tmp;
            while (!curr.empty()) {
                TreeNode *node = curr.front();
                curr.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr) next.push(node->left);
                if (node->right != nullptr) next.push(node->right);
            }
            result.push_back(tmp);
            swap(curr, next);
        }
        return result;
    }
};
