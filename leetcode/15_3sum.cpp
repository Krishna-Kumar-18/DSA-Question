class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int>v;
        set<vector<int>>s;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-2; i++)
        {
            int low = i+1;
            int high = nums.size()-1;

            while(low<high)
            {
                int sum = nums[i] + nums[low] + nums[high];

                if(sum == 0)
                {
                    v.push_back(nums[i]);
                    v.push_back(nums[low]);
                    v.push_back(nums[high]);

                    s.insert(v);
                    v.clear();

                    low++;
                    high--;
                }
                else if(sum < 0)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }

        for(auto i : s)
        {
            ans.push_back(i);
        }

        return ans;
    }
};