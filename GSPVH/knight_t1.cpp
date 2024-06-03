#include<bits/stdc++.h>
using namespace std;
const int N=6000,MX=4000,MN=-2000;
int t,a,b,x,y;
int dp[N+5][N+5],mod=998244353;
int dx[]={2,2,1,-1};
int dy[]={-1,1,2,2};
void add(int &x, const int &y) {
	x+=y;
	if (x>=mod) x-=mod;
}
bool inside(int x,int y) {
	if (x<MN||y<MN||x>MX||y>MX) return false;
	return true;
}
int main() {
	freopen("knight.inp","r",stdin);
	freopen("knight.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    dp[2000][2000]=1;	
    for (int sum=0;sum<=2*MX;sum++) {
    	for (int x=max(MN,sum-MX);x<=min(MX,sum-MN);x++) {
    		int y=sum-x;
    		for (int i=0;i<4;i++) {
    			if (!inside(x+dx[i],y+dx[i])) continue;
    			add(dp[x+dx[i]+2000][y+dy[i]+2000],dp[x+2000][y+2000]);
    		}
    	}
    }
    cin>>t;
    while (t--) {
    	cin>>a>>b>>x>>y;
    	x+=2000-a,y+=2000-b;
    	if (x+y<0) cout<<0<<'\n';
    	else cout<<dp[x][y]<<'\n';
    }
}