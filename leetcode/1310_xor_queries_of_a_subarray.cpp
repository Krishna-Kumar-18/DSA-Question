class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        vector<int>ans;

        int size = queries.size();

        for(int i=0; i<size; i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];

            bool flag = true;
            int temp;

            if(start==end)
            {
                ans.push_back(arr[start]);
                continue;
            }
            
            for(int i=start; i<=end; i++)
            {
                if(flag)
                {
                    temp = arr[i]^arr[i+1];
                    flag = false;
                    i++;
                }
                else 
                {
                    temp = temp ^ arr[i];
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};