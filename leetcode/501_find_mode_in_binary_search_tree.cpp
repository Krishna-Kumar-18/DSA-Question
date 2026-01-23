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
    vector<int> findMode(TreeNode* root) 
    {
        vector<int>ans;

        if(root==NULL)
        {
            return ans;
        }

        map<int, int>mp;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            mp[temp->val]++;
            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }

        int maxi = INT_MIN;
        for(auto i : mp)
        {
            maxi = max(i.second, maxi);
        }

        for(auto i : mp)
        {
            if(i.second == maxi)
            {
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};