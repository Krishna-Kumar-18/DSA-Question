#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define l1 long long int
void debug(int x)
{
    cerr << x;
}
void debug(long x) { cerr << x; }
void debug(long long x) { cerr << x; }
void debug(unsigned x) { cerr << x; }
void debug(unsigned long x) { cerr << x; }
void debug(unsigned long long x) { cerr << x; }
void debug(float x) { cerr << x; }
void debug(double x) { cerr << x; }
void debug(long double x) { cerr << x; }
void debug(char x) { cerr << '\'' << x << '\''; }
void debug(const char *x) { cerr << '\"' << x << '\"'; }
void debug(const string &x) { cerr << '\"' << x << '\"'; }
void debug(bool x) { cerr << (x ? "true" : "false"); }
 
template <typename T, typename V>
void debug(const pair<T, V> &x);
template <typename T>
void debug(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? ", " : ""), debug(i);
    cerr << "}";
}
template <typename T, typename V>
void debug(const pair<T, V> &x)
{
    cerr << '{';
    debug(x.first);
    cerr << ", ";
    debug(x.second);
    cerr << '}';
}
template <typename ST>
void debug(stack<ST> st)
{
    cerr << " ";
    while (!st.empty())
    {
        cerr << st.top() << " ";
        st.pop();
    }
}
template <typename Q>
void debug(queue<Q> que)
{
    while (!que.empty())
    {
        cerr << que.front() << " ";
        que.pop();
    }
}
template <typename DQ>
void debug(deque<DQ> dque)
{
    while (!dque.empty())
    {
        cerr << dque.front() << " ";
        dque.pop_front();
    }
}
void dbg() { cerr << "]\n"; }
template <typename T, typename... V>
void dbg(T t, V... v)
{
    debug(t);
    if (sizeof...(v))
        cerr << ", ";
    dbg(v...);
}
 
#ifdef DEBUG
#define dbg(x...)                                                             \
    cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; \
    dbg(x);                                                                   \
    cerr << "\e[39m" << endl;
#else
#define dbg(x...) 18
#endif
 
const int N = int(2e5) + 5;
l1 dp[N];

static bool comp(pair<l1,l1>a, pair<l1,l1>b)
{
    return a.first > b.first;
}

static bool second_comp(pair<l1,l1>a, pair<l1,l1>b)
{
    return a.first > b.first;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int>v(n);

    priority_queue<int>pq;

    for(int i=0; i<n; i++)
    {
        cin >> v[i];
        pq.push(v[i]);
    }

    while(k--)
    {
        int ele = pq.top();
        pq.pop();

        ele = ele/2;
        pq.push(ele);    
    }


    long long int sum = 0;
    while(!pq.empty())
    {
        int ele = pq.top();
        pq.pop();

        sum += ele;
    }
    
    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    l1 t=1;
    // cin >> t;
 
    while(t--)
    { 
        solve();
    }
 
    return 0;
}