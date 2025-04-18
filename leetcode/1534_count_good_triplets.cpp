class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) 
    {
        int count = 0;

        for(int i=0; i<arr.size()-2; i++)
        {
            for(int j=i+1; j<arr.size()-1; j++)
            {
                for(int k=j+1; k<arr.size(); k++)
                {
                    int diff_1 = abs(arr[i]-arr[j]);
                    int diff_2 = abs(arr[j]-arr[k]);
                    int diff_3 = abs(arr[k]-arr[i]);

                    if(diff_1<=a && diff_2<=b && diff_3<=c)
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
