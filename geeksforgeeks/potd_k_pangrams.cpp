#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    bool kPangram(string str, int k) 
    {
        vector<int>v(26, 0);
        
        int size=0;
        for(int i=0; i<str.size(); i++)
        {
            int ind = str[i]-'a';
            if(ind == -65)
            {
                continue;
                
            }
            else 
            {
                v[ind] = 1;
                size++;
            }
        }
        
        if(size < 26)
        {
            return false;
        }
        
        int count = 0;
        for(auto i : v)
        {
            if(i==1)
            {
                count++;
            }
        }
        
        int diff = 26-count;
        
        if(diff<=k)
        {
            return true;
        }
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}