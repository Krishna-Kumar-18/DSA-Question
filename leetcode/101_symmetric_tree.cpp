class Solution {
public:
    bool check(TreeNode* left, TreeNode* right)
    {
        if(left==NULL && right==NULL)
        {
            return true;
        }

        if(left==NULL || right==NULL)
        {
            return false;
        }

        if(left->val==right->val && check(left->left, right->right) && check(left->right, right->left))
        {
            return true;
        }

        return false;
    }

    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }

        return check(root->left, root->right);
    }
};