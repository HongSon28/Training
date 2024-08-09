#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18, MX = 1e15;
const double epsilon = 1e-3;

ll t, x, k;

namespace sub1
{

    void jump(long long &a) {

    }

    ll nx(ll a)
    {
        ll res = 0, cnt = 0;
        for(int i = 0; i <= 51; i++)
        {
            if(a >> i & 1)
            {
                if(a >> (i+1) & 1)
                {
                    cnt++;
                } else
                {
                    //cout << i << " a\n";
                    res += (1LL << (i+1));
                    for(int j = i+1; j <= 51; j++)
                    {
                        if(a >> j & 1) res += (1LL << j);
                    }
                    break;
                }
            }
        }
        res += (1LL << (cnt)) - 1;
        return res;
    }

    void solve()
    {
        while(t--)
        {
            cin >> x >> k;
            while(k>0)
            {
                jump(x);
                if(x > MX)
                {
                    x = -1;
                    break;
                }
                if (k==0) break;
                x = nx(x);
                k--;
                if(x > MX)
                {
                    x = -1;
                    break;
                }
            }
            cout << x << '\n';
        }
    }
}

int main()
{
    init();
    cin >> t;
    sub1::solve();
}

/*
1
1000000000 1
*/
