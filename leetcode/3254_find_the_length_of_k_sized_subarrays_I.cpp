class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        vector<int>ans;

        for(int i=0; i<=nums.size()-k; i++)
        {
            bool flag = true;
            int ele = -1;

            if(k==1)
            {
                ans.push_back(nums[i]);
                flag = false;
            }
            else 
            {
                for(int j=i; j<i+k-1; j++)
                {
                    if(nums[j]>=nums[j+1] || ((nums[j+1]-nums[j])>1))
                    {
                        ans.push_back(-1);
                        flag = false;
                        break;
                    }
                    ele = nums[j+1];
                }
            }

            if(flag)
            {
                ans.push_back(ele);
            }
        }

        return ans;        

    }
};