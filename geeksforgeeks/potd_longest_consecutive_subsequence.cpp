class Solution {
  public:
    int longestConsecutive(vector<int>& arr) 
    {
        if(arr.size() == 1)
        {
            return 1;
        }
        
        set<int>s;
        vector<int>temp;
        
        for(auto i : arr)
        {
            s.insert(i);
        }
        
        for(auto i : s)
        {
            temp.push_back(i);
        }
        
        sort(temp.begin(), temp.end());
        
        int maxi = 1;
        int count = 0;
        bool flag = true;
        
        int ele = temp[0];
        for(int i=0; i<temp.size(); i++)
        {
            if(temp[i] == ele+1)
            {
                if(flag)
                {
                    count+=2;
                    flag = false;
                }
                else
                {
                    count++;
                }
            }
            else 
            {
                maxi = max(count, maxi);
                count = 0;
                flag = true;
            }
            ele = temp[i];
        }
        
        return max(maxi, count);
    }
};