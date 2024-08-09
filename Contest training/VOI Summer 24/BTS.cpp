#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct edge{
	int u,v;
	long long w;
	bool operator < (const edge &other) const {
		return w<other.w;
	}
};
int n;
long long res;
struct point{
	long long x,y;
	int id;
	bool operator < (const point &other) const {
		return x<other.x;
	}
} p[N+5];
bool comp(point a,point b) {
	return a.y<b.y;
}
vector<edge>vc;
int	par[N+5];
int find_root(int u) {
	if (par[u]<0) return u;
	return par[u]=find_root(par[u]);
}
bool Union(int u,int v) {
	if ((u=find_root(u))==(v=find_root(v))) return false;
	if (par[u]>par[u]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(par,-1,sizeof(par));
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>p[i].x>>p[i].y;
    	p[i].id=i;
    }
    sort(p+1,p+1+n);
    for (int i=2;i<=n;i++) vc.push_back({p[i-1].id,p[i].id,p[i].x-p[i-1].x});
    sort(p+1,p+1+n,comp);
    for (int i=2;i<=n;i++) vc.push_back({p[i-1].id,p[i].id,p[i].y-p[i-1].y});
    sort(vc.begin(),vc.end());
    for (auto [u,v,w]:vc) if (Union(u,v)) res+=w;
    cout<<res;
}