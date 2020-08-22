//遍历每一个节点，以每一个节点为中心点计算最长路径（左子树边长+右子树边长），更新全局变量max
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int longest_path = 0;
        dfs(root, longest_path);
        return longest_path;
    }

private:
    int dfs(TreeNode *root, int& longest_path) {
        if (root->left == nullptr && right == nullptr) return 0;
        auto left_size = root->left == nullptr ? 0 : dfs(root->left, longest_path) + 1;
        auto right_size = root->right == nullptr ? 0 : dfs(root->right, longest_path) + 1;
        longest_path = max(longest_path, left_size + right_size);
        return max(left_size, right_size);
    }

};
