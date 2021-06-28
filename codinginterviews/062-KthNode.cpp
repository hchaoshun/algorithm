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

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (k == 0) return nullptr;
        vector<TreeNode*> nodes;
        InTrav(pRoot, nodes);
        if (nodes.size() >= k) {
            return nodes[k-1];
        } else {
            return nullptr;
        }
    }

private:
    void InTrav(TreeNode* pRoot, vector<TreeNode*>& nodes) {
        if (pRoot == nullptr) return;
        InTrav(pRoot->left, nodes);
        nodes.push_back(pRoot);
        InTrav(pRoot->right, nodes);
    }

};
