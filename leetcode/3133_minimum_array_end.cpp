class Solution {
public:
    long long minEnd(int n, int x) 
    {
        long long int num = x;

        for(int i=1; i<n; i++)
        {
            num = (num+1) | x;              // taking OR with just greater number give the next number whose & will be same
        }

        return num;
    }
};