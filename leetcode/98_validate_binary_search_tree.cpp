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
    bool isValidBST(TreeNode* root) 
    {
        stack<TreeNode*>st;

        TreeNode* node = root;
        int prev = INT_MIN;
        bool flag = true;

        while(true)
        {
            if(node)
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

                int next =  st.top()->val;

                if(flag)
                {
                    prev = st.top()->val;
                    flag = false;
                }
                else
                {
                    if(prev>=next)
                    {
                        return false;
                    }
                    prev = next;
                }

                node = st.top();
                st.pop();
                node = node->right;
            }
        }

        return true;
    }
};