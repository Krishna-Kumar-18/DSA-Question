class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        int n = values.size();

        int maxi = INT_MIN;

        int first = values[0] + 0;

        for(int i=1; i<n; i++)
        {
            int second = values[i] - i;

            maxi = max(maxi, first+second);

            first = max(first, values[i]+i);
        }

        return maxi;
    }
};