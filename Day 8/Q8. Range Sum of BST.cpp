void traversal(TreeNode* root, int low, int high, int &ans) {
        // base case
        if(root == NULL) return ;

        traversal(root->left,low,high,ans);

        if(root->val >= low && root->val <= high) ans = ans+root->val;

        
        traversal(root->right,low,high,ans);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        //if(root == NULL) return 0;
        int ans = 0;
        traversal(root,low,high,ans);

        return ans;
    }