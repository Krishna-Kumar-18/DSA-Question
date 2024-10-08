#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) 
    {
        if(arr.size()<2)
        {
            return arr.size();
        }
        
        int cb = 1;
        int bc = 1;
        
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i] > arr[i-1])
            {
                bc = 1 + cb;
            }
            
            if(arr[i] < arr[i-1])
            {
                cb = 1 + bc;
            }
        }
        
        return max(bc, cb);
    }
};

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}