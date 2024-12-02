#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
int n,m;
pair<int,int>p[N+5];
bool comp(pair<int,int>x,pair<int,int>y) {
	if (x.second!=y.second) return x.second<y.second;
	return x.first<y.first;
}
vector<pair<int,int>>v[N+5];
vector<int>dp[N+5];
map<int,int>lx,l1,l2;
int inf=1e9;
int pre[N+5],suf[N+5];
int res;
void maxi(int i) {
	int m=v[i].size()-1;
	pre[0]=-inf,suf[m+1]=-inf;
	for (int j=1;j<=m;j++) pre[j]=max(pre[j-1],dp[i][j]);
	for (int j=m;j>=1;j--) suf[j]=max(suf[j+1],dp[i][j]);
	for (int j=1;j<=m;j++) {
		dp[i][j]=max({dp[i][j],pre[j-1]+j-1,suf[j+1]+m-j});
		lx[v[i][j].first]=dp[i][j];
		l1[v[i][j].first-v[i][j].second]=dp[i][j];
		l2[v[i][j].first+v[i][j].second]=dp[i][j];
		//cout<<i<<' '<<v[i][j].first<<' '<<v[i][j].second<<' '<<dp[i][j]<<endl;
		res=max(res,dp[i][j]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    p[0]={0,0};
    sort(p,p+1+n,comp);
    for (int i=0;i<=n;i++) {
    	if (i==0||p[i].second!=p[i-1].second) {
    		m++;
    		v[m].emplace_back();
    		dp[m].push_back(-inf);
    	}
    	v[m].push_back(p[i]);
    	dp[m].push_back(-inf);
    	if (p[i]==make_pair(0,0)) dp[m][dp[m].size()-1]=0;
    }
    /*
    for (int i=1;i<=m;i++) {
    	cout<<i<<endl;
    	for (auto [x,y]:v[i]) cout<<x<<' '<<y<<endl;
    }*/
    maxi(1);
    for (int i=2;i<=m;i++) {
    	for (int j=1;j<(int)v[i].size();j++) {
    		if (lx.count(v[i][j].first)) {
    			int t=lx[v[i][j].first];
    			dp[i][j]=max(dp[i][j],t+1);
    		}
    		if (l1.count(v[i][j].first-v[i][j].second)) {
    			int t=l1[v[i][j].first-v[i][j].second];
    			dp[i][j]=max(dp[i][j],t+1);
    		}
    		if (l2.count(v[i][j].first+v[i][j].second)) {
    			int t=l2[v[i][j].first+v[i][j].second];
    			dp[i][j]=max(dp[i][j],t+1);
    		}
    	}
    	maxi(i);
    }
    cout<<res;
}