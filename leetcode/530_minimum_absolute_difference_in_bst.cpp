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
    int getMinimumDifference(TreeNode* root) 
    {
        if(root == NULL)
        {
            return 0;
        }

        int mini = INT_MAX;

        vector<int>v;

        stack<TreeNode*>st;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* temp = st.top();
            st.pop();

            v.push_back(temp->val);
            if(temp->right)
            {
                st.push(temp->right);
            }

            if(temp->left)
            {
                st.push(temp->left);
            }
        }

        sort(v.begin(), v.end());

        for(int i=0; i<v.size()-1; i++)
        {
            mini = min(mini, (v[i+1]-v[i]));
        }

        return mini;
    }
};







                                                // In-Order gives Sorted BST
                
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
    int getMinimumDifference(TreeNode* root) 
    {
        stack<TreeNode*>st;
        int prev = 0;
        int mini = INT_MAX;
        bool flag = true;

        while(true)
        {
            if(root!=NULL)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                if(st.empty())
                {
                    break;
                }

                root = st.top();
                st.pop();

                if(flag)
                {
                    prev = root->val;
                    flag = false;
                }
                else
                {
                    mini = min(mini, abs(prev - root->val));
                    prev = root->val;
                }

                root = root->right;
            }
        }

        return mini;
    }
};