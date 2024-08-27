#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,k,q;
int u[N+5],v[N+5];
int r1[N+5],r2[N+5],c1[N+5],c2[N+5];
bool res[N+5];
struct dat{
	int type,r1,c1,r2,c2,id;
	bool operator < (const dat &other) const {
		if (c2!=other.c2) return c2<other.c2;
		return type<other.type;
	}
};
vector<dat>vc;
pair<int,int> st[N*4+5];
int inf=1e9;
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]={val,val};
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id].first=min(st[id*2].first,st[id*2+1].first);
	st[id].second=max(st[id*2].second,st[id*2+1].second);
}
pair<int,int> get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return {inf,-inf};
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	pair<int,int>g1=get(id*2,l,mid,u,v),g2=get(id*2+1,mid+1,r,u,v);
	return {min(g1.first,g2.first),
			max(g1.second,g2.second)};
}
void solve() {
	int mx=max(m,n);
	for (int i=1;i<=N*4;i++) st[i]={0,inf};
	vc.clear();
	for (int i=1;i<=k;i++) vc.push_back({0,u[i],v[i],u[i],v[i],0});
	for (int i=1;i<=q;i++) vc.push_back({1,r1[i],c1[i],r2[i],c2[i],i});
	sort(vc.begin(),vc.end());
	for (auto [type,r1,c1,r2,c2,id]:vc) {
		//cout<<type<<' '<<r1<<' '<<c1<<' '<<r2<<' '<<c2<<' '<<id<<endl;
		if (!type) update(1,1,mx,r1,c1);
		else {
			pair<int,int>g=get(1,1,mx,r1,r2);
			//cout<<g.first<<' '<<g.second<<endl;
			if (g.first>=c1&&g.second<=c2) res[id]=true;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>k>>q;
    for (int i=1;i<=k;i++) cin>>u[i]>>v[i];
    for (int i=1;i<=q;i++) cin>>r1[i]>>c1[i]>>r2[i]>>c2[i];
    solve();
    for (int i=1;i<=k;i++) swap(u[i],v[i]);
    for (int i=1;i<=q;i++) {
    	swap(r1[i],c1[i]);
    	swap(r2[i],c2[i]);
    }
    solve();
    for (int i=1;i<=q;i++) cout<<res[i]<<'\n';
}