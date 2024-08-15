class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int count_5=0;
        int count_10=0;
        for(int i=0; i<bills.size(); i++)
        {
            if(bills[i]==5)
            {
                count_5++;
            }
            else if(bills[i]==10)
            {
                if(count_5==0)
                {
                    return false;
                }
                else 
                {
                    count_5--;
                }
                count_10++;
            }
            else if(bills[i]==20)
            {
                if(count_5==0)
                {
                    return false;
                }
                else if(count_10==0)
                {
                    if(count_5>=3)
                    {
                        count_5 -= 3;
                    }
                    else 
                    {
                        return false;
                    }
                }
                else 
                {
                    count_10--;
                    count_5--;
                }
            }
        }
        return true;
    }
};