class Solution {
    unordered_map<int, int> inorderMap;
    int postorderIndex;

    TreeNode* build(vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        int rootVal = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIndex = inorderMap[rootVal];

      
        root->right = build(postorder, inRootIndex + 1, inEnd);
        
        root->left = build(postorder, inStart, inRootIndex - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        
        for (int i = 0; i < n; ++i) {
            inorderMap[inorder[i]] = i;
        }
        
        postorderIndex = n - 1;
        
        return build(postorder, 0, n - 1);
    }
};