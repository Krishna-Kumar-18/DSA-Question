#include <bits/stdc++.h>
using namespace std;
#define l1 long long int 

void solve() 
{
    int a, b, c;
    cin >> a >> b >> c;
    
    
    int diff_1 = b-a;
    int diff_2 = c-b;
    
    if(diff_1 == diff_2)
    {
        cout << 0 << endl;
        return;
    }
    
    if(diff_2<0)
    {
        if(b+diff_1>100)
        {
            cout << 2 << endl;
            return;
        }
    }
    
    cout << 1 << endl;
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

