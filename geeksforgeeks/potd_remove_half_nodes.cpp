class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        
        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);
        
        if(root->left!=NULL && root->right==NULL)
        {
            return root->left;
        }
        
        if(root->left==NULL && root->right!=NULL)
        {
            return root->right;
        }
        
        return root;
    }
};