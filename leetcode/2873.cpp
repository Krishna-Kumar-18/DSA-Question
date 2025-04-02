class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int>left_maxi(n);
        vector<int>right_maxi(n);

        for(int i=1; i<n; i++)
        {
            left_maxi[i] = max(left_maxi[i-1], nums[i-1]);
        }

        for(int i=n-2; i>=0; i--)
        {
            right_maxi[i] = max(right_maxi[i+1], nums[i+1]);
        }


        long long ans = 0;

        for(int i=1; i<n; i++)
        {
            ans = max(ans, (long long) (left_maxi[i]-nums[i])*right_maxi[i]);
        }

        if(ans < 0)
        {
            return 0;
        }

        return ans;
    }
};
