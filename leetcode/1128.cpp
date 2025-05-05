class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        for(int i=0; i<dominoes.size(); i++)
        {
            if(dominoes[i][0] > dominoes[i][1])
            {
                swap(dominoes[i][0], dominoes[i][1]);
            }
        }

        map<vector<int>, int>mp;

        for (auto i : dominoes) 
        {
            mp[i]++;
        }

        int count = 0;
        
        for(auto i : mp)
        {
            if(i.second>1)
            {
                int a = ((i.second)*(i.second-1))/2;

                count += a;
            }
        }

        return count;
    }
};
