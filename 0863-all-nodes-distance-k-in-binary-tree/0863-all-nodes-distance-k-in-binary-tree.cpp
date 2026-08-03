class Solution {
    unordered_map<TreeNode*, TreeNode*> parentMap;
    
    void mapParents(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        
        if (parent) {
            parentMap[node] = parent;
        }
        
        mapParents(node->left, node);
        mapParents(node->right, node);
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        mapParents(root, nullptr);
        
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        
        q.push(target);
        visited.insert(target); 
        int currentDistance = 0;
        
        while (!q.empty()) {
            if (currentDistance == k) {
                break;
            }
            
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* current = q.front();
                q.pop();
                
                if (current->left && visited.find(current->left) == visited.end()) {
                    q.push(current->left);
                    visited.insert(current->left);
                }
                
                if (current->right && visited.find(current->right) == visited.end()) {
                    q.push(current->right);
                    visited.insert(current->right);
                }
                
                if (parentMap.find(current) != parentMap.end() && 
                    visited.find(parentMap[current]) == visited.end()) {
                    q.push(parentMap[current]);
                    visited.insert(parentMap[current]);
                }
            }
            
            currentDistance++;
        }
        
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        
        return result;
    }
};