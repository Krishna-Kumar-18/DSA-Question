class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int low = 0;
        int high = height.size()-1;

        int area = INT_MIN;

        while(low<high)
        {
            int len = min(height[low], height[high]);

            int wid = high-low;

            area = max(area, len*wid);

            if(height[low] <= height[high])
            {
                low++;
            }
            else
            {
                high--;
            }
        }

        return area;
    }
};