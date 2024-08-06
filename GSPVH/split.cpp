#include<bits/stdc++.h>
using namespace std;
const int N=7e3;
int n;
string s;
int mod=998244353;
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
void sub(int &x,int y) {
	x-=y;
	if(x<0) x+=mod;
}
int dp[N+5][N+5],sum[N+5][N+5];
int f[N+5][N+5];
void prep() {
	for (int i=n;i>=1;i--) {
		for (int j=n;j>=1;j--) {
			if (s[i]!=s[j]) f[i][j]=0;
			else f[i][j]=f[i+1][j+1]+1;
		}
	}
}
bool comp(int l,int r,int u,int v) {
	int t=f[l][u];
	if (t>=r-l+1) return false;
	int x=l+t,y=u+t;
	return s[x]<s[y];
}
int main() {
	freopen("split.inp","r",stdin);
	freopen("split.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    n=s.size();
    s=' '+s;
    prep();
    sum[0][0]=1;
    for (int r=1;r<=n;r++) {
    	for (int l=1;l<=r;l++) {
    		if (s[l]!='0') {
    			dp[l][r]=sum[l-1][l-1];
    			int len=r-l+1;
    			int v=l-1,u=v-len+1;
    			if (u>0) {
    				sub(dp[l][r],sum[u][l-1]);
    				if (comp(u,v,l,r)) add(dp[l][r],dp[u][v]);
    			}
    		} 
    		sum[l][r]=sum[l-1][r];
    		add(sum[l][r],dp[l][r]);
    	}
    }
    int res=0;
    for (int i=1;i<=n;i++) add(res,dp[i][n]);
    cout<<res;
}