class Solution {
public:
    int maxPathSumHelper(TreeNode* node, int& global_max) {
        if (node == nullptr) {
            return 0; 
        }

        int left_max = max(0, maxPathSumHelper(node->left, global_max));
        int right_max = max(0, maxPathSumHelper(node->right, global_max));
        
        int current_path_sum = node->val + left_max + right_max;
        
        global_max = max(global_max, current_path_sum);
        
        return node->val + max(left_max, right_max);
    }

    int maxPathSum(TreeNode* root) {
        int global_max = -10001; 
        
        maxPathSumHelper(root, global_max);
        
        return global_max;
    }
};