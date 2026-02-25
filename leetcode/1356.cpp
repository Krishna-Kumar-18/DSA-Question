class Solution {
public:
    static bool comp(pair<int, int>a, pair<int, int>b)
    {
        if(a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
    vector<int> sortByBits(vector<int>& arr) 
    {
        vector<int>ans;
        vector<pair<int, int>>v;

        for(int i=0; i<arr.size(); i++)
        {
            int num = arr[i];
            int count = 0;

            while(num > 0)
            { 
                int last_bit = num & 1;
                num = num >> 1;

                if(last_bit == 1)
                {
                    count++;
                }
            }

            v.push_back({arr[i], count});
        }

        sort(v.begin(), v.end(), comp);

        for(auto i : v)
        {
            ans.push_back(i.first);
        }

        return ans;
    }
};