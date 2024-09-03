class Solution {
public:
    int getLucky(string s, int k) 
    {
        string ans = ""; 
        for(int i=0; i<s.length(); i++)
        {
            int num = s[i]-'a';
            num++;
            string temp = to_string(num);
            ans += temp;
        }
        
        while(k--)
        {
            int sum = 0;
            for(int i=0; i<ans.length(); i++)
            {
                int num = ans[i]-'0';
                sum +=num;
            }
            ans = to_string(sum);
        }

        return stoi(ans);
    }
};