#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N=2e5;
int n,m;
int a[N+5],pos[N+5];
struct Query{
	int l,r,id;
	bool operator < (const Query &other) const {
		return l>other.l;
	}
} q[N+5];
long long res[N+5];
struct SegmentTree{
	long long st[N*4+5];
	void update(int id,int l,int r,int pos) {
		if (l>pos||r<pos) return;
		if (l==r) {
			st[id]++;
			return;
		}
		int mid=(l+r)/2;
		update(id*2,l,mid,pos);
		update(id*2+1,mid+1,r,pos);
		st[id]=st[id*2]+st[id*2+1];
	}
	long long get(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return 0;
		if (u<=l&&r<=v) return st[id];
		int mid=(l+r)/2;
		return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
	}
} tree;
vector<pair<int,int>>vp;
bool comp(pair<int,int>x, pair<int,int>y) {
	return x.first>y.first;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	pos[a[i]]=i;
    }
    for (int i=1;i<=n;i++) {
    	for (int j=i;j<=n;j+=i) {
    		int u=pos[i],v=pos[j];
    		if (u>v) swap(u,v);
    		vp.push_back({u,v});
    	}
    }
    sort(vp.begin(),vp.end(),comp);
    for (int i=1;i<=m;i++) {
    	cin>>q[i].l>>q[i].r;
    	q[i].id=i;
    }
    sort(q+1,q+1+m);
    int cur=0;
    for (int i=1;i<=m;i++) {
    	//cout<<q[i].id<<' '<<q[i].l<<' '<<q[i].r<<endl;
    	while (cur<vp.size()&&vp[cur].first>=q[i].l) {
    		//cout<<vp[cur].first<<' '<<vp[cur].second<<endl;
    		tree.update(1,1,n,vp[cur].second);
    		cur++;
    	}
    	res[q[i].id]=tree.get(1,1,n,q[i].l,q[i].r);
    }
    for (int i=1;i<=m;i++) cout<<res[i]<<'\n';
}