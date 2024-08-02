int solve(TreeNode* root) {
        if(root == NULL) return 0;

        int leftAns = 1 + solve(root->left);
        int rightAns = 1 + solve(root->right);

        return max(leftAns, rightAns);
    }
    int maxDepth(TreeNode* root) {

        int ans = solve(root);
        return ans;
    }