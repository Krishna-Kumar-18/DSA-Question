class Solution {
public:
    static bool comp(pair<int, int>a, pair<int, int>b)
    {
        if(a.second == b.second)
        {
            return a.first > b.first;
        }
        return a.second < b.second;
    }

    vector<int> frequencySort(vector<int>& nums) 
    {
        map<int, int>mp;
        vector<pair<int, int>>v;
        vector<int>ans;

        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        for(auto i : mp)
        {
            v.push_back({i.first, i.second});
        }

        sort(v.begin(), v.end(), comp);

        for(auto i : v)
        {
            int count = i.second;
            while(count--)
            {
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};