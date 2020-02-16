class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == nullptr) return true;
        int left = BinaryTreeDepth(pRoot->left);
        int right = BinaryTreeDepth(pRoot->right);
        if (fabs(left - right) <= 1) {
            return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
        } else {
            return false;
        }
    }
    
private:
    int BinaryTreeDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        return max(BinaryTreeDepth(root->left), BinaryTreeDepth(root->right)) + 1;
    }
};
