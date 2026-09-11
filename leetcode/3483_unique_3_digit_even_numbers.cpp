class Solution {
public:
    void solve(vector<int>&digits, vector<int>&temp, set<vector<int>>&ans, vector<bool>&used)
    {
        if(temp.size() == 3)
        {
            if(temp[temp.size()-1]%2==0)
            {
                ans.insert(temp);
            }
            return;
        }

        for(int i=0; i<digits.size(); i++)
        {
            if(used[i])
            {
                continue;
            }

            if(temp.size()==0 && digits[i]==0)
            {
                continue;
            }

            used[i] = true;

            temp.push_back(digits[i]);
            solve(digits, temp, ans, used);

            temp.pop_back();
            used[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) 
    {
        int n = digits.size();

        set<vector<int>>ans;
        vector<int>temp;
        vector<bool>used(n, false);

        solve(digits, temp, ans, used);

        return ans.size();
    }
};