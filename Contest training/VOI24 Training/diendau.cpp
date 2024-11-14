#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
pair<int,int>adj[N+5];
long long w[N+5];
int t,k,cur;
long long num,res;
long long dp[N+5][21];
string s;
char last;
void dfs(int u) {
	if (adj[u].first==0&&adj[u].second==0) {
		dp[u][0]=w[u];
		return;
	}
	dfs(adj[u].first);
	dfs(adj[u].second);
	for (int i=0;i<=k;i++) {
		for (int x=0;x<=i;x++) {
			int y=i-x;
			dp[u][i]=max(dp[u][i],dp[adj[u].first][x]+dp[adj[u].second][y]);
			//cout<<u<<' '<<i<<' '<<dp[u][i]<<' '<<dp[adj[u].first][x]<<' '<<dp[adj[u].second][y]<<endl;
		}
	}
	for (int i=1;i<=k;i++) {
		for (int x=0;x<i;x++) {
			int y=i-1-x;
			dp[u][i]=max(dp[u][i],dp[adj[u].first][x]*dp[adj[u].second][y]);
			//cout<<u<<' '<<i<<' '<<dp[u][i]<<' '<<dp[adj[u].first][x]<<' '<<dp[adj[u].second][y]<<endl;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t>>k;
	while (t--) {
		cur=0;
		res=0;
		last=' ';
		memset(dp,-1,sizeof(dp));
		memset(adj,0,sizeof(adj));
		stack<int>st;
		cin>>s;
		for (auto i:s) {
			if (i=='o'||i=='p'||i=='(') continue;
			if (i>='0'&&i<='9') {
				num*=10;
				num+=i-'0';
			} else if (i==','&&last!=')') {
				w[++cur]=num;
				st.push(cur);
				num=0;
				//cout<<cur<<' '<<w[cur]<<endl;
			} else if (i==')') {
				w[++cur]=num;
				st.push(cur);
				num=0;
				++cur;
				adj[cur].first=st.top();
				//cout<<cur<<' '<<st.top()<<' '<<w[st.top()]<<endl;
				st.pop();
				adj[cur].second=st.top();
				//cout<<cur<<' '<<st.top()<<' '<<w[st.top()]<<endl;
				st.pop();
				st.push(cur);
			}
			last=i;
		} 
		dfs(cur);
		for (int i=0;i<=k;i++) res=max(res,dp[cur][i]);
		cout<<res<<'\n';
	}
}