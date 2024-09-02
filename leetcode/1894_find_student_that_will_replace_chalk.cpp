class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        long long int total_chalk = 0;
        for(int i=0; i<chalk.size(); i++)
        {
            total_chalk += chalk[i];
        }

        long long int remaining_chalk = k%total_chalk;

        for(int i=0; i<chalk.size(); i++)
        {
            if(remaining_chalk < chalk[i])
            {
                return i;
            }
            remaining_chalk -= chalk[i];
        }

        return 1;
    }
};