 bool isValidBST(TreeNode *root) {
        long long inOrder = (long long)INT_MIN - 1;
        stack<TreeNode*> stack;
        while(!stack.empty() || root != nullptr){
            while(root != nullptr){
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if(root->val <= inOrder)    return false;
            inOrder = root->val;
            root = root->right;
        }
        return true;
    }