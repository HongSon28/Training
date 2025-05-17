#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
int a[N+5];
vector<int>cprs;
int p[N+5];
vector<int>pos[N+5];
int res[N+5];
bool good[N+5];
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
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		p[i]=-1;
		cprs.push_back(a[i]);
	}	
	cprs.push_back(0);
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	int m=cprs.size()-1;
	for (int i=1;i<=n;i++) {
		int t=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin();
		pos[t].push_back(i);
	}
	int cur=0,last=0;
	for (int i=m;i>=1;i--) {
		for (auto x:pos[i]) {
			good[x]=true;
			if (x>1&&good[x-1]) Union(x,x-1);
			if (x<n&&good[x+1]) Union(x,x+1);
			cur=max(cur,-p[find_root(x)]);
		}
		for (int j=last+1;j<=cur;j++) res[j]=cprs[i];
		last=cur;
	}
	for (int i=1;i<=n;i++) cout<<res[i]<<' ';
}