#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,q;
map<pair<int,int>,int>id;
int curid;
pair<int,int>edge[N+5];
pair<int,int>p[N+5];
vector<int>st[N*4+5];
struct DSU{
	int par[N+5],comp;
	struct op{
		int u,pu,v,pv,val;
	};
	vector<op>ops;
	void init() {
		memset(par,-1,sizeof(par));
		comp=n;
	}
	int find_root(int u) {
		if (par[u]<0) return u;
		return find_root(par[u]);
	}
	void Union(int u,int v) {
		u=find_root(u),v=find_root(v);
		if (u==v) {
			ops.push_back({-1,-1,-1,-1,0});
			return;
		}
		comp--;
		if (par[u]>par[v]) swap(u,v);
		ops.push_back({u,par[u],v,par[v],1});
		par[u]+=par[v];
		par[v]=u;
	}
	void roll_back() {
		op t=ops.back();
		ops.pop_back();
		if (t.val==0) return;
		comp++;
		par[t.u]=t.pu;
		par[t.v]=t.pv;
	}
} dsu;
bool query[N+5];
int res[N+5];
void update(int id,int l,int r,int u,int v,int val) {
	if (u>r||v<l) return;
	if (u<=l&&r<=v) {
		st[id].push_back(val);
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
}
void dfs(int id,int l,int r) {
	//cout<<id<<' '<<l<<' '<<r<<endl;
	for (auto e:st[id]) {
		dsu.Union(edge[e].first,edge[e].second);
		//cout<<edge[e].first<<' '<<edge[e].second<<' '<<dsu.comp<<endl;
	}
	if (l==r) {
		if (query[l]) res[l]=dsu.comp;
	}
	else {
		int mid=(l+r)/2;
		dfs(id*2,l,mid);
		dfs(id*2+1,mid+1,r);
	}
	for (auto e:st[id]) dsu.roll_back();
}
int main() {
	freopen("connect.in","r",stdin);
	freopen("connect.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    if (q==0) return 0;
    for (int i=1;i<=q;i++) {
    	char type;
    	int u,v;
    	cin>>type;
    	if (type=='+') {
    		cin>>u>>v;
    		if (u>v) swap(u,v);
    		if (id[{u,v}]==0) {
    			id[{u,v}]=++curid;
    			edge[curid]={u,v};
    		}
    		p[id[{u,v}]]={i,q};
    	} else if (type=='-') {
    		cin>>u>>v;
    		if (u>v) swap(u,v);
    		int cid=id[{u,v}];
    		p[cid].second=i-1;
    		update(1,1,q,p[cid].first,p[cid].second,cid);
    		//cout<<p[cid].first<<' '<<p[cid].second<<' '<<edge[cid].first<<' '<<edge[cid].second<<endl;
    	} else {
    		query[i]=true;
    	}
    }
    for (int i=1;i<=curid;i++) {
    	if (p[i].second==q) {
    		update(1,1,q,p[i].first,p[i].second,i);
    		//cout<<p[i].first<<' '<<p[i].second<<' '<<edge[i].first<<' '<<edge[i].second<<endl;
    	}
    }
    dsu.init();
    dfs(1,1,q);
    for (int i=1;i<=q;i++) if (query[i]) cout<<res[i]<<'\n';
}