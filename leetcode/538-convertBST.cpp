class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        convertBST(root->right);
        root->val += num;
        num = root->val;
        convertBST(root->left);
        return root;
    }
private:
    int num = 0;
};
