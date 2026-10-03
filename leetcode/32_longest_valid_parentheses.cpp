class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int n = s.length();

        vector<int>pair(n, -1);
        stack<int>st;

        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(st.empty() && s[i]==')')
            {
                continue;
            }
            else 
            {
                int open = st.top();
                st.pop();
                pair[open] = i;
                pair[i] = open;
            }
        }

        int max_len = 0;
        int len = 0;
        for(auto i : pair)  
        {
            if(i==-1)
            {
                len = 0;
            }
            else
            {
                len++;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};