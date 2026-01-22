/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }   

        int sum = 0;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left)
            {
                q.push(temp->left);
                TreeNode* tempLeft = temp->left;
                if(tempLeft->left==NULL && tempLeft->right==NULL)
                {
                    sum += tempLeft->val;
                }
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }

        return sum;
    }
};