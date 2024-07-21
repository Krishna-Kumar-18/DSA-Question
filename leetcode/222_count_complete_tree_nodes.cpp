class Solution {
public:
    int countNodes(TreeNode* root) 
    {
        queue<TreeNode*>q;

        if(root==NULL)
        {
            return 0;
        }

        q.push(root);

        int count = 0;
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            count++;
            
            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }

        return count;
    }
};