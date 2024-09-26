#include <bits/stdc++.h>
using namespace std;
#define l1 long long int 

void solve() 
{
    int a, b, c;
    cin >> a >> b >> c;
    
    if(b+c<a)
    {
        cout << "NO" << endl;
    }
    else if(a+c<b)
    {
        cout << "NO" << endl;
    }
    else if(a+b<c)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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
