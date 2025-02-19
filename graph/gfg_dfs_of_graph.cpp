class Solution {
  public:
    void dfs(vector<vector<int>>&adj, vector<int>&bfs, vector<int>&vis, int start)
    {
        bfs.push_back(start);
        vis[start] = 1;
        
        for(auto it : adj[start])
        {
            if(!vis[it])
            {
                dfs(adj, bfs, vis, it);
            }
        }
    }
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) 
    {
        int n = adj.size();
        
        vector<int>vis(n, 0);
        
        vector<int>bfs;
        
        int start = 0;
        
        dfs(adj, bfs, vis, start);
        
        return bfs;
    }
};