                                            // Recursion Approach

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
    void checkSum(TreeNode* root, int targetSum, int sum, bool &flag)
    {
        if(root == NULL)
        {
            return;
        }

        sum += root->val;
        if(root->left==NULL && root->right==NULL)
        {
            if(sum == targetSum)
            {
                flag = true;
            }
            sum -= root->val;
        }

        checkSum(root->left, targetSum, sum, flag);

        checkSum(root->right, targetSum, sum, flag);
    }

    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if(root == NULL)
        {
            return false;
        }

        bool flag = false;
        int sum = 0;

        checkSum(root, targetSum, sum, flag);

        if(flag)
        {
            return true;
        }

        return false;
    }
};





                                                //Stack Approach

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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root==NULL)
        {
            return false;
        }

        stack<pair<TreeNode*, int>>st;
        st.push({root, root->val});

        while(!st.empty())
        {
            auto [node, currSum] = st.top();
            st.pop();

            if(node->left==NULL && node->right==NULL)
            {
                if(currSum == targetSum)
                {
                    return true;
                }
            }

            if(node->right)
            {
                st.push({node->right, currSum + node->right->val});
            }

            if(node->left)
            {
                st.push({node->left, currSum + node->left->val});
            }
        }

        return false;
    }
};