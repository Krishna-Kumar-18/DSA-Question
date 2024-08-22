class Solution {
public:
    int findComplement(int num) 
    {
        for(long long int i=1; i<=num; i*=2)
        {
            num = num^i;
        }

        return num;
    }
};