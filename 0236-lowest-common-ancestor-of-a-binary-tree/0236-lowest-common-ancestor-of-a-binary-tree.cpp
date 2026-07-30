class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == nullptr) {
            return false;
        }
        
        path.push_back(root);
        
        if (root == target) {
            return true;
        }
        
        if (getPath(root->left, target, path) || getPath(root->right, target, path)) {
            return true;
        }
        
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;
        
        getPath(root, p, pathP);
        getPath(root, q, pathQ);
        
        TreeNode* lca = nullptr;
        int i = 0;
        
        while (i < pathP.size() && i < pathQ.size() && pathP[i] == pathQ[i]) {
            lca = pathP[i];
            i++;
        }
        
        return lca;
    }
};