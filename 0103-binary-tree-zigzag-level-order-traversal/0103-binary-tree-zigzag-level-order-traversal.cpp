class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool ltor = true; 
        
        while (!q.empty()) {
            int l = q.size();
            
            vector<int> currentLevel(l);
            
            for (int i = 0; i < l; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                int index = ltor ? i : (l - 1 - i);
                currentLevel[index] = node->val;
                
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            
            result.push_back(currentLevel);
            
            ltor = !ltor; 
        }
        
        return result;
    }
};