#include <bits/stdc++.h>
using namespace std;
#define l1 long long int 

void solve() 
{
    l1 x, y;
    cin >> x >> y;
    
    l1 add = x + 1000;
    l1 dou = x*2;
    
    if(add>=dou)
    {
        l1 ans = add;
        for(l1 i=2; i<=y; i++)
        {
            ans = ans * 2;
        }
        cout << ans << endl;
        return;
    }
    else 
    {
        l1 ans = x;
        for(l1 i=1; i<=y; i++)
        {
            ans = ans * 2;
        }
        cout << ans << endl;
        return;
    }
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
