class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) 
    {
        int maxi = 0;
        for(int i=0; i<reservedSeats.size(); i++)
        {   
            int first = reservedSeats[i][0];
            maxi = max(maxi, first);
        }

        vector<vector<int>>temp(maxi, vector<int>(10, 0));

        for(int i=0; i<reservedSeats.size(); i++)
        {
            int first = reservedSeats[i][0];
            int second = reservedSeats[i][1];

            temp[first-1][second-1] = 1;
        }

        int count = 0;
        for(int i=0; i<maxi; i++)
        {
            int ind=2;
            int last = 5;
            while(last<=9)
            {
                for(int j=ind; j<=last; j++)
                {
                    if(temp[i][j-1]==1)
                    {
                        ind = 0;
                        break;
                    }
                }

                if(ind == 0)
                {
                    ind = last-1;
                    last = ind+3;
                }
                else
                {
                    count++;
                    ind = last+1;
                    last = ind+3;
                }
            }
        }

        int rem = (n-maxi) *2 ;

        return count + rem;
    }
};