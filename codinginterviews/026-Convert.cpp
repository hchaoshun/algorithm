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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode *head = new TreeNode(-1);
        TreeNode *tail = head;
        inTrav(pRootOfTree, [&tail](TreeNode *node) {
            tail->right = node;
            node->left = tail;
            tail = node;
        });
        if (head->right != nullptr) head->right->left = nullptr;
        TreeNode *result = head->right;
        delete head;
        return result;
    }

private:
    template <typename VST>
    void inTrav(TreeNode *root, VST visit) {
        stack<TreeNode*> s;
        while (true) {
            goAlongLeftBranch(root, s);
            if (s.empty()) break;
            root = s.top();
            s.pop();
            visit(root);
            root = root->right;
        }
    }
    
    void goAlongLeftBranch(TreeNode *root, stack<TreeNode*> &s) {
        while (root != nullptr) {
            s.push(root);
            root = root->left;
        }
    }
};
