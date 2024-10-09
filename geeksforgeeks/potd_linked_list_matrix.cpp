class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        
        vector<vector<Node*>>Nodmat(n, vector<Node*>(n, NULL));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                Nodmat[i][j] = new Node(mat[i][j]);
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j<n-1)
                {
                    Nodmat[i][j]->right = Nodmat[i][j+1];
                }
                
                if(i<n-1)
                {
                    Nodmat[i][j]->down = Nodmat[i+1][j];
                }
            }
        }
        
        return Nodmat[0][0];
    }
};