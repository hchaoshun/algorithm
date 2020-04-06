class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        //如果左右孩子都不为空，返回较小深度+1
        //如果左右孩子有一个为空,说明left和right有一个必然为0，返回left + right + 1
        return (left && right) ? min(left, right) + 1 : left + right + 1;
    }
};
