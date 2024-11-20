class Solution {
public:
    int takeCharacters(string s, int k) 
    {
        int count_a = 0;
        int count_b = 0;
        int count_c = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='a')
            {
                count_a++;
            }

            if(s[i]=='b')
            {
                count_b++;
            }

            if(s[i]=='c')
            {
                count_c++;
            }
        }

        if(count_a<k || count_b<k || count_c<k)
        {
            return -1;
        }

        count_a = count_a-k;
        count_b = count_b-k;
        count_c = count_c-k;

        int cnt_a = 0;
        int cnt_b = 0;
        int cnt_c = 0;

        int max_length = INT_MIN;
        int j=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='a')
            {
                cnt_a++;
            }

            if(s[i]=='b')
            {
                cnt_b++;
            }

            if(s[i]=='c')
            {
                cnt_c++;
            }

            while(cnt_a>count_a)
            {
                if(s[j] == 'a')
                {
                    cnt_a--;
                }

                if(s[j]=='b')
                {
                    cnt_b--;
                }

                if(s[j]=='c')
                {
                    cnt_c--;
                }
                j++;
            }

            while(cnt_b>count_b)
            {
                if(s[j] == 'a')
                {
                    cnt_a--;
                }

                if(s[j]=='b')
                {
                    cnt_b--;
                }

                if(s[j]=='c')
                {
                    cnt_c--;
                }
                j++;
            }

            while(cnt_c>count_c)
            {
                if(s[j] == 'a')
                {
                    cnt_a--;
                }

                if(s[j]=='b')
                {
                    cnt_b--;
                }

                if(s[j]=='c')
                {
                    cnt_c--;
                }
                j++;
            }

            max_length = max(max_length, i-j+1);
        }

        return s.size()-max_length;
    }
};