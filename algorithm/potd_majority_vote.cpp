                                                            // Moore Algorithm


class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) 
    {
        vector<int>ans;
        
        int ele_1=nums[0], ele_2=nums[0];
        int count_1=0, count_2=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(ele_1==nums[i])
            {
                count_1++;
            }
            else if(ele_2==nums[i])
            {
                count_2++;
            }
            else if(count_1==0)
            {
                ele_1 = nums[i];
                count_1 = 1;
            }
            else if(count_2==0)
            {
                ele_2 = nums[i];
                count_2 = 1;
            }
            else 
            {
                count_1--;
                count_2--;
            }
        }
        
        int freq_1=0, freq_2=0;
        for(int i=0; i<nums.size(); i++)
        {ASSETS[assetIndex].startASSETS[assetIndex].start
            if(ele_1==nums[i])
            {
                freq_1++;
            }
            else if(ele_2==nums[i])
            {
                freq_2++;
            }
        }
        
        int vote = nums.size()/3;
        
        if(freq_1>vote)
        {
            ans.push_back(ele_1);
        }
        
        if(freq_2>vote)
        {
            ans.push_back(ele_2);
        }
        
        sort(ans.begin(), ans.end());
        
        if(ans.size()==0)
        {
            ans.push_back(-1);
        }
        
        return ans;
    }
};
