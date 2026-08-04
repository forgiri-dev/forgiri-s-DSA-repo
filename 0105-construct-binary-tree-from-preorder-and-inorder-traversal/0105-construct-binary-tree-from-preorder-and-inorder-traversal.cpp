class Solution {
    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;

    TreeNode* build(vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIndex = inorderMap[rootVal];

        root->left = build(preorder, inStart, inRootIndex - 1);
        
        root->right = build(preorder, inRootIndex + 1, inEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        
        return build(preorder, 0, inorder.size() - 1);
    }
};