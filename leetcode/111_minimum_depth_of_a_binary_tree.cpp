class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        int ans = 1;

        if(root==NULL)
        {
            return 0;
        }

        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL)
            {
                if(!q.empty())
                {
                    ans++;
                    q.push(NULL);
                    continue;
                }
            }

            if(!temp->left && !temp->right)
            {
                return ans;
            }

            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }

        return ans;
    }
};