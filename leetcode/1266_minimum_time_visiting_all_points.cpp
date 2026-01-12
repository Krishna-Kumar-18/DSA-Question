class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        int m = points[0].size();

        int total_time = 0;

        for(int i=0; i<n-1; i++)
        {   
            int x = abs(points[i][0] - points[i+1][0]);
            int y = abs(points[i][1] - points[i+1][1]);
            
            total_time += max(x, y);
        }
        
        return total_time;
    }
};