class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        if (root == nullptr) {
            return {};
        }
        
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* node = p.first;
            int col = p.second.first;
            int row = p.second.second;
            
            nodes[col][row].insert(node->val);
            
            if (node->left != nullptr) {
                q.push({node->left, {col - 1, row + 1}});
            }
            
            if (node->right != nullptr) {
                q.push({node->right, {col + 1, row + 1}});
            }
        }
        
        vector<vector<int>> result;
        for (auto& [col, rowMap] : nodes) {
            vector<int> colList;
            
            for (auto& [row, values] : rowMap) {
                for (int val : values) {
                    colList.push_back(val);
                }
            }
            
            result.push_back(colList);
        }
        
        return result;
    }
};