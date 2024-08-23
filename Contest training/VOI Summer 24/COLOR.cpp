#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N=5e5;
int n,m;
struct paint{
	int l,r,c,id;
	bool operator < (const paint &other) const {
		return c<other.c;
	}
} x[N+5];
int inf=1e9+5;
int a[N+5];
int deg[N+5];
queue<int>q;
struct SegmentTree {
	struct Node{
		vector<int>v;
		int mn,mx;
	} st[N*4+5];
	void add(int id,int l,int r,const int &u,const int &v,const int &i) {
		if (l>v||r<u) return;
		if (u<=l&&r<=v) {
			st[id].v.emplace_back(i);
			deg[i]++;
			st[id].mn=min(st[id].mn,x[i].c);
			st[id].mx=max(st[id].mx,x[i].c);
			return;
		}
		int mid=(l+r)>>1;
		add(id<<1,l,mid,u,v,i);
		add(id<<1|1,mid+1,r,u,v,i);
	}
	void add(const int &i) {
		add(1,1,n,x[i].l,x[i].r,i);
	}
	void calc(int id) {
		//cout<<id<<' '<<st[id].mn<<' '<<st[id].mx<<endl;
		if (st[id].mn>st[id].mx) {
			for (auto t:st[id].v) {
				deg[t]--;
				if (!deg[t]) q.push(t);
			}
			st[id].v.clear();
		} else if (st[id].mn==st[id].mx) {
			int l=0,r=st[id].v.size()-1;
			int pos=st[id].v.size();
			while (l<=r) {
				int mid=(l+r)>>1;
				if (x[st[id].v[mid]].c>=st[id].mn) {
					pos=mid;
					r=mid-1;
				} else l=mid+1;
			}
			int cnt=0;
			while (pos<(int)st[id].v.size()&&x[st[id].v[pos]].c==st[id].mn) {
				cnt++;
				deg[st[id].v[pos]]--;
				if (deg[st[id].v[pos]]==0) q.push(st[id].v[pos]);
				pos++;
			}
			for (int i=pos;i<(int)st[id].v.size();i++) st[id].v[i-cnt]=st[id].v[i];
			while (cnt--) st[id].v.pop_back();
		}
	}
	void build(int id,int l,int r) {
		if (l==r) {
			if (a[l]==0) {
				st[id].mn=inf;
				st[id].mx=-inf;
			} else st[id].mn=st[id].mx=a[l];
			if (st[id].mn>st[id].mx&& !st[id].v.empty()) {
				cout<<-1;
				exit(0);
			}
			//cout<<id<<' '<<l<<' '<<r<<' '<<st[id].mn<<' '<<st[id].mx<<' '<<st[id].v.size()<<endl;
			calc(id);
			return;
		}
		int mid=(l+r)>>1;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
		st[id].mn=min(st[id<<1].mn,st[id<<1|1].mn);
		st[id].mx=max(st[id<<1].mx,st[id<<1|1].mx);
		if (st[id].mn>st[id].mx&& !st[id].v.empty()) {
			cout<<-1;
			exit(0);
		}
		//cout<<id<<' '<<l<<' '<<r<<' '<<st[id].mn<<' '<<st[id].mx<<' '<<st[id].v.size()<<endl;
		calc(id);
	}
	void build() {
		build(1,1,n);
	}
	void del(int id,int l,int r,const int &u,const int &v) {
		if (l>v||r<u) return;
		if (st[id].mn>st[id].mx) return;
		if (l==r) {
			st[id].mn=inf;
			st[id].mx=-inf;
			calc(id);
			return;
		}
		int mid=(l+r)>>1;
		del(id<<1,l,mid,u,v);
		del(id<<1|1,mid+1,r,u,v);
		st[id].mn=min(st[id<<1].mn,st[id<<1|1].mn);
		st[id].mx=max(st[id<<1].mx,st[id<<1|1].mx);
		calc(id);
	}
	void del(const int &i) {
		del(1,1,n,x[i].l,x[i].r);
	}
} seg;
vector<int>res;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
    	cin>>x[i].l>>x[i].r>>x[i].c;
    	x[i].id=i;
    }
    sort(x+1,x+1+m);
    for (int i=1;i<=m;++i) {
    	seg.add(i);
    	//cout<<x[i].l<<' '<<x[i].r<<' '<<x[i].c<<' '<<x[i].id<<' '<<deg[i]<<endl;
    }
    for (int i=1;i<=n;i++) cin>>a[i];
    seg.build();
    while (!q.empty()) {
    	int u=q.front();
    	q.pop();
    	res.emplace_back(u);
    	seg.del(u);
    }
    if ((int)res.size()<m) {
    	cout<<-1;
    	return 0;
    }
    for (int i=res.size()-1;i>=0;--i) cout<<x[res[i]].id<<' ';
}