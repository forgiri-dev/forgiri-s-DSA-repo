class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        TreeNode* current = root;
        
        while (true) {
            if (val < current->val) {
                if (current->left == nullptr) {
                    current->left = new TreeNode(val);
                    break;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = new TreeNode(val);
                    break;
                }
                current = current->right;
            }
        }
        
        return root;
    }
};