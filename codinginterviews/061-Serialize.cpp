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
    char* Serialize(TreeNode *root) {    
        if (root == nullptr) {
            char *seri = new char[3];
            strcpy(seri, "#,");
            return seri;
        }
        string str;
        Serialize(root, str);
        char *seri = new char[str.size() + 1];
        strcpy(seri, str.c_str());
        return seri;
    }
    TreeNode* Deserialize(char *str) {
        if (str == nullptr || *str == '\0') {
            return nullptr;
        }
        int index = 0;
        return Deserialize(str, index);
    }

private:
    void Serialize(TreeNode *root, string &str) {
        if (root == nullptr) {
            str += "#,";
            return;
        }
        str += to_string(root->val) + ",";
        Serialize(root->left, str);
        Serialize(root->right, str);
    }
    
    TreeNode *Deserialize(char *str, int &index) {
        if (str[index] == '\0') {
            return nullptr;
        }
        if (str[index] == '#') {
            index += 2;
            return nullptr;
        }
        int num = 0;
        while (str[index] >= '0' && str[index] <= '9') {
            num = num * 10 + (str[index] - '0');
            index++;
        }
        index++;
        TreeNode *root = new TreeNode(num);
        root->left = Deserialize(str, index);
        root->right = Deserialize(str, index);
        return root;
    }
};

