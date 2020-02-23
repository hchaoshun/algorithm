/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if (pRoot == nullptr) return true;
        return isSymmetrical(pRoot->left, pRoot->right);
    }
private:
    bool isSymmetrical(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        return (left->val == right->val) && isSymmetrical(left->left, right->right)
            && isSymmetrical(left->right, right->left);
    }

};
