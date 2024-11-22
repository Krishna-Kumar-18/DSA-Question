class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
    {
        unordered_map<string, int>mp;

        for(int i=0; i<matrix.size(); i++)
        {
            string temp = "";
            for(int j=0; j<matrix[0].size(); j++)
            {
                temp += to_string(matrix[i][j]);
            }
            mp[temp]++;
            
            for(int i=0; i<temp.size(); i++)
            {
                if(temp[i]=='0')
                {
                    temp[i] = '1';
                }
                else 
                {
                    temp[i] = '0';
                }
            }
            mp[temp]++;
        }

        int ans = INT_MIN; 
        for(auto i : mp)
        {
            ans = max(i.second, ans);
        }

        return ans;
    }
};