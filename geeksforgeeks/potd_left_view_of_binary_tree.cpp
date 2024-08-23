vector<int> leftView(Node *root)
{
    vector<int>ans;
    
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    
    ans.push_back(root->data);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        
        if(temp==NULL)
        {
            if(!q.empty())
            {
                ans.push_back(q.front()->data);
                q.push(NULL);
            }
        }
        else
        {
            if(temp->left)
            {
                q.push(temp->left);
            }
            
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    
    return ans;
}