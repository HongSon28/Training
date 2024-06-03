#include<bits/stdc++.h>
using namespace std;
const int N=359;
int n;
int s[N+5];
int dp[N+5][N+5];
pair<int,int>trace[N+5][N+5];
pair<int,int>mx[N+5],res;
vector<pair<int,int>>v;
int cur=1;
void trc(int i,int j,int id) {
	if (j==0) return;
	cur++;
	int k=trace[i][j].first,l=trace[i][j].second;
	v.push_back({id,cur});
	trc(i-k,j-1,id);
	trc(k,l,cur);
}
int main() {
	freopen("deggraph.inp","r",stdin);
	freopen("deggraph.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<n;i++) cin>>s[i];
    memset(dp,-1,sizeof(dp));
    memset(mx,-1,sizeof(mx));
    mx[1]={s[1],0};
    dp[1][0]=0;
	for (int i=2;i<=n;i++) {
		for (int j=1;j<i;j++) {
			for (int k=j;k<i;k++) {
				if (dp[i][j]<dp[k][j-1]+s[j]-s[j-1]+mx[i-k].first) {
					dp[i][j]=dp[k][j-1]+s[j]-s[j-1]+mx[i-k].first;
					trace[i][j]=make_pair(i-k,mx[i-k].second);
					//cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j]<<' '<<dp[k][j-1]<<' '<<mx[i-k].first<<' '<<mx[i-k].second<<endl;
				}
			}
			mx[i]=max(mx[i],{dp[i][j]+s[j+1]-s[j],j});
		}
	}
	for (int j=1;j<n;j++) res=max(res,{dp[n][j],j});
	cout<<res.first<<'\n'<<n-1<<'\n';
	trc(n,res.second,1);
	for (auto [x,y]:v) cout<<x<<' '<<y<<'\n';
}