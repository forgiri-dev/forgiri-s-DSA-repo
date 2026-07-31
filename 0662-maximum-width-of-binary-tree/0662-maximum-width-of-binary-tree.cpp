class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int maxwidth = 0;
        
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            int levelSize = q.size();
            
            long long minIndex = q.front().second;
            long long first = 0, last = 0;
            
            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front().first;
                long long normalizedIndex = q.front().second - minIndex;
                q.pop();
                
                if (i == 0) first = normalizedIndex;
                if (i == levelSize - 1) last = normalizedIndex;
                
                if (node->left != nullptr) {
                    q.push({node->left, 2 * normalizedIndex + 1});
                }
                if (node->right != nullptr) {
                    q.push({node->right, 2 * normalizedIndex + 2});
                }
            }
            

            int currentWidth = static_cast<int>(last - first + 1);
            maxwidth = max(maxwidth, currentWidth);
        }
        
        return maxwidth;
    }
};