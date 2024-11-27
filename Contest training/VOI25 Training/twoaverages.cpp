#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N=500;
int n;
int a[N+5],b[N+5];
int sa[N+5],sb[N+5];
int dp[N+5][N+5],f[N+5][N+5],mod=1e9+7;
struct dat{
	int x,y,p;
	bool operator < (const dat &other) const {
		return x*other.y<other.x*y;
	} 
	bool operator <= (const dat &other) const {
		return x*other.y<=other.x*y;
	} 
};
vector<dat>v[N+5];
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	sa[i]=sa[i-1]+a[i];
    }	
    for (int i=1;i<=n;i++) {
    	cin>>b[i];
    	sb[i]=sb[i-1]+b[i];
    }
    dp[0][0]=1;
    for (int j=1;j<=n;j++) {
    	for (int t=0;t<j;t++) v[j].push_back({sb[j]-sb[t],j-t,t});
    	sort(v[j].begin(),v[j].end());
    }
    for (int i=1;i<=n;i++) {
    	vector<dat>ord;
    	for (int t=0;t<i;t++) ord.push_back({sa[i]-sa[t],i-t,t});
    	sort(ord.begin(),ord.end());
    	for (int j=0;j<=n;j++) {
			for (int p=0;p<i;p++) {
				if (!p) f[j][p]=dp[ord[p].p][j];
				else {
					f[j][p]=f[j][p-1];
					add(f[j][p],dp[ord[p].p][j]);
				}
				//if (i==3) cout<<j<<' '<<p<<' '<<f[j][p]<<' '<<ord[p].second<<endl;
			}
    	}
    	for (int j=1;j<=n;j++) {
    		int pos=-1;
    		for (int t=0;t<(int)v[j].size();t++) {
    			while (pos+1<(int)ord.size()&&ord[pos+1]<=v[j][t]) pos++;
    			if (pos!=-1) add(dp[i][j],f[v[j][t].p][pos]);
    		}
    		//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
    	}
    }
    cout<<dp[n][n];
}