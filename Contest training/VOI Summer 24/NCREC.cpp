#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
struct query{
	int x,y1,y2,type,id;
	bool operator < (const query &other) const {
		if (x!=other.x) return x<other.x;
		return type>other.type;
	}
};
vector<query>v;
set<int>s[N+5];
vector<int>cprs;
int n,m;
int a[N+5],b[N+5],c[N+5],d[N+5],x[N+5],y[N+5],k[N+5],par[N+5],res[N+5];
int st[N*4+5];
bool lazy[N*4+5];
void down(int id) {
	if (lazy[id]) {
		lazy[id]=false;
		lazy[id*2]=lazy[id*2+1]=true;
		st[id*2]=st[id*2+1]=st[id];
	}
}
void update(int id,int l,int r,int u,int v,int val) {
	if (l>v||r<u) return;
	if (u<=l&&r<=v) {
		st[id]=val;
		lazy[id]=true;
		//cout<<"UPDATE: "<<id<<' '<<l<<' '<<r<<' '<<st[id]<<' '<<st[2]<<endl;
		return;
	}
	down(id);
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
}
int get(int id,int l,int r,int pos) {
	if (l>pos||r<pos) return -1;
	//cout<<"GET: "<<id<<' '<<l<<' '<<r<<' '<<pos<<' '<<st[id]<<' '<<st[2]<<endl;
	if (l==r) return st[id];
	down(id);
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,pos),get(id*2+1,mid+1,r,pos));
}
vector<int>adj[N+5];
void dfs(int u,int par) {
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		if (s[u].size()<s[v].size()) swap(s[u],s[v]);
		for (auto i:s[v]) s[u].insert(i);
	}
	res[u]=s[u].size();
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	cin>>a[i]>>b[i]>>c[i]>>d[i];
    	cprs.push_back(b[i]);
    	cprs.push_back(d[i]);
    }
    for (int i=1;i<=m;i++) {
    	cin>>x[i]>>y[i]>>k[i];
    	cprs.push_back(y[i]);
    }
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    int SZ=cprs.size();
    for (int i=1;i<=n;i++) {
    	b[i]=lower_bound(cprs.begin(),cprs.end(),b[i])-cprs.begin()+1;
    	d[i]=lower_bound(cprs.begin(),cprs.end(),d[i])-cprs.begin()+1;
    	v.push_back({a[i],b[i],d[i],1,i});
    	v.push_back({c[i]+1,b[i],d[i],2,i});
    }
    for (int i=1;i<=m;i++) {
    	y[i]=lower_bound(cprs.begin(),cprs.end(),y[i])-cprs.begin()+1;
    	v.push_back({x[i],y[i],y[i],0,i});
    }
    sort(v.begin(),v.end());
    for (auto [x,y1,y2,type,id]:v) {
    	//cout<<x<<' '<<y1<<' '<<y2<<' '<<type<<' '<<id<<endl;
    	if (type==1) {
    		par[id]=get(1,1,SZ,y1);
    		update(1,1,SZ,y1,y2,id);
    	} else if (type==2) {
    		update(1,1,SZ,y1,y2,par[id]);
    	} else {
    		s[get(1,1,SZ,y1)].insert(k[id]);
    	}
    }
    /*
    for (int i=1;i<=n;i++) {
    	cout<<par[i]<<' '<<s[i].size()<<endl;
    	for (auto j:s[i]) cout<<j<<' ';
    	cout<<endl;
	}
	*/
	for (int i=1;i<=n;i++) adj[par[i]].push_back(i);
	dfs(0,-1);
	for (int i=1;i<=n;i++) cout<<res[i]<<'\n';
}