class Solution {
  public:
    int missingNumber(vector<int> &arr) 
    {
        int n = arr.size();
        
        vector<int>pos;
        
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]<=0)
            {
                continue;
            }
            
            pos.push_back(arr[i]);
        }
        
        sort(pos.begin(), pos.end());
        
        int num = 1;
        for(int i=0; i<pos.size(); i++)
        {
            if(pos[i]==num)
            {
                num++;
                continue;
            }
            
            if(i>0 && pos[i]==pos[i-1])
            {
                continue;
            }
            
            return num;
        }
        
        return num;
    }
};