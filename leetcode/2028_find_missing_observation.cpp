class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        vector<int>ans;

        long long int sum = 0;
        for(int i=0; i<rolls.size(); i++)
        {
            sum += rolls[i];
        }

        long long int total = rolls.size() + n;

        long long int mul = total * mean;
        long long int diff = mul - sum;
        
        if(n>diff)
        {
            return ans;
        }

        long long int max_sum = n * 6;
        if(max_sum>=diff)
        {
            int div = diff/n;

            for(int i=0; i<n; i++)
            {
                ans.push_back(div);
            }

            int mod = diff%n;
            for(int i=0; i<ans.size(); i++)
            {
                int diff = 6-ans[i];
                if(mod<=diff)
                {
                    ans[i] += mod;
                    return ans;
                }
                ans[i] += diff;
                mod -= diff;
            }
        }
        return ans;
    }
};