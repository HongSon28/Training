#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
long long a[N+5],dp[N+5],res;
vector<int>adj[N+5];
void dfs(int u,int par) {
	dp[u]=a[u];
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		if (dp[v]>=0) dp[u]+=dp[v];
	}
	res=max(res,dp[u]);
}
int solve() {
	res=-1e9;
	for (int i=1;i<=n;i++) res=max(res,a[i]);
	dfs(1,0);
	return res;
}

multiset<int>ms;
struct Node{
	long long sum,pre,suf,mx;
} st[N*4+5];
int id[N+5],b[N+5];
Node Merge(Node x, Node y) {
	Node ans;
	ans.sum=x.sum+y.sum;
	ans.pre=max(x.pre,x.sum+y.pre);
	ans.suf=max(y.suf,y.sum+x.suf);
	ans.mx=max({x.mx,y.mx,x.suf+y.pre});
	return ans;
}
void build(int id,int l,int r) {
	if (l==r) {
		st[id].sum=a[b[l]];
		st[id].mx=st[id].pre=st[id].suf=max(a[b[l]],0ll);
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=Merge(st[id*2],st[id*2+1]);
}
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id].sum=val;
		st[id].mx=st[id].pre=st[id].suf=max(val,0);
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id]=Merge(st[id*2],st[id*2+1]);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    cin>>q;
    if (n<=1000&&q<=1000) {
	    while (q--) {
	    	int u,x;
	    	cin>>u>>x;
	    	a[u]=x;
	    	cout<<solve()<<'\n';
	    }
    } else {
    	for (int i=1;i<=n;i++) {
    		if (adj[i].size()==1) {
    			id[i]=1;
    			b[1]=i;
    			break;
    		}
    	}
    	for (int i=2;i<=n;i++) {
    		if (adj[b[i-1]][0]!=b[i-2]) b[i]=adj[b[i-1]][0];
    		else b[i]=adj[b[i-1]][1];
    		id[b[i]]=i;
    		//cout<<b[i]<<endl;
    	}
    	for (int i=1;i<=n;i++) ms.insert(a[i]);
    	build(1,1,n);
    	while (q--) {
	    	int u,x;
	    	cin>>u>>x;
	    	ms.erase(ms.lower_bound(a[u]));
	    	ms.insert(x);
	    	a[u]=x;
	    	update(1,1,n,id[u],x);
	    	res=*ms.rbegin();
	    	if (res<0) cout<<res<<'\n';
	    	else cout<<max(res,st[1].mx)<<'\n';
	    }
    }
}