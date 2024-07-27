class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p==NULL && q==NULL)
        {
            return true;
        }

        if(p==NULL || q==NULL)
        {
            return false;
        }

        queue<TreeNode*>q1;
        queue<TreeNode*>q2;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty())
        {
            TreeNode* temp1 = q1.front();
            TreeNode* temp2 = q2.front();

            q1.pop();
            q2.pop();

            if(temp1->val != temp2->val)
            {
                return false;
            }

            if(temp1->left!=NULL && temp2->left!=NULL)
            {
                q1.push(temp1->left);
                q2.push(temp2->left);
            }

            if(temp1->left==NULL && temp2->left!=NULL)
            {
                return false;
            }

            if(temp1->left!=NULL && temp2->left==NULL)
            {
                return false;
            }

            if(temp1->right!=NULL && temp2->right!=NULL)
            {
                q1.push(temp1->right);
                q2.push(temp2->right);
            }

            if(temp1->right==NULL && temp2->right!=NULL)
            {
                return false;
            }

            if(temp1->right!=NULL && temp2->right==NULL)
            {
                return false;
            }
        }
        return true;
    }
};