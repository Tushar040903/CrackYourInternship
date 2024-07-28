int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        int ans = max(left,right) + 1;

        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = maxDepth(root->left) + maxDepth(root->right);

        int ans = max(op1,max(op2,op3));

        return ans;
    }