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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if (pRoot == nullptr) return result;
        queue<TreeNode*> q1, q2;
        q1.push(pRoot);
        while (!q1.empty()) {
            vector<int> tmp;
            while (!q1.empty()) {
                TreeNode *node = q1.front();
                q1.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr) q2.push(node->left);
                if (node->right != nullptr) q2.push(node->right);
            }
            result.push_back(tmp);
            swap(q1, q2);
        }
        return result;
    }
    
};
