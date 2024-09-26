#include <bits/stdc++.h>
using namespace std;
#define l1 long long int 

void solve() 
{
    map<int, int>mp;
    
    int n;
    cin >> n;
    
    int arr[n-1][2];
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<2; j++)
        {
            cin >> arr[i][j];
            mp[arr[i][j]]++;
        }
    }
    
    int ans = 0;
    for(auto i : mp)
    {
        if(i.second>=2)
        {
            ans += 2;
        }
        else 
        {
            ans += 3;
        }
    }
    
    cout << ans << endl;
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

