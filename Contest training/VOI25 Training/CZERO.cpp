#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
const int N=31;
int dp[N+1][2][N+1][2];
int f(int i, bool les, int cnt, bool nz) {
	if (cnt>k) return 0;
    if (i==-1) return cnt==k&&nz==1;
    int ans=0;
    if (dp[i][les][cnt][nz]!=-1) return dp[i][les][cnt][nz];
    if (nz==1) {
        ans+=f(i-1,les||(n>>i&1),cnt+1,1);
    }
    else
        ans+=f(i-1,les||(n>>i&1),cnt,0);
    if (les||(n>>i&1)) ans+=f(i-1,les,cnt,1);
    dp[i][les][cnt][nz]=ans;
    return ans;
}
int main() {
    freopen("CZERO.INP","r",stdin);
    freopen("CZERO.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin>>n) {
    	cin>>k;
    	if (k>N) {
    		cout<<0<<'\n';
    		continue;
    	}
        memset(dp,-1,sizeof(dp));
        cout<<f(31,0,0,0)<<'\n';
    }
}
