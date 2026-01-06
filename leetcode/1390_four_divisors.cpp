class Solution {
public:
    int sumFourDivisors(vector<int>& nums) 
    {
        int n = nums.size(); 
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int count = 0;
            bool flag = true;
            int sum = 0;
            for(int j=1; j<=nums[i]/2; j++)
            {
                if(nums[i]%j==0)
                {
                    count++;

                    sum += j;

                    if(count == 4)
                    {
                        flag = false;
                        break;
                    }
                }
            }

            count++;
            if(flag)
            {
                if(count == 4)
                {
                    sum += nums[i];
                    ans += sum;
                }
            }
        }

        return ans;
    }
};