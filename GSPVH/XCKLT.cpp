#include<bits/stdc++.h>
using namespace std;
const int N=501;
int n,m,p;
string a,b,c;
short dp[N][N][N],inf=10000,res=inf;
short trace[N][N][N],trc;
string ans;
int main() {
	freopen("xcklt.inp","r",stdin);
    freopen("xcklt.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>a>>b>>c;
    n=a.size(),m=b.size(),p=c.size();
    a=' '+a,b=' '+b,c=' '+c;
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			for (int k=0;k<N;k++)
				dp[i][j][k]=inf;
	dp[0][0][0]=0;
	for (int i=0;i<=n;i++) {
		for (int j=0;j<=m;j++) {
			for (int k=0;k<=p;k++) {
				if (i<n) {
					int tb=j,tc=k;
					if (tb<m&&a[i+1]==b[tb+1]) tb++;
					if (tc<p&&a[i+1]==c[tc+1]) tc++;
					if (tc<p) {
						if (dp[i+1][tb][tc]>dp[i][j][k]+1) {
							dp[i+1][tb][tc]=dp[i][j][k]+1;
							trc=2;
							if (tb!=j) trc|=4;
							if (tc!=k) trc|=8;
							trace[i+1][tb][tc]=trc;
						}
					}
				}
				if (j<m) {
					int ta=i,tc=k;
					if (ta<n&&b[j+1]==a[ta+1]) ta++;
					if (tc<p&&b[j+1]==c[tc+1]) tc++;
					if (tc<p) {
						if (dp[ta][j+1][tc]>dp[i][j][k]+1) {
							dp[ta][j+1][tc]=dp[i][j][k]+1;
							trc=5;
							if (ta!=i) trc|=2;
							if (tc!=k) trc|=8;
							trace[ta][j+1][tc]=trc;
							//cout<<i<<' '<<j<<' '<<k<<' '<<ta<<' '<<j+1<<' '<<tc<<' '<<b[j+1]<<'\n';
						}
					}
				}
			}
		}
	}
	short i=n,j=m,k;
	for (int t=0;t<p;t++) {
		if (res>dp[n][m][t]) {
			res=dp[n][m][t];
			k=t;
		}
	}
	if (res==inf) {
		cout<<"TRETRAU";
		return 0;
	}
	cout<<res<<'\n';
	while (i>0||j>0||k>0) {
        short temp=trace[i][j][k];
		if (!(temp&1)) ans+=a[i];
		else ans+=b[j];
		i-=(temp>>1&1),j-=(temp>>2&1),k-=(temp>>3&1);
	}
	reverse(ans.begin(),ans.end());
	cout<<ans;
}
