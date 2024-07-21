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


// Second Approach

class Solution {
public:
    int leftHeight(TreeNode* root)
    {
        int lh = 0;
        if(root)
        {
            while(root)
            {
                lh++;
                root = root->left;
            }
        }
        return lh;
    }

    int rightHeight(TreeNode* root)
    {
        int rh = 0;
        if(root)
        {
            while(root)
            {
                rh++;
                root = root->right;
            }
        }
        return rh;
    }

    int countNodes(TreeNode* root) 
    {
        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh==rh)
        {
            return pow(2, lh) - 1;
        }
        else 
        {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};