                                                                // Done Using Sorting

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        sort(gifts.begin(), gifts.end());

        long long int n = gifts.size();

        while(k--)
        {
            gifts[n-1] = sqrt(gifts[n-1]);
            sort(gifts.begin(), gifts.end());
        }

        long long int sum = 0;

        for(auto i : gifts)
        {
            sum += i;
        }

        return sum;
    }
};