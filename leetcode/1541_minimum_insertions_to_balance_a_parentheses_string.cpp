class Solution {
public:
    int minInsertions(string s) 
    {
        int n = s.size();

        stack<char>st;

        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else if(s[i]==')' && i+1<n && s[i+1]==')' && !st.empty() && st.top()=='(')
            {
                st.pop();
                i++;
            }
            else if(s[i]==')' && !st.empty() && st.top()=='(')
            {
                ans++;
                st.pop();
            }
            else if(s[i]==')' && i+1<n && s[i+1]==')')
            {
                ans++;
                i++;
            }
            else if(s[i]==')')
            {
                ans += 2;
            }
        }

        ans += (st.size()) * 2;
        
        return ans;
    }
};