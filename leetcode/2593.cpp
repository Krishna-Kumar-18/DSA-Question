class Solution {
public:
    static bool comp(pair<int, int>a, pair<int, int>b)
    {
        if(a.first == b.first)
        {
            return a.second < b.second;
        }

        return a.first < b.first;
    }

    long long findScore(vector<int>& nums) 
    {
        int n = nums.size();

        vector<pair<int, int>>v;

        vector<bool>vis(n, false);

        for(int i=0; i<n; i++)
        {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end(), comp);

        long long int score = 0;

        for(auto i : v)
        {
            int smallest = i.first;
            int ind = i.second;

            if(vis[ind]==false)
            {
                score += smallest;

                vis[ind] = true;

                if(ind-1>=0)
                {
                    vis[ind-1] = true;
                }

                if(ind+1<n)
                {
                    vis[ind+1] = true;
                }
            }
        }

        return score;
    }
};