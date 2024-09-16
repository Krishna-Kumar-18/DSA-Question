class Solution {
public:
    int findMinDifference(vector<string>& timePoints) 
    {
        vector<int>v;

        for(int i=0; i<timePoints.size(); i++)
        {
            string h = timePoints[i].substr(0, 2);
            string m = timePoints[i].substr(3);

            int total_time = stoi(h) * 60 + stoi(m);
            v.push_back(total_time);
        }

        sort(v.begin(), v.end());

        v.push_back(v[0] + 24*60);

        int ans = INT_MAX;
        for(int i=1; i<v.size(); i++)
        {
            ans = min(ans, (v[i]-v[i-1]));
        }

        return ans;
    }
};