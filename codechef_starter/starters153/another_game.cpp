#include <bits/stdc++.h>
using namespace std;
#define l1 long long int 

void solve() 
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    
    int n;
    cin >> n;
    
    int ele = 0;
    
    int arr[n];
    for(int i=0;  i<n; i++)
    {
        cin >> arr[i];
        mini = min(arr[i], mini);
        maxi = max(arr[i], maxi);
        if(arr[i]!=i+1)
        {
            ele = max(ele, arr[i]);
        }
    }
    
    int count = 0;
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]<arr[i+1])
        {
            count++;
        }
    }
    
    if(count==n-1)
    {
        cout << 0 << endl;
        return;
    }
    
    cout << ele + mini << endl;
}

int main()
{
	l1 t;
	cin >> t;
	
	while(t--)
	{
	    solve();
	}
	
	return 0;
}

