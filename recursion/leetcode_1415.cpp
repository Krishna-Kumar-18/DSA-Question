class Solution {
public:
    void solve(int n, vector<string>&result, string curr)
    {
        if(curr.size() == n)
        {
            result.push_back(curr);
            return;
        }

        for(char ch='a'; ch<='c'; ch++)
        {
            if(!curr.empty() && ch==curr.back())
            {
                continue;
            }

            curr.push_back(ch);
            solve(n, result, curr);
            curr.pop_back();
        }

        return;
    }
    string getHappyString(int n, int k) 
    {
        vector<string>result;
        string curr = "";

        solve(n, result, curr);

        if(k > result.size())
        {
            return "";
        }

        return result[k-1];
    }
};