class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        int n = nums.size();
        vector<long long int>square;
        for(int i=0; i<n; i++)
        {
            long long int sq = nums[i] * nums[i];
            square.push_back(sq);
        }
        
        sort(square.begin(), square.end());

        long long int i = 0;
        long long int diff_sum = 0;
        long long int plus_sum = 0;
        while(i < n/2)
        {
            diff_sum += square[i];
            plus_sum += square[n-i-1];
            i++;
        }

        if(n%2==0)
        {
            return plus_sum - diff_sum;
        }

        return plus_sum + square[i] - diff_sum;
    }
};