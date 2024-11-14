#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n,m,k;
vector<int>adj[N+5];
int a[N+5],b[N+5];
int d[N+5][N+5],f[N+5][N+5],inf=1e9;
queue<int>q;
double e[N+5];
long long res;
double mx;
void bfs(int s) {
	for (int i=1;i<=n;i++) d[s][i]=inf;
	d[s][s]=0;
	f[s][s]=1;
	q.push(s);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (auto v:adj[u]) {
			if (d[s][v]>d[s][u]+1) {
				q.push(v);
				d[s][v]=d[s][u]+1;
				f[s][v]=f[s][u];
			} else if (d[s][v]==d[s][u]+1) f[s][v]+=f[s][u];
		}
	}
}
int main() {
	freopen("TRAINCENTRE.INP","r",stdin);
	freopen("TRAINCENTRE.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
    	int u,v;
    	cin>>u>>v;
    	u++,v++;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    cin>>k;
    for (int i=1;i<=k;i++) {
    	cin>>a[i]>>b[i];
    	a[i]++,b[i]++;
    }
    for (int i=1;i<=n;i++) bfs(i);
    for (int i=1;i<=k;i++) {
    	for (int j=1;j<=n;j++) {
    		if (d[j][a[i]]+d[j][b[i]]==d[a[i]][b[i]]) {
    			double cur=f[j][a[i]]*f[j][b[i]];
    			cur/=f[a[i]][b[i]];
    			e[j]+=cur;
    		}
    	}
    }
    for (int i=1;i<=n;i++) {
    	//cout<<e[i]<<' ';
    	if (e[i]>mx) {
    		mx=e[i];
    		res=i-1;
    	}
    }
    cout<<res;
}