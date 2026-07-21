class Solution {
public:
    void traverse(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        
        result.push_back(node->val);   
        traverse(node->left, result);  
        traverse(node->right, result); 
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;            
        traverse(root, result);        
        return result;                
    }
};