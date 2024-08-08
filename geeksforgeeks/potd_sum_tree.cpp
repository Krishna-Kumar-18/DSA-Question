class Solution {
  public:
    int solve(Node* root, bool &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            return root->data;
        }
        
        int left_sum = solve(root->left, ans);
        int right_sum = solve(root->right, ans);
        
        if(left_sum+right_sum != root->data)
        {
            ans = false;
        }
        
        return left_sum + right_sum + root->data;
    }
    
    bool isSumTree(Node* root) 
    {
        bool ans = true;
        
        solve(root, ans);
        
        return ans;
    }
};