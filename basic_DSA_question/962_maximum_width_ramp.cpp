                // Based on Monotonic Stack

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        stack<pair<int, int>>st;

        for(int i=0; i<nums.size(); i++)
        {
            if(st.empty() || nums[i]<st.top().first)
            {
                st.push({nums[i], i});
            }
        }

        int ans = 0;

        for(int i=nums.size()-1; i>=0; i--)
        {
            while(!st.empty() && st.top().first<=nums[i])
            {
                ans = max(ans, (i-st.top().second));
                st.pop();
            }
        }

        return ans;
    }
};