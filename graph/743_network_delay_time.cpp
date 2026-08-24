class Solution {
public:
    int dijkstra(vector<vector<pair<int, int>>>&adj, int n, int source)
    {
        vector<int>dist(n+1, INT_MAX);
        set<pair<int, int>>st;

        st.insert({source, 0});
        dist[source] = 0;

        while(!st.empty())
        {
            auto node = *st.begin();
            st.erase(node);

            int v = node.first;
            int d = node.second;

            for(auto i : adj[v])
            {
                int vertex = i.first;
                int distance = i.second;

                if(distance + dist[v] < dist[vertex])
                {
                    dist[vertex] = distance + dist[v];

                    st.insert({vertex, dist[vertex]});
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1; i<=n; i++)
        {
            if(dist[i]==INT_MAX)
            {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int, int>>>adj(n+1);

        for(int i=0; i<times.size(); i++)
        {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        return dijkstra(adj, n, k);
    }
};