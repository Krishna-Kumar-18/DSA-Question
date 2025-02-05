class Solution {
public:
    bool areAlmostEqual(string s1, string s2) 
    {
        int n = s1.length();
        int m = s2.length();

        vector<int>v;

        if(n!=m)
        {
            return false;
        }

        for(int i=0; i<n; i++)
        {
            if(s1[i] != s2[i])
            {
                v.push_back(i);
            }
        }

        if(v.size() == 0)
        {
            return true;
        }

        if(v.size() != 2)
        {
            return false;
        }

        swap(s1[v[0]], s1[v[1]]);

        if(s1 == s2)
        {
            return true;
        }

        return false;
    }
};