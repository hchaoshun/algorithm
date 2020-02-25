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
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (pRoot == nullptr) return nullptr;
        TreeNode *ret = nullptr;
        if ((ret = KthNode(pRoot->left, k)) != nullptr) {
            return ret;
        }
        if (++count == k) {
            return pRoot;
        }
        if ((ret = KthNode(pRoot->right, k)) != nullptr) {
            return ret;
        }
        return nullptr;
    }

private:
    unsigned int count = 0;
};
