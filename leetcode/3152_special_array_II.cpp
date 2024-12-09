class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) 
    {
        vector<bool>ans;

        vector<int>temp;
        temp.push_back(0);

        int count = 0;
        for(int j=1; j<nums.size(); j++)
        {
            bool flag = true;

            if(nums[j]%2==0 && nums[j-1]%2==0)
            {
                count++;
                flag = false;
                temp.push_back(count);
            }

            if(nums[j]%2!=0 && nums[j-1]%2!=0)
            {
                count++;
                flag = false;
                temp.push_back(count);
            }

            if(flag)
            {
                temp.push_back(count);
            }
        }

        for(int i=0; i<queries.size(); i++)
        {
            int end = queries[i][1];
            int start = queries[i][0];

            if(temp[end]-temp[start] == 0)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }    

        return ans;
    }
};