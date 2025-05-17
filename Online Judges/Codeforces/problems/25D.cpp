#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n;
int p[N+5];
int find_root(int u) {
	if (p[u]<0) return u;
	return p[u]=find_root(p[u]);
}
bool Union(int u,int v) {
	if ((u=find_root(u))==(v=find_root(v))) return false;
	if (p[u]>p[v]) swap(u,v);
	p[u]+=p[v];
	p[v]=u;
	return true;
}
vector<pair<int,int>>res;
vector<int>comp;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    memset(p,-1,sizeof(p));
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	if (!Union(u,v)) res.push_back({u,v});
    }
   	for (int i=1;i<=n;i++) {
   		if (find_root(i)==i) comp.push_back(i);
   	}
   	cout<<res.size()<<'\n';
   	for (int i=0;i<(int)res.size();i++) {
   		cout<<res[i].first<<' '<<res[i].second<<' '<<comp[i]<<' '<<comp[i+1]<<'\n';
   	}
}