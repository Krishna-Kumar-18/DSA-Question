class Solution{
    public:
    bool solve(vector<int>&arr, int k, int ind, int sum)
    {
        if(ind==arr.size())
        {
            if(sum==k)
            {
                return true;
            }
            return false;
        }
        
        if(sum>k)
        {
            return false;
        }
        
        sum += arr[ind];
        
        if(solve(arr, k, ind+1, sum) == true)
        {
            return true;
        }
        
        sum -= arr[ind];
        
        if(solve(arr, k, ind+1, sum) == true)
        {
            return true;
        }
        
        return false;
    }
    
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) 
    {
        
        bool flag = false;
        
        int ind = 0;
        
        bool ans = solve(arr, k, 0, 0);
        
        return ans;
    }
};