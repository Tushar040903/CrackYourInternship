bool solve(TreeNode* root, int targetSum, int sum) {
        if(root == NULL) return 0;

        sum = sum + root->val;

        if(root->left == NULL && root->right == NULL) {
            if(sum == targetSum) return true;
        } 

        int left = solve(root->left, targetSum, sum);
        int right = solve(root->right, targetSum, sum);

        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = solve(root, targetSum, sum);

        return ans;
    }