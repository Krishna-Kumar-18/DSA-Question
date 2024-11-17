                                                                    // Based on Sliding Window

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) 
    {
        int j=0;
        int n = nums.size();

        int ans = INT_MAX;

        vector<long long int>cummulativeSum(n);
        deque<int>dq;                                       // stores index in monotonic increasing order of cummulativeSum

        while(j<n)
        {
            if(j==0)
            {
                cummulativeSum[j] = nums[j];
            }
            else
            {
                cummulativeSum[j] = cummulativeSum[j-1] + nums[j];
            }

            if(cummulativeSum[j]>=k)
            {
                ans = min(ans, j+1);
            }

            while(!dq.empty() && cummulativeSum[j]-cummulativeSum[dq.front()]>=k)                   // check where window is shrinking or not
            {
                ans = min(ans, j-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && cummulativeSum[j] <= cummulativeSum[dq.back()])                    // check the value is dip or not
            {
                dq.pop_back();
            }

            dq.push_back(j);
            j++;
        }

        if(ans==INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};