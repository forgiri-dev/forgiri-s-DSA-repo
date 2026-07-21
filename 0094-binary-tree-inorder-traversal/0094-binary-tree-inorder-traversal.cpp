class Solution {
public:
    void helper(TreeNode* node, vector<int>& res) {
        if (node == nullptr) {
            return;
        }
        
        helper(node->left, res);      
        res.push_back(node->val);     
        helper(node->right, res);     
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> result;
       helper(root, result);
       return result;
    }
};