class Solution {
  public:
    void solve(vector<int>&arr, vector<int>&ans, int sum, int ind)
    {
        if(ind>=arr.size())
        {
            ans.push_back(sum);
            return;
        }
        
        sum += arr[ind];
        solve(arr, ans, sum, ind+1);
        sum -= arr[ind];
        solve(arr, ans, sum, ind+1);
    }
    
    vector<int> subsetSums(vector<int>& arr) 
    {
        vector<int>ans;
        vector<int>temp;
        
        solve(arr, ans, 0, 0);
        
        return ans;
    }
};