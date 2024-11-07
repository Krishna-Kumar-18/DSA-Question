class Solution {
public:
    int largestCombination(vector<int>& candidates) 
    {
        int ans = INT_MIN;

        for(int i=0; i<32; i++)                                             // count the no of set bit of each element one by one in for loop
        {                                                                   // for bitwise & > 0 one bit should be same of two element
            int count = 0;                                                              
            for(int j=0; j<candidates.size(); j++)
            {
                if(candidates[j]&1)
                {
                    count++;
                }
                candidates[j] = candidates[j]>>1;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};