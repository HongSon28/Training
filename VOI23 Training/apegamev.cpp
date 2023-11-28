#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
vector<vector<int>>adj(N+5);
int p[N+5],w[N+5];
struct dat{
	int s,d,id;
	bool operator < (const dat &other) const {
		if (d!=other.d) return d<other.d;
		return s<other.s;
	}
}query[N+5];
int sum[N+5],res[N+5],mx[N+5],cur;
void add_node(int node) {
	int u=node;
	int temp=w[node]
	while (u!=1) {
		int v=p[node];
		temp+=w[v];
		if (mx[v]<sum[v]+temp)
	}
}
int main() {
	cin>>n>>q;
	for (int i=2;i<=n;i++) cin>>p[i];
	for (int i=2;i<=n;i++) cin>>w[i];
	for (int i=1;i<=q;i++) {
		cin>>query[i].s>>query[i].d;
		query[i].id=i;
	}
	sort(query+1,query+1+q);
	cur=1;
	for (int i=1;i<=q;i++) {
		while (cur<query[i].d&&cur<n) {
			cur++;
			add_node(cur);
		}
	}
}