class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        vector<vector<int>>ans;
        vector<int>temp;

        int i=0;
        for(int j=0; j<m; j++)
        {
            temp.clear();
            if(i==original.size())
            {
                ans.clear();
                return ans;
            }
            for(int k=0; k<n; k++)
            {
                if(i==original.size())
                {
                    ans.clear();
                    return ans;
                }
                temp.push_back(original[i]);
                i++;
            }
            ans.push_back(temp);
        }

        if(i<=original.size()-1)
        {
            ans.clear();
            return ans;
        }

        return ans;
    }
};