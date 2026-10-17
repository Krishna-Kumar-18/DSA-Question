class Solution {
public:
    int minSwaps(vector<int>& nums) 
    {
        int n = nums.size();

        vector<pair<int, int>>srtdArr;

        for(int i=0; i<n; i++)
        {
            int sum = 0;
            int num = nums[i];
            while(num > 0)
            {
                int temp = num%10;
                sum += temp;
                num = num/10;
            }

            srtdArr.push_back({sum, nums[i]});
        }

        sort(srtdArr.begin(), srtdArr.end());

        unordered_map<int, int>pos;
        for(int i=0; i<n; i++)
        {
            pos[srtdArr[i].second] = i;
        }

        vector<int>vis(n, 0);
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(vis[i])
            {
                continue;
            }

            int idx = i;
            int cycle_ele = 0;
            while(!vis[idx])
            {
                vis[idx] = 1;
                cycle_ele++;

                idx = pos[nums[idx]];
            }

            ans += (cycle_ele - 1);
        }

        return ans;
    }
};