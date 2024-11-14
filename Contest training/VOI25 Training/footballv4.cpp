#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,t,k;
int l[N+5],r[N+5];
int c[N+5][N+5];
namespace sub1{
	vector<int>v;
	void solve(int l,int r) {
		v.clear();
		v.push_back(l);
		for (int i=l+1;i<=r;i++) {
			v.push_back(i);
			int cur=v.size()-1;
			while (cur>0) {
				if (c[v[cur]][v[cur-1]]) break;
				swap(v[cur],v[cur-1]);
				cur--;
			}
			//for (auto i:v) cout<<i<<' ';
			//cout<<endl;
		}
		reverse(v.begin(),v.end());
		cout<<v.size()<<' ';
		for (auto i:v) cout<<i<<' ';
		cout<<'\n';
	}
}
namespace sub2{
	queue<pair<int,int>>q;
	bool vis[N+5];
	int trace[N+5];
	bool bfs(int s,int l,int r) {
		memset(vis,false,sizeof(vis));
		memset(trace,0,sizeof(trace));
		while (!q.empty()) q.pop();
		q.push({s,0});
		vis[s]=true;
		while (!q.empty()) {
			int u=q.front().first,d=q.front().second;
			q.pop();
			if (d==2) {
				if (c[u][s]) {
					cout<<3<<' '<<s<<' '<<trace[u]<<' '<<u<<'\n';
					return true;
				}
				continue;
			}
			for (int v=1;v<=n;v++) {
				if (vis[v]||!c[u][v]||v<l||v>r) continue;
				q.push({v,d+1});
				trace[v]=u;
				vis[v]=true;
			}
		}
		return false;
	}
	void solve(int l,int r) {
		for (int i=l;i<=r;i++) {
			if (bfs(i,l,r)) return;
		}
		cout<<-1<<'\n';
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>t>>k;
	for (int i=1;i<=t;i++) cin>>l[i]>>r[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>c[i][j];
	for (int i=1;i<=t;i++) 
		if (k==1) sub1::solve(l[i],r[i]);
		else sub2::solve(l[i],r[i]);
}