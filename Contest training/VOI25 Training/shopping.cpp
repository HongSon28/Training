#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
long long a[N+5];
pair<long long,int>p[N+5];
struct FenwickTree{
	long long bit[N+5];
	void reset() {
		memset(bit,0,sizeof(bit));
	}
	void update(int pos,long long val) {
		while (pos<=n) {
			bit[pos]+=val;
			pos+=(pos&(-pos));
		}
	}
	long long getval(int idx) {
		long long ans=0;
		while (idx>0) {
			ans+=bit[idx];
			idx-=(idx&(-idx));
		}
		return ans;
	}
	long long get(int l,int r) {
		return getval(r)-getval(l-1);
	}
} tree;
int l[N+5],u[N+5],v[N+5],k[N+5];
int lo[N+5],hi[N+5],res[N+5];
long long ans[N+5];
struct query{
	int l,r,u,v,id;
};
struct query2{
	int l,r,u,type,id;
	bool operator < (const query2 &other) const {
		return u<other.u;
	}
};
vector<query>vc;
vector<query2>qu;
void solve() {
	int pos=1;
	qu.clear();
	tree.reset();
	for (auto [l,r,u,v,id]:vc) {
		ans[id]=0;
		qu.push_back({l,r,u-1,-1,id});
		qu.push_back({l,r,v,1,id});
	}
	sort(qu.begin(),qu.end());
	for (auto [l,r,u,type,id]:qu) {
		while (pos<=n&&p[pos].first<=u) {
			tree.update(p[pos].second,p[pos].first);
			pos++;
		}
		ans[id]+=tree.get(l,r)*type;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
		p[i]={a[i],i};
	}
	sort(p+1,p+1+n);
	for (int i=1;i<=q;i++) {
		cin>>l[i]>>u[i]>>v[i]>>k[i];
		lo[i]=l[i],hi[i]=n;
		res[i]=l[i]-1;
	}
	int running=q;
	while (running>0) {
		running=0;
		vc.clear();
		for (int i=1;i<=q;i++) {
			if (lo[i]>hi[i]) continue;
			vc.push_back({l[i],(lo[i]+hi[i])/2,u[i],v[i],i});
		}
		solve();
		for (int i=1;i<=q;i++) {
			if (lo[i]>hi[i]) continue;
			int mid=(lo[i]+hi[i])/2;
			if (ans[i]<=k[i]) {
				res[i]=mid;
				lo[i]=mid+1;
			} else hi[i]=mid-1;
			running+=(lo[i]<=hi[i]);
		}
	}
	for (int i=1;i<=q;i++) cout<<res[i]-l[i]+1<<'\n';
}