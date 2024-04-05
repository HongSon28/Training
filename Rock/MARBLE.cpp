#include<bits/stdc++.h>
using namespace std;
const int N=600;
int n,w,h;
pair<int,int>p[N+5];
int dp[N+5][N+5];
int f(int x,int y) {
	if (dp[x][y]!=-1) return dp[x][y];
	for (int i=1;i<=n;i++) if (x==p[i].first&&y==p[i].second) return dp[x][y]=0;
	int ans=x*y;
	for (int i=1;i<x;i++) ans=min(ans,f(i,y)+f(x-i,y));
	for (int i=1;i<y;i++) ans=min(ans,f(x,i)+f(x,y-i));
	return dp[x][y]=ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	memset(dp,-1,sizeof(dp));
	cin>>w>>h>>n;
	for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
	cout<<f(w,h);
}