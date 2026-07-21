
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0; 
        }
        
        int max_depth = 0;
        stack<pair<TreeNode*, int>> s; 
        s.push({root, 1});
        
        while (!s.empty()) {
            pair<TreeNode*, int> current = s.top();
            s.pop();
            
            TreeNode* node = current.first;
            int current_depth = current.second;
            
            max_depth = max(max_depth, current_depth);
            
            if (node->left != nullptr) {
                s.push({node->left, current_depth + 1});
            }
            if (node->right != nullptr) {
                s.push({node->right, current_depth + 1});
            }
        }
        
        return max_depth;
    }
};