class Solution {
  public:
    int solve(Node* root, int &ans)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int lh = solve(root->left, ans);
        int rh = solve(root->right, ans);
        
        ans = max(ans, lh+rh);
        
        return max(lh, rh) + 1;
    }
    int diameter(Node* root) 
    {
        int ans = 0;
        
        solve(root, ans);
        
        return ans;
    }
};