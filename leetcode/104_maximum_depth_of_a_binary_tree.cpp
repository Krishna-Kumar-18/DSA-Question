class Solution {
public:
    int solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int left = solve(root->left) + 1;
        int right = solve(root->right) + 1;

        return max(left, right);
    }

    int maxDepth(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }

        return solve(root);
    }
};