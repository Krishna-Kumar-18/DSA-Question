class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) 
    {
        int mini_1, mini_2, mini_ind_1, mini_ind_2, maxi_1, maxi_2, maxi_ind_1, maxi_ind_2;

        if(arrays[0][0] <= arrays[1][0])
        {
            mini_1 = arrays[0][0];
            mini_ind_1 = 0;

            mini_2 = arrays[1][0];
            mini_ind_2 = 1;
        }
        else
        {
            mini_1 = arrays[1][0];
            mini_ind_1 = 1;

            mini_2 = arrays[0][0];
            mini_ind_2 = 0;
        }

        if(arrays[0][arrays[0].size()-1] >= arrays[1][arrays[1].size()-1])
        {
            maxi_1 = arrays[0][arrays[0].size()-1];
            maxi_ind_1 = 0;

            maxi_2 = arrays[1][arrays[1].size()-1];
            maxi_ind_2 = 1;
        }
        else 
        {
            maxi_1 = arrays[1][arrays[1].size()-1];
            maxi_ind_1 = 1;

            maxi_2 = arrays[0][arrays[0].size()-1];
            maxi_ind_2 = 0;
        }

        for(int i=2; i<arrays.size(); i++)
        {
            if(arrays[i][0] < mini_2)
            {
                if(arrays[i][0] < mini_1)
                {
                    mini_2 = mini_1;
                    mini_ind_2 = mini_ind_1;

                    mini_1 = arrays[i][0];
                    mini_ind_1 = i;
                }
                else
                {
                    mini_2 = arrays[i][0];
                    mini_ind_2 = i;
                }
            }

            if(arrays[i][arrays[i].size()-1] > maxi_2)
            {
                if(arrays[i][arrays[i].size()-1] > maxi_1)
                {
                    maxi_2 = maxi_1;
                    maxi_ind_2 = maxi_ind_1;

                    maxi_1 = arrays[i][arrays[i].size()-1];
                    maxi_ind_1 = i;
                }
                else
                {
                    maxi_2 = arrays[i][arrays[i].size()-1];
                    maxi_ind_2 = i;
                }
            } 
        }

        if(mini_ind_1 != maxi_ind_1)
        {
            return maxi_1-mini_1;
        }

        if(maxi_2-mini_1 >= maxi_1-mini_2)
        {
            return maxi_2-mini_1;
        }
        return maxi_1-mini_2;
    }
};