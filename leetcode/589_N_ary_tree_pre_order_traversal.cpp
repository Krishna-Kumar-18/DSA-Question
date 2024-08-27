class Solution {
public:
    void solve(Node* root, vector<int>&ans)
    {
        ans.push_back(root->val);
        for(int i=0; i<root->children.size(); i++)
        {
            solve(root->children[i], ans);
        }
    }

    vector<int> preorder(Node* root) 
    {
        vector<int>ans;

        if(root==NULL)
        {
            return ans;
        }

        solve(root, ans);

        return ans;
    }
};