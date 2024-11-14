#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,q;
int p[N+5];
struct query{
	int l,r,id;
	bool operator < (const query &other) const {
		return r<other.r;
	}
} qu[N+5];
bool cmp(query x,query y) {
	return x.l>y.l;
}
struct SegmentTree{
	int st[N*4+5];
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
	int get(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return 0;
		if (u<=l&&r<=v) return st[id];
		int mid=(l+r)/2;
		return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
	}
	void reset() {
		memset(st,0,sizeof(st));
	}
} tree;
vector<pair<int,int>>cyc;
bool comp(pair<int,int>x,pair<int,int>y) {
	if (x.second!=y.second) return x.second<y.second;
	return x.first<y.first;
}
bool used[N+5];
int c0[N+5],c1[N+5];
int pos[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
    	cin>>p[i];
    	pos[p[i]]=i;
    }
    for (int i=1;i<=n;i++) {
    	if (used[i]) continue;
    	int t=i;
    	t=p[t];
    	used[t]=used[i]=true;
    	int r=t;
    	while (t!=i) {
    		t=p[t];
    		r=max(r,t);
    		used[t]=true;
    	}
    	cyc.push_back({i,r});
    	//cout<<i<<' '<<r<<endl;
    }
    sort(cyc.begin(),cyc.end(),comp);
    for(int i=1;i<=q;i++) {
    	cin>>qu[i].l>>qu[i].r;
    	qu[i].id=i;
    }
    sort(qu+1,qu+1+q);
    int p1=0,p2=1;
    for (int i=1;i<=n;i++) {
    	while (p1<(int)cyc.size()&&cyc[p1].second<=i) {
    		tree.update(1,1,n,cyc[p1].first);
    		p1++;
    	}
    	while (p2<=q&&qu[p2].r<=i) {
    		c0[qu[p2].id]=tree.get(1,1,n,qu[p2].l,qu[p2].r);
    		p2++;
    	}
    }
    tree.reset();
    p1=1;
    for (int r=1;r<=n;r++) {
    	tree.update(1,1,n,pos[r]);
    	while (p1<=q&&qu[p1].r<=r) {
	    	int x=qu[p1].l,y=qu[p1].r;
    		c1[qu[p1].id]+=y-x+1-tree.get(1,1,n,x,y);
    		p1++;
    	}
    }
    tree.reset();
    sort(qu+1,qu+1+q,cmp);
    p1=1;
    for (int l=n;l>=1;l--) {
    	tree.update(1,1,n,pos[l]);
    	while (p1<=q&&qu[p1].l>=l) {
	    	int x=qu[p1].l,y=qu[p1].r;
    		c1[qu[p1].id]+=y-x+1-tree.get(1,1,n,x,y);
    		p1++;
    	}
    }
    for (int i=1;i<=q;i++) {
    	if (c1[i]==0) cout<<c0[i]-1<<'\n';
    	else if (c0[i]==0) cout<<c1[i]<<'\n';
    	else cout<<c0[i]+c1[i]<<'\n';
    }
}