#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
vector<pair<int,int>>adj[N+5];
int l[N+5],r[N+5],x[N+5];
int col[N+5];
long long mod=1e9+7;
bool bfs(int u) {
	queue<int>q;
	if (col[u]==-1) col[u]=0;
	q.push(u);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (auto [v,w]:adj[u]) {
			if (col[v]!=-1) {
				if ((col[u]^w)!=col[v]) return false;
			} else {
				col[v]=(col[u]^w);
				q.push(v);
			}
		}
	}
	return true;
}
long long calc(int t) {
	memset(col,-1,sizeof(col));
	col[0]=0,col[n]=t;
	for (int i=1;i<=n;i++) adj[i].clear();
	for (int i=1;i<=n;i++) {
		if (l[i]>r[i]) x[i]^=t;
		adj[r[i]].push_back({l[i]-1,x[i]});
		adj[l[i]-1].push_back({r[i],x[i]});
	}
	long long res=1;
	if (!bfs(0)) return 0;
	if (!bfs(n)) return 0;
	for (int i=1;i<n;i++) {
		if (col[i]==-1) 
			if (bfs(i)) res=(res*2)%mod;
			else return 0;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>l[i]>>r[i]>>x[i];
    	l[i]=i-l[i];
    	if (l[i]<=0) l[i]+=n;
    	r[i]=i+r[i];
    	if (r[i]>n) r[i]-=n;
    }
    cout<<(calc(0)+calc(1))%mod;
}