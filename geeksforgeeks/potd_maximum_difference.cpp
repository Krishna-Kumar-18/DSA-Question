class Solution {
  public:
    int findMaxDiff(vector<int> &arr) 
    {
        int n = arr.size();
        
        stack<int>st;
        vector<int>v_l(n);
        vector<int>v_r(n);
        
        for(int i=0; i<n; i++)
        {
            if(st.empty())
            {
                v_l[i] = 0;
                st.push(arr[i]);
            }
            else if(arr[i]>st.top())
            {
                v_l[i] = st.top();
                st.push(arr[i]);
            }
            else 
            {
                st.pop();
                bool flag = true;
                while(!st.empty())
                {
                    if(arr[i]>st.top())
                    {
                        v_l[i] = st.top();
                        st.push(arr[i]);
                        flag = false;
                        break;
                    }
                    else
                    {
                        st.pop();
                    }
                }
                
                if(flag)
                {
                    v_l[i] = 0;
                    st.push(arr[i]);
                }
            }
        }
        
        while(!st.empty())
        {
            st.pop();
        }
        
        for(int i=arr.size()-1; i>=0; i--)
        {
            if(st.empty())
            {
                v_r[i] = 0;
                st.push(arr[i]);
            }
            else if(arr[i]>st.top())
            {
                v_r[i] = st.top();
                st.push(arr[i]);
            }
            else 
            {
                st.pop();
                bool flag = true;
                while(!st.empty())
                {
                    if(arr[i]>st.top())
                    {
                        v_r[i] = st.top();
                        st.push(arr[i]);
                        flag = false;
                        break;
                    }
                    else
                    {
                        st.pop();
                    }
                }
                
                if(flag)
                {
                    v_r[i] = 0;
                    st.push(arr[i]);
                }
            }
        }
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++)
        {
            ans = max(ans, abs(v_l[i] - v_r[i]));
        }
        
        return ans;
    }
};