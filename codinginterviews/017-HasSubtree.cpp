/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    //todo 用递归
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == nullptr || pRoot2 == nullptr) return false;
        vector<int> vec1, vec2;
        preTrav(pRoot1, vec1);
        preTrav(pRoot2, vec2);
        return search(vec1.begin(), vec1.end(), 
                      vec2.begin(), vec2.end()) != vec1.end();
    }
private:
    static void preTrav(TreeNode *root, vector<int> &vec) {
        if (root == nullptr) return;
        vec.push_back(root->val);
        preTrav(root->left, vec);
        preTrav(root->right, vec);
    }
};
