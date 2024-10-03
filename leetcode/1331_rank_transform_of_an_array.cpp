class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        vector<int>temp = arr;
        vector<int>ans;
        map<int, int>mp;

        sort(temp.begin(), temp.end());

        int rank = 1;
        for(int i=0; i<temp.size(); i++)
        {
            if(i==0)
            {
                mp[temp[i]] = rank;
            }
            else if(temp[i]==temp[i-1])
            {
                mp[temp[i]] = rank;
            }
            else 
            {
                rank++;
                mp[temp[i]] = rank;
            }
        }

        for(int &a : arr)
        {
            a = mp[a];
        }

        return arr;
    }
};