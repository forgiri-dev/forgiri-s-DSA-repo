
class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* middle = nullptr;
    TreeNode* last = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);

        if (prev != nullptr && root->val < prev->val) {
            
            if (first == nullptr) {
                first = prev;
                middle = root; 
            } 
            else {
                last = root;   
            }
        }
        
        prev = root;

        inorder(root->right);
    }

public: 
    void recoverTree(TreeNode* root) {
        first = middle = last = prev = nullptr;
        
        inorder(root);
        
        if (first != nullptr && last != nullptr) {
            std::swap(first->val, last->val);
        } else if (first != nullptr && middle != nullptr) {
            std::swap(first->val, middle->val);
        }
    }
};