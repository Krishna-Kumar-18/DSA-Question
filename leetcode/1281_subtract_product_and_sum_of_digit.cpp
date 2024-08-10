class Solution {
public:
    int subtractProductAndSum(int n) 
    {
        long long int sum = 0;
        long long int prod = 1;

        while(n>0)
        {
            int num = n%10;
            sum += num;
            prod = prod * num;
            n=n/10;
        }
        
        return prod-sum;
    }
};