class Solution {
public:
    std::vector<int> inor(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> s;
        TreeNode* current = root;

        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();

            result.push_back(current->val);

            current = current->right;
        }
        return result;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> r = inor(root);
        
        if (r.size() < 2) return false;

        int i = 0;
        int j = r.size() - 1;
        
        while (i < j) {
            int sum = r[i] + r[j];
            
            if (sum == k) {
                return true;
            } else if (sum < k) {
                i++;
            } else { 
                j--;
            }
        }

        return false;
    }
};