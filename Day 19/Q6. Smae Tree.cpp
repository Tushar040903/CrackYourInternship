bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case
        if(p == NULL && q == NULL) {
            return true;
        }
        if(q == NULL || p == NULL || p->val != q->val) {
            return false;
        }

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }