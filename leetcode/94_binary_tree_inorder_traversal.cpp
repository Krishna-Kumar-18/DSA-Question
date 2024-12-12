                                                                // Using Recursion

class Solution {
public:
    void inOrder(TreeNode* root, vector<int>&ans)
    {
        if(root!=NULL)
        {
            inOrder(root->left, ans);
            ans.push_back(root->val);
            inOrder(root->right, ans);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>ans;

        inOrder(root, ans);

        return ans;
    }
};







                                                                // Iterative Approach or Done is using stack


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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>inOrder;

        stack<TreeNode*>st;

        if(root == NULL)
        {
            return inOrder;
        }

        TreeNode* node = root;

        while(true)
        {
            if(node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if(st.empty())
                {
                    break;
                }

                node = st.top();
                st.pop();
                
                inOrder.push_back(node->val);
                node = node->right;
            }
        }

        return inOrder;
    }
};