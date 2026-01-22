                                                //Approach using Queue

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






                                                    // Approach using Recursion

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

        if(root->left && root->left->left==NULL && root->left->right==NULL)
        {
            sum += root->left->val;
        }

        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};