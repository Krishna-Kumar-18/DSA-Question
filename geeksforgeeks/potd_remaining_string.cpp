#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    string printString(string s, char ch, int count) 
    {
        int ind = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]==ch)
            {
                count--;
            }
            
            if(count==0)
            {
                ind=i;
                break;
            }
        }
        
        if(count>0)
        {
            return "";
        }
        
        string ans="";
        if(count == 0)
        {
            for(int i=ind+1; i<s.length(); i++)
            {
                ans = ans + s[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}