#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int binarySearch(vector<int> &temp, int key)
    {
        int index=-1, low=0, high=temp.size()-1, mid;
        
        while(low <= high)
        {
            mid = (low+high)/2;
            
            if(temp[mid]==key)
            {
                index = mid;
                high = mid-1;
            }
            else if(temp[mid]>key)
            {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return index;
    }
    
    vector<int> constructLowerArray(vector<int> &arr) 
    {
        vector<int> ans;
        vector<int> temp;
        
        for(auto x : arr)
        {
            temp.push_back(x);
        }
        
        sort(temp.begin(),temp.end());
        
        for(int i=0; i<arr.size(); i++)
        {
            int index = binarySearch(temp, arr[i]);
            ans.push_back(index);
            temp.erase(temp.begin()+index);
        }
        
        return ans;
    }
};

int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}