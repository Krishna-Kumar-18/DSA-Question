class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        unordered_set<int>st;
        int ans = 0;

        for(auto &i : arr1)
        {
            while(i>0)
            {
                st.insert(i);
                i=i/10;
            }
        }

        for(auto &i : arr2)
        {
            while(i>0)
            {
                if(st.find(i)!=st.end())
                {
                    ans = max(ans, static_cast<int>(log10(i) + 1));
                }

                i = i/10;
            }
        }

        return ans;
    }
};