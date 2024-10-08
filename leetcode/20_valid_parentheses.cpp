class Solution {
public:
    bool isValid(string s) 
    {
        stack<char>st;

        if(s.length()==1)
        {
            return false;
        }

        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else 
            {
                if(st.empty())
                {
                    if(s[i]==')' || s[i]=='}' || s[i]==']')
                    {
                        return false;
                    }
                }
                if(st.top()=='(' && s[i]==')')
                {
                    st.pop();
                }
                else if(st.top()=='{' && s[i]=='}')
                {
                    st.pop();
                }
                else if(st.top()=='[' && s[i]==']')
                {
                    st.pop();
                }
                else 
                {
                    return false;
                }
            }
        }
        
        if(!st.empty())
        {
            return false;
        }
        return true;
    }
};