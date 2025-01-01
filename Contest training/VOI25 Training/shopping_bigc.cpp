#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N=5e3;
int n,b,inf=1e9+5;
vector<int>adj[N+5];
int d[N+5],c[N+5];
int res;
int f[N+5][N+5][2],g[N+5][2];
int sz[N+5];
void mini(int &x,int y) {
	if (x>y) x=y;
}
void dfs(int u) {
	sz[u]=1;
	for (auto v:adj[u]) {
		dfs(v);
		sz[u]+=sz[v];
	}
	for (int i=0;i<=sz[u];i++) f[u][i][0]=f[u][i][1]=inf;
	f[u][0][0]=f[u][0][1]=0;
	int cur=0;
	for (auto v:adj[u]) {
		cur+=sz[v];
		for (int i=1;i<=cur;i++) {
			for (int k=0;k<=1;k++) {
				g[i][k]=f[u][i][k];
			}
		}
		for (int i=1;i<=sz[v];i++) {
			for (int j=cur;j>=i;j--) {
				for (int k1=0;k1<=1;k1++) {
					for (int k2=0;k2<=1;k2++) {
						mini(f[u][j][k1|k2],g[j-i][k1]+f[v][i][k2]);
					}
				}
			}
		}
	}
	for (int i=sz[u];i>=1;i--) {
		mini(f[u][i][0],f[u][i-1][0]+c[u]);
		f[u][i][1]=f[u][i-1][1]+c[u]-d[u];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>b;
    cin>>c[1]>>d[1];
    for (int i=2;i<=n;i++) {
    	int p;
    	cin>>c[i]>>d[i]>>p;
    	adj[p].push_back(i);
    }	
    dfs(1);
    for (int i=n;i>=0;i--) 
    	if (f[1][i][0]<=b||f[1][i][1]<=b) {
    		cout<<i;
    		break;
    	}
}