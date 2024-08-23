#include<bits/stdc++.h>
using namespace std;
const int N=1e4,M=1e6;
int n,m,q;
int deg[N+5];
bitset<N>adj[N];
struct query {
	int u,v,id;
	bool operator < (const query &other) const {
		return deg[u]>deg[other.u];
	}
} qu[M+5];
int res[N+5];
int lst[N+5];
int bfs(int s,int t) {
	int cur=n-2;
	queue<pair<int,int>>q;
	for (int i=0;i<n;i++) {
		lst[i]=i;
	}
	q.push({s,0});
	swap(lst[s],lst[n-1]);
	while (!q.empty()) {
		pair<int,int>p=q.front();
		q.pop();
		int u=p.first,d=p.second;
		if (u==t) return d;
		int i=0;
		while (i<=cur) {
			if (!adj[u][lst[i]]) {
				i++;
				continue;
			}
			q.push({lst[i],d+1});
			swap(lst[i],lst[cur]);
			cur--;
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=0;i<n;i++) {
    	adj[i]|=((1<<n)-1);
    	deg[i]=n-1;
    }
    for (int i=1;i<=m;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].reset(v);
    	adj[v].reset(u);
    	deg[u]--;
    	deg[v]--;
    }
    cin>>q;
    for (int i=1;i<=q;i++) {
    	cin>>qu[i].u>>qu[i].v;
    	qu[i].id=i;
    	if (deg[qu[i].u]>deg[qu[i].v]) swap(qu[i].u,qu[i].v);
    }
    sort(qu+1,qu+1+q);
    int pos=q+1;
    for (int i=1;i<=q;i++) {
    	if (deg[qu[i].u]>=n/2) {
    		if (qu[i].u==qu[i].v) res[qu[i].id]=0;
    		else if (adj[qu[i].u][qu[i].v]) res[qu[i].id]=1;
    		else res[qu[i].id]=2;
    	} else {
    		pos=i;
    		break;
    	}
    }
    for (int i=pos;i<=q;i++) res[qu[i].id]=bfs(qu[i].u,qu[i].v);
    for (int i=1;i<=q;i++) cout<<res[i]<<'\n';
}