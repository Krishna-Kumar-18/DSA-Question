class Solution {
  public:
    int ans = 0;
    void solve(Node *root, int data)
    {
        if(root==NULL)
        {
            return;
        }
        
        data = (data*10) + (root->data);
        
        if(root->left==NULL && root->right==NULL)
        {
            ans += data;
            return;
        }
        
        solve(root->left, data);
        solve(root->right, data);
        
        return;
    }
    
    int treePathsSum(Node *root) 
    {
        solve(root, 0);
        
        return ans;
    }
};