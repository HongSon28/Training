#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,m,k;
int c[N+5];
struct edge{
	int u,v;
	long long w;
	bool operator < (const edge &other) const {
		return w<other.w;
	}
};
vector<edge>ed;
namespace sub1{
	bool check() {
		return (n==2&&m==1);
	}
	void solve() {
		if ((c[1]==1&&c[2]==1)||(c[1]==2&&c[2]==2)) {
			cout<<-1<<'\n';
			return;
		}
		cout<<ed[0].w<<'\n';
	}
}
struct DSU{
	int p[N+5];
	void init() {
		memset(p,-1,sizeof(p));
	}
	int find_root(int u) {
		if (p[u]<0) return u;
		return p[u]=find_root(p[u]);
	}
	void Union(int u,int v) {
		if ((u=find_root(u))==(v=find_root(v))) return;
		if (p[u]>p[v]) swap(u,v);
		p[u]+=p[v];
		p[v]=u;
	}
} dsu;
namespace sub2{
	bool check() {
		for (int i=1;i<=n;i++) {
			if (c[i]!=i) return false;
		}
		return true;
	}
	long long res=0,cnt=0;
	void solve() {
		dsu.init();
		sort(ed.begin(),ed.end());
		for (auto [u,v,w]:ed){
			if (dsu.find_root(u)!=dsu.find_root(v)) {
				dsu.Union(u,v);
				cnt++;
				res+=w;
			}
		}
		if (cnt<k-1) cout<<-1<<'\n';
		else cout<<res<<'\n';
	}
}
namespace sub3{
	bool check() {
		return (n<=6&&m<=20);
	}
	long long inf=1e18,res=inf;
	int b[N+5];
	vector<edge>cur;
	long long calc() {
		dsu.init();
		cur.clear();
		long long ans=0,cnt=0;
		for (auto [u,v,w]:ed) cur.push_back({b[u],b[v],w});
		for (auto [u,v,w]:cur) {
			//cout<<u<<' '<<v<<' '<<w<<endl;
			if (dsu.find_root(u)!=dsu.find_root(v)) {
				dsu.Union(u,v);
				cnt++;
				ans+=w;
			}
		}
		if (cnt<k-1) return inf;
		return ans;
	}
	void rec(int i) {
		if (i==n+1) {
			res=min(res,calc());
			return;
		}
		if (c[i]!=0) {
			b[i]=c[i];
			rec(i+1);
			return;
		}
		for (int t=1;t<=k;t++) {
			b[i]=t;
			rec(i+1);
		}
	}
	void solve() {
		res=inf;
		sort(ed.begin(),ed.end());
		rec(1);
		if (res==inf) cout<<-1<<'\n';
		else cout<<res<<'\n';
	}
}
namespace sub4{
	bool check() {
		for (int i=1;i<=n;i++) {
			if (c[i]!=0) return false;
		}
		return true;
	}
	long long res=0,cnt=0;
	void solve() {
		dsu.init();
		sort(ed.begin(),ed.end());
		for (auto [u,v,w]:ed){
			if (dsu.find_root(u)!=dsu.find_root(v)) {
				dsu.Union(u,v);
				cnt++;
				res+=w;
			}
			if (cnt==k-1) break;
		}
		if (cnt<k-1) cout<<-1<<'\n';
		else cout<<res<<'\n';
	}
}
int main() {
	freopen("GRAPHZIP.INP","r",stdin);
	freopen("GRAPHZIP.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	cin>>n>>m>>k;
    	for (int i=1;i<=n;i++) cin>>c[i];
    	ed.clear();
    	for (int i=1;i<=m;i++) {
    		int u,v,w;
    		cin>>u>>v>>w;
    		ed.push_back({u,v,w});
    	}
    	if (sub1::check()) sub1::solve();
    	else if (sub2::check()) sub2::solve();
    	else if (sub3::check()) sub3::solve();
    	else sub4::solve();
    }	
}