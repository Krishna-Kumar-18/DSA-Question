class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) 
    {
        vector<vector<int>>mergeArray;

        vector<int>temp;

        int n1 = nums1.size();
        int n2 = nums2.size();

        int i=0;
        int j=0;

        while(i<n1 || j<n2)
        {
            temp.clear();
            if(i<n1 && j<n2)
            {
                if(nums1[i][0] == nums2[j][0])
                {
                    temp.push_back(nums1[i][0]);
                    temp.push_back(nums1[i][1] + nums2[j][1]);
                    mergeArray.push_back(temp);
                    i++;
                    j++;

                }
                else if(nums1[i][0] < nums2[j][0])
                {
                    temp.push_back(nums1[i][0]);
                    temp.push_back(nums1[i][1]);
                    mergeArray.push_back(temp);
                    i++;
                }
                else
                {
                    temp.push_back(nums2[j][0]);
                    temp.push_back(nums2[j][1]);
                    mergeArray.push_back(temp);
                    j++;
                }
            }
            else if(i<n1)
            {
                temp.push_back(nums1[i][0]);
                temp.push_back(nums1[i][1]);
                mergeArray.push_back(temp);
                i++;
            }
            else if(j<n2)
            {
                temp.push_back(nums2[j][0]);
                temp.push_back(nums2[j][1]);
                mergeArray.push_back(temp);
                j++;
            }
        }

        return mergeArray;
    }
};
