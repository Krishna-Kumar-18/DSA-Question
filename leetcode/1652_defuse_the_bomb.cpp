class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        vector<int>ans;
        
        int n = code.size();

        for(int i=0; i<code.size(); i++)
        {
            int sum = 0;
            if(k>0)
            {
                int j=i+1;
                int loop = k;
                while(loop>0)
                {
                    if(j==n)
                    {
                        j=0;
                    }
                    sum += code[j];
                    j++;
                    loop--;
                }

                ans.push_back(sum);
            }
            else if(k==0)
            {
                ans.push_back(0);
            }
            else
            {
                int j=i-1;
                int loop = abs(k);
                while(loop>0)
                {
                    if(j<0)
                    {
                        j=n-1;
                    }
                    sum += code[j];
                    j--;
                    loop--;
                }

                ans.push_back(sum);
            }
        }

        return ans;
    }
};