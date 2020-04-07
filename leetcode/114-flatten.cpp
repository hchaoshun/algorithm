class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            if (node->right != nullptr) s.push(node->right);
            if (node->left != nullptr) s.push(node->left);
            node->left = nullptr;
            if (!s.empty()) node->right = s.top();
        }
    }
};
