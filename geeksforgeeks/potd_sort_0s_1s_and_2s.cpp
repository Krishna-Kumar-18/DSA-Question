class Solution {
  public:
    void sort012(vector<int>& arr) 
    {
        int count_0 = 0, count_1 = 0, count_2 = 0;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] == 0)
            {
                count_0++;
            }
            else if(arr[i] == 1)
            {
                count_1++;
            }
            else
            {
                count_2++;
            }
        }
        
        for(int i=0; i<arr.size(); i++)
        {
            if(count_0>0)
            {
                arr[i] = 0;
                count_0--;
            }
            else if(count_1>0)
            {
                arr[i] = 1;
                count_1--;
            }
            else 
            {
                arr[i] = 2;
                count_2--;
            }
        }
    }
};