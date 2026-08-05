class Solution {
public:
    int count = 0;
    int result = -1;

    void inorder(TreeNode* node, int k) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, k);

        
        count++; 
        if (count == k) {
            result = node->val; 
            return;
        }

        if (count < k) {
            inorder(node->right, k);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};