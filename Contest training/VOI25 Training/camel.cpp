#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,q;
struct query{
	int x,l,r,id;
	bool operator < (const query &other) const {
		return x>other.x;
	}
};
vector<query>q1,q2;
int a[N+5],pre[N+5],suf[N+5];
int res[N+5];
int st[N*4+5];
pair<int,int>p[N+5];
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
void solve_left() {
	if (q1.empty()) return;
	sort(q1.begin(),q1.end());
	for (int i=1;i<=n;i++) p[i]={pre[i],i};
	sort(p+1,p+1+n,greater<pair<int,int>>());
	int cur=1;
	for (auto [x,l,r,id]:q1) {
		while(cur<=n&&p[cur].first>=x) {
			update(1,1,n,p[cur].second);
			cur++;
		}
		res[id]=get(1,1,n,l,r);
	}
}
void solve_right() {
	if (q2.empty()) return;
	memset(st,0,sizeof(st));
	sort(q2.begin(),q2.end());
	for (int i=1;i<=n;i++) p[i]={suf[i],i};
	sort(p+1,p+1+n,greater<pair<int,int>>());
	int cur=1;
	for (auto [x,l,r,id]:q2) {
		while(cur<=n&&p[cur].first>=x) {
			update(1,1,n,p[cur].second);
			cur++;
		}
		res[id]=get(1,1,n,r,l);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>q;
	for (int i=1;i<=n;i++) {
		char c;
		cin>>c;
		if (c=='+') a[i]=1;
		else a[i]=-1;
		pre[i]=pre[i-1]+a[i];
	}
	for (int i=n;i>=1;i--) suf[i]=suf[i+1]+a[i];
	for (int i=1;i<=q;i++) {
		query temp;
		cin>>temp.l>>temp.r;
		temp.id=i;
		if (temp.l<=temp.r) {
			temp.x=pre[temp.l-1]+1;
			q1.push_back(temp);
		} else {
			temp.x=suf[temp.l+1]+1;
			q2.push_back(temp);
		}
	}
	solve_left();
	solve_right();
	for (int i=1;i<=q;i++) cout<<res[i]<<'\n';
}