#include <algorithm> // For std::max

class Solution {
public:
    int heightHelper(TreeNode* node, int& max_diameter) {
        if (node == nullptr) {
            return 0; 
        }
        
        int left_height = heightHelper(node->left, max_diameter);
        int right_height = heightHelper(node->right, max_diameter);
        
        max_diameter = max(max_diameter, left_height + right_height);
        
        return 1 + max(left_height, right_height);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0; 
        
        heightHelper(root, max_diameter); 
        
        return max_diameter;
    }
};