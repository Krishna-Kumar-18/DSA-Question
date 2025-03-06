class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        int range = n * n;

        vector<int> ans;

        map<int, int>mp;

        for(auto i : grid)
        {
            for(auto j : i)
            {
                mp[j]++;
                if(mp[j]==2)
                {
                    ans.push_back(j);
                }
            }
        }

        for(int i=1; i<=n*n; i++)
        {
            if(mp[i] == 0)
            {
                ans.push_back(i);
                return ans;
            }
        }

        return ans;
    }
};
