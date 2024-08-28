
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>>ans;
        queue<Node*>q;

        if(root==NULL)
        {
            return ans;
        }

        q.push(root);

        while(!q.empty())
        {
            int n = q.size();

            vector<int>t;

            for(int i=0; i<n; i++)
            {
                Node* temp = q.front();
                q.pop();

                for(int j=0; j<temp->children.size(); j++)
                {
                    q.push(temp->children[j]);
                }
                t.push_back(temp->val);
            }
            ans.push_back(t);
        }
        return ans;
    }
};