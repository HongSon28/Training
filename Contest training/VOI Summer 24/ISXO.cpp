#include<bits/stdc++.h>
using namespace std;
const int N=2e3+2;
struct node{
	int pre,suf,sum,mx;
} st[N*4+5];
int n,m;
vector<pair<int,int>>p[N+5];
pair<int,int>p1[N+5],p2[N+5];
int inf=1e9+5,res=-inf;
node merge(node x,node y) {
	node ans;
	ans.pre=max(x.pre,x.sum+y.pre);
	ans.suf=max(y.suf,y.sum+x.suf);
	ans.sum=x.sum+y.sum;
	ans.mx=max({x.mx,y.mx,x.suf+y.pre});
	return ans;
}
void build(int id,int l,int r) {
	if (l==r) {
		st[id]={0,0,0,0};
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=merge(st[id*2],st[id*2+1]);
}
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id].pre+=val;
		st[id].suf+=val;
		st[id].sum+=val;
		st[id].mx+=val;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id]=merge(st[id*2],st[id*2+1]);
}
node get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return {-inf,-inf,0,-inf};
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    int a,b;
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>p1[i].first>>p1[i].second;
    	p1[i].first+=1001;
    	p1[i].second+=1001;
    }
    cin>>m;
    for (int i=1;i<=m;i++) {
    	cin>>p2[i].first>>p2[i].second;
    	p2[i].first+=1001;
    	p2[i].second+=1001;
    }
    cin>>a>>b;
    for (int i=1;i<=n;i++) p[p1[i].first].push_back({p1[i].second,a});
    for (int i=1;i<=m;i++) p[p2[i].first].push_back({p2[i].second,-b});
	for (int i=1;i<=N;i++) {
		build(1,1,N);
		for (int j=i;j<=N;j++) {
			for (auto [pos,val]:p[j]) update(1,1,N,pos,val);
			res=max(res,st[1].mx);
		}
	}
	cout<<res;
}