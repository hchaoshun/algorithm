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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> result;
        vector<int> cur;
        dfs(root, result, cur, expectNumber);
        return result;
    }
private:
    static void dfs(TreeNode *root, vector<vector<int>> &result,
                   vector<int> &cur, int sum) {
        if (root == nullptr) return;
        cur.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == sum)
                result.push_back(cur);
        }
        dfs(root->left, result, cur, sum - root->val);
        dfs(root->right, result, cur, sum - root->val);
        cur.pop_back();
    }
};
