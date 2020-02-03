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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> cur;
        dfs(root, result, cur, sum);
        return result;
    }

private:
    void dfs(TreeNode *root, vector<vector<int>> &result, vector<int> &cur, int sum) {
        if (root == nullptr) return; //递归基
        cur.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == sum)
                result.push_back(cur);
        }
        dfs(root->left, result, cur, sum - root->val);
        dfs(root->right, result, cur, sum - root->val);
        cur.pop_back();
    }
};
