class Solution {
public:
    static bool comp(pair<string, int>a, pair<string, int>b)
    {
        return a.second > b.second;
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        vector<pair<string, int>>v;
        vector<string>ans;

        for(int i=0; i<names.size(); i++)
        {
            v.push_back({names[i], heights[i]});
        }

        sort(v.begin(), v.end(), comp);

        for(auto i : v)
        {
            ans.push_back(i.first);
        }

        return ans;
    }
};