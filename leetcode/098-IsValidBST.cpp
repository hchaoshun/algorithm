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
    bool isValidBST(TreeNode* root) {
        vector<int> result;
        InTrav(root, result);
        return isOrder(result);
    }

private:
    static void InTrav(TreeNode *root, vector<int> &result) {
        stack<TreeNode*> s;
        while (true) {
            goAlongLeftBranch(root, s);
            if (s.empty()) break;
            root = s.top();
            s.pop();
            result.push_back(root->val);
            root = root->right;
        }
    }
    static void goAlongLeftBranch(TreeNode *root, stack<TreeNode*> &s) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
    static bool isOrder(vector<int> &result) {
        int count = 0;
        for (int i = 1; i < result.size(); i++) {
            if (result[i-1] >= result[i])
                count++;
        }
        return !count;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//todo 有bug，当root->val = 2147483647时判断错误
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        //Value of INT_MAX is +2147483647.
        //Value of INT_MIN is -2147483648.
        return isValidBST(root, INT_MIN, INT_MAX);
    }
private:
    static bool isValidBST(TreeNode *root, int lower, int upper) {
        if (root == nullptr) return true;
        return root->val > lower && root->val < upper &&
            isValidBST(root->left, lower, root->val) &&
            isValidBST(root->right, root->val, upper);
    }
};
