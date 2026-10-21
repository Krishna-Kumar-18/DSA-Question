class Solution {
public:
    int minOperations(string s) 
    {
        int n = s.length(); 

        int ans = 0;

        int maxi = INT_MIN;
        int max_ind = 0;
        int mini = INT_MAX;
        int mini_ind = 0;
        bool flag = true;
        for(int i=0; i<n; i++)
        {
            int curr = s[i]-'a';
            
            int forward = 0;
            if(i < n-1)
            {
                forward = s[i+1]-'a';
            }

            maxi = max(maxi, curr);

            if(mini != curr)
            {
                mini = min(mini, curr);
                if(mini == curr)
                {
                    mini_ind = i;
                }
            }
            
            if(maxi == curr)
            {
                max_ind = i;
            }

            if(i < n-1)
            {
                int forward = s[i+1]-'a';
                if(curr > forward)
                {
                    flag = false;
                }
            }
        }

        if(flag)
        {
            return 0;
        }

        if(max_ind == n-1 || mini_ind == 0)
        {
            return 1;
        }

        if(n==2)
        {
            return -1;
        }

        if(max_ind==0 && mini_ind==n-1)
        {
            return 3;
        }

        return 2;
    }
};