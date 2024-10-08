class Solution {
  public:
    int pairsum(vector<int> &arr) 
    {
        int first_max, second_max;
        
        if(arr[0]>=arr[1])
        {
            first_max = arr[0];
            second_max = arr[1];
        }
        else 
        {
            first_max = arr[1];
            second_max = arr[0];
        }
        
        for(int i=2; i<arr.size(); i++)
        {
            if(arr[i]>=first_max)
            {
                second_max = first_max;
                first_max = arr[i];
            }
            else if(arr[i]>=second_max)
            {
                second_max = arr[i];
            }
        }
        
        int ans = first_max + second_max;
        
        return ans;
    }
};