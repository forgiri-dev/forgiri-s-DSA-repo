class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        s1.push(root->left);
        s2.push(root->right);

        while (!s1.empty() && !s2.empty()) {
            TreeNode* n1 = s1.top();
            TreeNode* n2 = s2.top();
            
            s1.pop();
            s2.pop();

            if (n1 == nullptr && n2 == nullptr) {
                continue;
            }

            if (n1 == nullptr || n2 == nullptr) {
                return false;
            }

            if (n1->val != n2->val) {
                return false;
            }

            s1.push(n1->left);
            s2.push(n2->right);
            
            s1.push(n1->right);
            s2.push(n2->left);
        }

        return true;
    }
};