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

int max_cost = -1;

void cost(vector<vector<int>>&grid, int st_x, int st_y, int dis_x, int dis_y, int c, int m, int n, vector<vector<bool>>&vis)
{
        if(st_x==dis_x && st_y==dis_y)
        {
            max_cost = max(max_cost, c);
            return;
        }

        if(st_x<0 || st_x>=m || st_y<0 || st_y>=n || grid[st_x][st_y]==0 || vis[st_x][st_y])
        {
            return;
        }

        vis[st_x][st_y] = true;

        cost(grid, st_x+1, st_y, dis_x, dis_y, c+1, m, n, vis);
        cost(grid, st_x-1, st_y, dis_x, dis_y, c+1, m, n, vis);
        cost(grid, st_x, st_y+1, dis_x, dis_y, c+1, m, n, vis);
        cost(grid, st_x, st_y-1, dis_x, dis_y, c+1, m, n, vis);

        vis[st_x][st_y] = false;
}

void solve()
{
    int m, n;
    cin >> m >> n;

    int h;
    cin >> h;

    vector<vector<int>>grid(m, vector<int>(n, 1));

    vector<vector<bool>>vis(m, vector<bool>(n, false));

    for(int i=0; i<h; i++)
    {
        int a, b;
        cin >> a >> b;
        grid[a][b] = 0;
    }

    int st_x, st_y;
    cin >> st_x >> st_y;

    int dis_x, dis_y;
    cin >> dis_x >> dis_y;

    if(grid[st_x][st_y]==0 || grid[dis_x][dis_y]==0)
    {
        cout << max_cost;
        return;
    }
    
    cost(grid, st_x, st_y, dis_x, dis_y, 0, m, n, vis);

    cout << max_cost;
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