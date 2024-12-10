#include<bits/stdc++.h>
using namespace std;
int n,m,t;
long long mod=1e9+9999;
namespace sub1{
    int a[21][21],res;
    int b[21][21];
    void solve() {
        memset(b,-1,sizeof(b));
        for (int i=1;i<=t;i++) {
            int u,v,x;
            cin>>u>>v>>x;
            u--,v--;
            b[u][v]=x;
        }
        for (int mask=0;mask<(1<<(n*m));mask++) {
            bool flag=true;
            for (int i=0;i<n;i++) {
                for (int j=0;j<m;j++) {
                    a[i][j]=((mask>>(i*m+j))&1);
                    if (b[i][j]!=-1&&a[i][j]!=b[i][j]) {
                        flag=false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (!flag) continue;
            for (int i=1;i<n;i++) {
                for (int j=1;j<m;j++) {
                    int cur=a[i][j]+a[i-1][j]+a[i][j-1]+a[i-1][j-1];
                    if (cur%2) {
                        flag=false;
                        break;
                    }
                }
                if (!flag) break;
            }
            res+=flag;
        }
        cout<<res;
    }
}
long long power(long long x,long long y) {
	long long res=1;
	while (y>0) {
		if (y&1) res=(res*x)%mod;
		y>>=1;
		x=(x*x)%mod;
	}
	return res;
}
namespace sub2{
    void solve() {
        cout<<power(2,n+m-1);
    }
}
namespace sub3{
    void solve() {
        cout<<power(2,n+m-2);
    }
}
namespace sub5{
    const int N=1e5,M=8;
    long long dp[N+5][(1<<M)+5];
    bool b[N+5][M+5];
    bool check(int i,int mask) {
        for (int j=0;j<m;j++) {
            int cur=(mask>>j&1);
            if (b[i][j]!=-1&&b[i][j]!=cur) return false;
        }
        return true;
    }
    void add(long long &x,long long y) {
        x+=y;
        if (x>=mod) x-=mod;
    }
    int cur[M+5],ans[M+5];
    int g(int seed,int mask) {
        for (int i=0;i<m;i++) cur[i]=(mask>>i&1);
        ans[0]=seed;
        for (int i=1;i<m;i++) {
            int t=cur[i]+cur[i-1]+ans[i-1];
            if (t%2==0) ans[i]=0;
            else ans[i]=1;
        }
        int m=0;
        for (int i=0;i<m;i++) m|=(1<<i);
        return m;
    }
    void solve() {
        memset(b,-1,sizeof(b));
        for (int i=1;i<=t;i++) {
            int u,v,x;
            cin>>u>>v>>x;
            u--,v--;
            b[u][v]=x;
        }
        for (int mask=0;mask<(1<<m);mask++){
            if (check(0,mask)) dp[0][mask]=1;
        }
        for (int i=0;i<n-1;i++) {
            for (int mask=0;mask<(1<<m);mask++) {
                if (!dp[i][mask]) continue;
                int m0=g(0,mask),m1=g(1,mask);
                if (check(i+1,m0)) add(dp[i+1][m0],dp[i][mask]);
                if (check(i+1,m1)) add(dp[i+1][m1],dp[i][mask]);
            }
        }
        long long res=0;
        for (int mask=0;mask<(1<<m);mask++) add(res,dp[n-1][mask]);
        cout<<res;
    }
}
int main() {
    freopen("SQUARE.INP","r",stdin);
	freopen("SQUARE.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>t;
    if (n*m<=20) sub1::solve();
    else if (t==0) sub2::solve();
    else if (t==1) sub3::solve();
    else sub5::solve();
}
