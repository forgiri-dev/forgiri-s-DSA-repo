class Solution {
public:
    TreeNode* dfs(TreeNode* node, int val){
        if (node == nullptr) {
            return nullptr;
        }
        
        if (val == node->val) {
            return node;
        }
        
        if (val < node->val) {
            return dfs(node->left, val); 
        } else {
            return dfs(node->right, val);
        }
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        return dfs(root, val); 
    }
};