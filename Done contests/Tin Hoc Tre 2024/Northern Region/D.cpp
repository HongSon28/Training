#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define int short
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,m, a[SZ][SZ], b[SZ][SZ], x[SZ], y[SZ];

namespace sub1
{
    void solve()
    {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if(a[i][j] == -1) cnt++;
            }
        }
        for(int i = 1; i <= n; i++) cin >> x[i];
        for(int i = 1; i <= m; i++)
        {
            cin >> y[i];
        }
        for(int mask = 0; mask < (1 << cnt); mask++)
        {
            int cur = 0;
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= m; ++j)
                {
                    b[i][j] = a[i][j];
                    if(b[i][j] == -1)
                    {
                        b[i][j] = (mask >> cur & 1);
                        cur++;
                    }
                }
            }
            bool check = true;
            for(int i = 1; i <= n; i++)
            {
                int cur = 0;
                for(int j = 1; j <= m; j++)
                {
                    if(b[i][j] == 1) cur++;
                }
                if(cur != x[i]) check = false;
            }
            for(int j = 1; j <= m; j++)
            {
                int cur = 0;
                for(int i = 1; i <= n; i++)
                {
                    if(b[i][j] == 1) cur++;
                }
                if(cur != y[j]) check = false;
            }
            if(check)
            {
                for(int i = 1; i <= n; i++)
                {
                    for(int j = 1; j <= m; j++)
                    {
                        cout << b[i][j] << " ";
                    }
                    cout << '\n';
                }
                return;
            }
        }
    }
}

namespace sub2
{
    void check()
    {
        bool flag = true;
        for(int i = 1; i <= n; i++)
        {
            if(x[i] != 0) flag = false;
        }
        for(int j = 1; j <= m; j++)
        {
            if(y[j] != 0) flag = false;
        }
        if(flag)
        {
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= m; j++)
                {
                    if (a[i][j]!=-1) cout<<a[i][j]<<' ';
                    else cout << b[i][j] << " ";
                }
                cout << '\n';
            }
            exit(0);
        }
    }

    void rec(int i, int j)
    {
        if(a[i][j] == 1) {
            if (!x[i]||!y[j]) return;
            x[i]--;
            y[j]--;
            if (i==n && j==m) check();
            else if (i<n&&j==m) {
                rec(i+1,1);
            } else rec(i,j+1);
            x[i]++;
            y[j]++;
        } else if (a[i][j] == 0) {
            if (i==n && j==m) check();
            else if (i<n&&j==m) {
                rec(i+1,1);
            } else rec(i,j+1);
        } else {
            b[i][j]=0;
            if (i==n && j==m) check();
            else if (i<n&&j==m) {
                rec(i+1,1);
            } else rec(i,j+1);

            if (!x[i]||!y[j]) return;
            b[i][j]=1;
            x[i]--;
            y[j]--;
            if (i==n && j==m) check();
            else if (i<n&&j==m) {
                rec(i+1,1);
            } else rec(i,j+1);
            x[i]++;
            y[j]++;
        }
    }

    void solve()
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        for(int i = 1; i <= m; i++)
        {
            cin >> y[i];
        }
        rec(1, 1);
    }
}

signed main()
{
    init();
    cin >> n >> m;
    sub2::solve();
}

