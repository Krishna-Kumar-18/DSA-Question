class Solution {
public:
    static bool comp(pair<int, int>&a, pair<int, int>&b)
    {
        return a.first < b.first;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
    {
        vector<int>ans;
        map<int, int>mp;
        vector<int>temp;

        vector<pair<int, int>>v(items.size());
        for(int i=0; i<items.size(); i++)
        {
            v[i].first = items[i][0];
            v[i].second = items[i][1];
        }
        
        sort(v.begin(), v.end(), comp);

        int maxi = INT_MIN;
        for(int i=0; i<v.size(); i++)
        {
            maxi = max(maxi, v[i].second);
            mp[v[i].first] = maxi;
            temp.push_back(v[i].first);
        }

        sort(temp.begin(), temp.end());

        for(int i=0; i<queries.size(); i++)
        {
            int low = 0;
            int high = temp.size()-1;
            int ele = queries[i];

            bool flag = false;
            while(low<=high)
            {
                int mid = (low+high)/2;

                if(temp[mid]==ele)
                {
                    int beauty = mp[ele];
                    ans.push_back(beauty);
                    flag = true;
                    break;
                }                                       
                else if(temp[mid]<ele)
                {
                    low = mid+1;
                }
                else 
                {
                    high = mid-1;               
                }

            }
            
            if(!flag)
            {
                if(high==-1)
                {
                    int beauty = temp[high+1];
                    if(beauty <= ele)
                    {
                        ans.push_back(mp[beauty]);
                    }
                    else 
                    {
                        ans.push_back(0);
                    }
                }
                else 
                {
                    int beauty = temp[high];
                    ans.push_back(mp[beauty]);
                }
            }
        }

        return ans;
    }
};