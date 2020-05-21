//先序遍历每个节点，以该节点为起始点左右递归
class Solution {
public:
    int 4(TreeNode* root, int sum) {
        int count = 0;
        preTrav(root, sum, count);
        return count;
    }

private:
    void preTrav(TreeNode *root, int sum, int &count) {
        if (root == nullptr) return;
        calcSum(root, sum, count);
        preTrav(root->left, sum, count);
        preTrav(root->right, sum, count);
    }

    void calcSum(TreeNode *root, int sum, int &count) {
        if (root == nullptr) return;
        sum -= root->val;
        if (sum == 0) {
            ++count;
        }
        calcSum(root->left, sum, count);
        calcSum(root->right, sum, count);
    }
};
