class Solution {
public:
    void solve(int ind, int target, vector<int>&candidates, vector<vector<int>>&ans, vector<int>&temp)
    {
        if(ind == candidates.size())
        {
            if(target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }

        if(candidates[ind]<=target)
        {
            temp.push_back(candidates[ind]);
            solve(ind, target-candidates[ind], candidates, ans, temp);
            temp.pop_back();
        }

        solve(ind+1, target, candidates, ans, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        vector<int>temp;

        int ind = 0;

        solve(ind, target, candidates, ans, temp);

        return ans;
    }
};