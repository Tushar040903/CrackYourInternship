void solve(TreeNode* root) {
        if(root == NULL) return ;

        TreeNode* leftSubTree = root->left;

        root->left = root->right;
        root->right = leftSubTree;

        solve(root->left);
        solve(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {

        solve(root);

        return root;
        
    }