class Solution {
public:
    static bool comp(pair<int, int>a, pair<int, int>b)
    {
        return a.first > b.first;
    }

    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) 
    {
        int no_rows = rowSum.size();
        int col_rows = colSum.size();

        vector<pair<int, int>>v;

        for(int i=0; i<no_rows; i++)
        {
            v.push_back({rowSum[i], i});
        }

        sort(v.begin(), v.end(), comp);

        vector<vector<int>>ans;
        vector<int>temp;

        for(int i=0; i<no_rows; i++)
        {
            for(int j=0; j<col_rows; j++)
            {
                temp.push_back(0);
            }
            ans.push_back(temp);
            temp.clear();
        }

        int k=0;
        int diff = -1;
        for(int i=0; i<col_rows; i++)
        {
            int num = colSum[i];
            while(num>0)
            {
                int ind = v[0].second;
                int n = v[0].first;
                ans[ind][i] = min(num, n);

                if(num>=n)
                {
                    diff = 0;
                }
                else 
                {
                    diff = abs(n - num);
                }

                num = num - n;
                v.erase(v.begin()+k);
                v.push_back({diff, ind});
                sort(v.begin(), v.end(), comp);
            }
        }
        return ans;
    }
};