#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
vector<int>adj[N+5];
vector<int>vc[N+5];
int res[N+5];
bool used[N+5];
void dfs(int u,int par,int cur) {
	vc[cur].push_back(u);
	for (auto v:adj[u]) {
		if (v!=par) dfs(v,u,cur+1);
	}
}
int calc(int k) {
	int ans=0;
	for (auto u:vc[k]) {
		if (!used[u]) {
			used[u]=true;
			ans++;
		}
	}
	return ans;
}
pair<int,int>far(int u,int par) {
	pair<int,int>ans={-1,u};
	for (auto v:adj[u]) {
		if (v==par) continue;
		ans=max(ans,far(v,u));
	}
	ans.first++;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }	
    int s=far(1,0).second;
    pair<int,int>temp=far(s,0);
    int t=temp.second,dist=temp.first;
    dfs(s,0,0);
    dfs(t,0,0);
 	for (int i=dist+1;i<=n;i++) res[i]=n;
 	res[dist]=n-1;   
 	used[s]=used[t]=true;
 	res[dist]-=calc(dist);
 	for (int i=dist-1;i>=1;i--) {
 		res[i]=res[i+1];
 		res[i]-=calc(i);
 	}
 	for (int i=1;i<=n;i++) cout<<res[i]<<' ';
}