bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case
        if(p == NULL && q == NULL) {
            return true;
        }
        if(q == NULL || p == NULL || p->val != q->val) {
            return false;
        }

        return isSameTree(p->left,q->right) && isSameTree(p->right,q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left , root->right);
    }