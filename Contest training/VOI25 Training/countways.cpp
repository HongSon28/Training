#include<bits/stdc++.h>
using namespace std;
const int N=6e5;
int n,q;
pair<int,int>p[N+5];
vector<int>cprs;
map<pair<int,int>,bool>col;
struct query{
	int type,x,y,u,v;
} qu[N+5];
long long cnt[N+5],mod=1e9+7;
long long st[N*4+5];
void build(int id,int l,int r) {
	if (l==r) {
		st[id]=cnt[l]+1;
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=(st[id*2]*st[id*2+1])%mod;
}
void update(int id,int l,int r,int pos) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]=cnt[l]+1;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos);
	update(id*2+1,mid+1,r,pos);
	st[id]=(st[id*2]*st[id*2+1])%mod;
}
long long get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return 1;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)*get(id*2+1,mid+1,r,u,v)%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>q;
	for (int i=1;i<=n;i++) {
		cin>>p[i].first>>p[i].second;
		cprs.push_back(p[i].first);
	}
	for (int i=1;i<=q;i++) {
		cin>>qu[i].type>>qu[i].x>>qu[i].y;
		cprs.push_back(qu[i].x);
		if (qu[i].type==2) {
			cin>>qu[i].u>>qu[i].v;
			cprs.push_back(qu[i].u);
		}
	}
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	int m=cprs.size();
	for (int i=1;i<=n;i++) {
		p[i].first=lower_bound(cprs.begin(),cprs.end(),p[i].first)-cprs.begin()+1;
		col[p[i]]=true;
		cnt[p[i].first]++;
		//cout<<p[i].first<<' '<<cnt[p[i].first]<<endl;
	}
	build(1,1,m);
	for (int i=1;i<=q;i++) {
		qu[i].x=lower_bound(cprs.begin(),cprs.end(),qu[i].x)-cprs.begin()+1;
		if (qu[i].type==1) {
			if (col[{qu[i].x,qu[i].y}]) cnt[qu[i].x]--;
			else cnt[qu[i].x]++;
			col[{qu[i].x,qu[i].y}]=1-col[{qu[i].x,qu[i].y}];
			update(1,1,m,qu[i].x);
		} else {
			qu[i].u=lower_bound(cprs.begin(),cprs.end(),qu[i].u)-cprs.begin()+1;
			if (qu[i].x==qu[i].u&&qu[i].y==qu[i].v) cout<<1<<'\n';
			else if (qu[i].x>=qu[i].u) cout<<0<<'\n';
			else cout<<get(1,1,m,qu[i].x+1,qu[i].u-1)<<'\n';
		}
	}
}