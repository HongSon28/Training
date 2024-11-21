#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,k,m;
int sign[N+5];
bool w[N+5][N+5];
bool beautiful[N+5];
vector<int>adj[N+5];
bool st[N+5];
long long dp[N+5][N+5];
long long mx1[N+5][7],mx2[N+5][7];
struct line{
	int len,sign;
	long long val;
};
vector<line>v1,v2;
long long f[N+5][7][N+5],inf=1e18,res;
int main() {
	freopen("WORD.INP","r",stdin);
	freopen("WORD.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k>>m;
	for (int i=1;i<=n;i++) cin>>sign[i];
	for (int i=1;i<=6;i++) {
		for (int j=1;j<=6;j++) cin>>w[i][j];
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			bool t;
			cin>>t;
			if (t) adj[j].push_back(i);
		}
		cin>>beautiful[i];
	}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=6;j++) mx1[i][j]=mx2[i][j]=-inf;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++) dp[i][j]=-inf;
	for (int i=1;i<=n;i++) {
		cin>>st[i];
		if (st[i]) {
			dp[1][i]=k;
			if (beautiful[i]) mx1[1][sign[i]]=max(mx1[1][sign[i]],(long long)k);
			else mx2[1][sign[i]]=max(mx2[1][sign[i]],(long long)k);
		}
	}
	cin>>st[0];
	for (int len=2;len<=m;len++) {
		for (int i=1;i<=n;i++) {
			for (auto j:adj[i]) {
				dp[len][i]=max(dp[len][i],dp[len-1][j]+(k-len+1));
			}
			if (beautiful[i]) mx1[len][sign[i]]=max(mx1[len][sign[i]],dp[len][i]);
			else mx2[len][sign[i]]=max(mx2[len][sign[i]],dp[len][i]);
			//cout<<len<<' '<<i<<' '<<sign[i]<<' '<<beautiful[i]<<' '<<dp[len][i]<<' '<<j<<' '<<dp[len-1][j]<<endl;
		}
	}
	for (int sum=0;sum<=m;sum++)
		for (int p=0;p<=m;p++) 
			for (int ed=1;ed<=6;ed++) f[sum][ed][p]=-inf;
	for (int len=1;len<=m;len++) {
		for (int sign=1;sign<=6;sign++) {
			if (mx1[len][sign]>0) {
				v1.push_back({len,sign,mx1[len][sign]});
				f[len][sign][0]=mx1[len][sign];
			}
			if (mx2[len][sign]>0) v2.push_back({len,sign,mx2[len][sign]});
		}
	}
	//for (auto [len,sign,val]:v1) cout<<len<<' '<<sign<<' '<<val<<endl;
	//for (auto [len,sign,val]:v2) cout<<len<<' '<<sign<<' '<<val<<endl;
	for (int p=0;p<=m;p++) {
		for (int sum=0;sum<=m;sum++) {
			for (int ed=1;ed<=6;ed++) {
				for (auto [len,sign,val]:v1) {
					if (sum+len<=m) {
						f[sum+len][sign][p+w[ed][sign]]=max(f[sum+len][sign][p+w[ed][sign]],f[sum][ed][p]+val);
						//if (f[sum+len][sign][p+w[ed][sign]]>0&&f[sum][ed][p]+val==f[sum+len][sign][p+w[ed][sign]])
							//cout<<sum+len<<' '<<sign<<' '<<p+w[ed][sign]<<' '<<f[sum+len][sign][p+w[ed][sign]]<<' '<<sum<<' '<<ed<<' '<<p<<' '<<f[sum][ed][p]<<endl;
					}
				}
			}
		}
	}
	for (int sum=0;sum<=m;sum++) {
		for (int ed=1;ed<=6;ed++) {
			for (int p=0;p<=m;p++) {
				if (f[sum][ed][p]<=0) continue;
				res=max(res,1ll*p*f[sum][ed][p]);
				//cout<<p<<' '<<sum<<' '<<ed<<' '<<f[sum][ed][p]<<' '<<1ll*p*f[sum][ed][p]<<endl;
				for (auto [len,sign,val]:v2) {
					if (sum+len<=m) {
						res=max(res,1ll*p*(f[sum][ed][p]+val));
					}
				}
			}
		}
	}
	cout<<res;
}