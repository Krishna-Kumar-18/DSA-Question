class Solution {
public:
    int solve(TreeNode* root, int &height)
    {
        if(root==NULL)
        {
            return 0;
        }

        int left = solve(root->left, height) + 1;
        int right = solve(root->right, height) + 1;

        if(abs(left-right) > 1)
        {
            height = 0;
        }

        return max(left, right);
    }

    bool isBalanced(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }

        int height = 1;

        solve(root, height);

        if(height)
        {
            return true;
        }

        return false;
    }
};