#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m,a,b;
vector<int>adj[N];
int dp[N][(1<<N)],mod=1e9+7;
bool vis[N][(1<<N)];
queue<pair<int,int>>q;
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
    	cin>>a>>b;
    	a--,b--;
    	adj[a].push_back(b);
    }
    dp[0][1]=1;
    q.push({0,1});
    vis[0][1]=true;
    while (!q.empty()) {
    	int u=q.front().first;
    	int mask=q.front().second;
    	q.pop();
    	if (u==n-1) continue;
    	for (auto v:adj[u]) {
    		if (mask>>v&1) continue;
    		int curmask=(mask|(1<<v));
    		add(dp[v][curmask],dp[u][mask]);
    		if (!vis[v][curmask]) {
    			vis[v][curmask]=true;
    			q.push({v,curmask});
    		}
    	}
    }
    cout<<dp[n-1][(1<<n)-1];
}