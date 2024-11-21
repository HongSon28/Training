#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m;
vector<int>adj[N+5];
bool c[N+5][N+5];
bool dp[N+5];
int col[N+5];
vector<int>v;
int bfs(int s) {
	int s0=1,s1=0;
	queue<int>q;
	q.push(s);
	col[s]=0;
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (auto v:adj[u]) {
			if (col[v]==-1) {
				col[v]=1-col[u];
				q.push(v);
				if (col[v]==0) s0++;
				else s1++;
			} else {
				if (col[v]!=1-col[u]) return -1;
			}
		}
	}
	return abs(s1-s0);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		c[u][v]=c[v][u]=true;
	}
	for (int i=1;i<n;i++) {
		for (int j=i+1;j<=n;j++) {
			if (!c[i][j]) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	int res=n,sum=0;
	memset(col,-1,sizeof(col));
	for (int i=1;i<=n;i++) {
		if (col[i]!=-1) continue;
		int temp=bfs(i);
		if (temp==-1) {
			cout<<-1;
			return 0;
		}
		sum+=temp;
		//cout<<temp<<endl;
		v.push_back(temp);
	}
	res=sum;
	dp[0]=true;
	for (auto x:v) {
		for (int s=sum;s>=x;s--) {
			if (dp[s-x]&&!dp[s]) dp[s]=true;
		}
	}
	for (int i=1;i<=sum;i++) {
		if (dp[i]) res=min(res,abs(i-(sum-i)));
	}
	cout<<res;
}