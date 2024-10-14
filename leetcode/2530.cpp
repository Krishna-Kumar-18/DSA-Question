class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) 
    {
        priority_queue<long long int>pq;

        for(int i=0; i<nums.size(); i++)
        {
            pq.push(nums[i]);
        }

        long long int ans = 0;

        while(k--)
        {
            long double ele = pq.top();
            pq.pop();

            ans += ele;
            
            ele = ceil(ele/3);
            pq.push(ele);       
        }

        return ans;
    }
};