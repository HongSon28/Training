#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
string s;
vector<vector<int>>adj(N+5);
stack<int>st;
int node;
int dp[N+5],w[N+5];
string dfs(int u,int par) {
	string ans;
	dp[u]=1;
	vector<pair<int,string>>vc;
	for (auto v:adj[u]) {
		if (v==par) continue;
		string temp=dfs(v,u);
		vc.push_back({dp[v],temp});
		//cout<<u<<' '<<v<<' '<<dp[v]<<endl;
	}
	sort(vc.rbegin(),vc.rend());
	for (int i=0;i<(int)vc.size();i++) {
		dp[u]=max(dp[u],vc[i].first+i);
		ans+=vc[i].second;
	}
	if (w[u]==0) ans+='a';
	else ans+=to_string(w[u]);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>s;
	n=s.size();
	s=' '+s;
	for (int i=1;i<=n;i++) {
		if (s[i]=='a') {
			st.push(++node);
		} else {
			int t=(int)s[i]-'0';
			node++;
			w[node]=t;
			while (t--) {
				int cur=st.top();
				st.pop();
				adj[cur].push_back(node);
				adj[node].push_back(cur);
			}
			st.push(node);
		}
	}
	string res=dfs(node,0);
	cout<<dp[node]<<'\n'<<res;
}