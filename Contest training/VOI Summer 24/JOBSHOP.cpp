#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
vector<int>adj[N+5],jb[N+5],topo;
queue<int>q;
int in[N+5];
bool done[N+5];
bool check(int u) {
	for (auto v:jb[u]) {
		if(!done[v]) return false;
	}
	return true;
}
void sub1() {
	for (int i=1;i<=n;i++) {
		int k;
		cin>>k;
		while (k--) {
			int j;
			cin>>j;
			adj[j].push_back(i);
			in[i]++;
			jb[i].push_back(j);
		}
	}
	for (int i=1;i<=n;i++) {
		if (!in[i]) q.push(i);
	}
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		topo.push_back(u);
		for (auto v:adj[u]) {
			in[v]--;
			if (!in[v]) q.push(v);
		}
	}
	if (topo.size()<n) {
		cout<<-1;
		return;
	}
	int res=1;
	queue<int>temp;
	for (auto i:topo) {
		if (!check(i)) {
			while (!temp.empty()) {
				done[temp.front()]=true;
				temp.pop();
			}
			res++;
		}
		temp.push(i);
	}
	cout<<res;
}
int job[N+5],pre[1<<16],dp[1<<16],inf=1e9;
void sub2() {
	for (int mask=1;mask<(1<<n);mask++) dp[mask]=inf;
	for (int i=0;i<n;i++) {
		int k;
		cin>>k;
		while (k--) {
			int j;
			cin>>j;
			j--;
			job[i]|=(1<<j);
		}
	}
	for (int mask=0;mask<(1<<n);mask++) {
		for (int i=0;i<n;i++) {
			if (mask>>i&1) pre[mask]|=job[i];
		}
		for (int cur=mask;cur>0;cur=(cur-1)&mask) {
            //cout<<mask<<' '<<cur<<endl;
			if (__builtin_popcount(cur)>m) continue;
			int t=mask^cur;
			if ((pre[cur]&t)==pre[cur]) dp[mask]=min(dp[mask],dp[t]+1);
		}
		//cout<<mask<<' '<<dp[mask]<<endl;
	}
	if (dp[(1<<n)-1]==inf) cout<<-1;
	else cout<<dp[(1<<n)-1];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin>>n>>m;
	if (n<=m) sub1();
	else sub2();
}
