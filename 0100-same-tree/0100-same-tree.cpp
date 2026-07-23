class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> s;
        s.push({p, q});
        
        while (!s.empty()) {
            pair<TreeNode*, TreeNode*> current = s.top();
            s.pop();
            
            TreeNode* n1 = current.first;
            TreeNode* n2 = current.second;
            
            if (n1 == nullptr && n2 == nullptr) {
                continue;
            }
            
            if (n1 == nullptr || n2 == nullptr) {
                return false;
            }
            
            if (n1->val != n2->val) {
                return false;
            }
            
            s.push({n1->left, n2->left});
            s.push({n1->right, n2->right});
        }
        
        return true;
    }
};