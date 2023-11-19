#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define for1(i,j,k) for(int i=j;i<=k;i++)
#define for2(i,j,k) for(int i=j;i>=k;i--)
#define for3(i,j,k,l) for(int i=j;i<=k;i+=l)
#define bit(n,i) ((n>>i)&1)
#define all(x) x.begin(),x.end()
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,sse,sse2,sse3,ssse3,sse4,popcnt")
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef double ld;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;
const ll maxn=1e2+10;
const ll N=2e5+2;
const ll offset=1e18;
//const ll block_sz=317;
const ll inf=1e9;
const ll mod=998244353;

int n,l,r,k,dp[maxn][maxn*maxn],prv[maxn][maxn*maxn],a[maxn];

void sol()
{
    cin>>n>>l>>r>>k;
    for (int i = 1;i <= n;i++) cin>>a[i];
    for (int pos = r;pos >= l;pos--){
        for (int cur = r;cur <= n;cur++){
            for (int rm = 0;rm <= k;rm++){
                int &res = dp[cur][rm];
                if (cur == r) res = prv[cur][rm] + a[pos];
                else{
                    int d = abs(cur - pos);
                    res = min(dp[cur - 1][rm],prv[cur][rm] + a[pos]);
                    if (rm >= d) res = min(res,prv[cur - 1][rm - d] + a[cur]);
                }
            }
        }
        for (int cur = l;cur > 0;cur--){
            for (int rm = 0;rm <= k;rm++){
                int &res = dp[cur][rm];
                if (cur == l) res = dp[n][rm];
                else{
                    int d = abs(cur - pos);
                    res = min(dp[cur + 1][rm],prv[cur][rm] + a[pos]);
                    if (rm >= d) res = min(res,prv[cur + 1][rm - d] + a[cur]);
                }
            }
        }
        for (int i = 1;i <= n;i++)
            for (int j = 0;j <= k;j++) prv[i][j] = dp[i][j];
    }
    cout<<dp[1][k];
}

int32_t main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    freopen("debt.inp","r",stdin);
    freopen("debt.out","w",stdout);
    int t=1;
    //cin >> t;
    while (t--)
    {
        sol();
    }
}
