#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int tt,n;
long long mod=998244353;
vector<vector<int>>adj;
long long res,sum,pw[N+5];
int dfs(int u,int par) {
	vector<int>vc;
	int cur=1;
	long long ssum=0;
	for (auto v:adj[u]) {
		if (v==par) continue;
		int temp=dfs(v,u);
		vc.push_back(temp);
		cur+=temp;
	}
	for (auto t:vc) {
		//cout<<u<<' '<<t<<endl;
		ssum+=t*(t-1)/2;
		ssum+=t*(cur-1-t)/2;
		ssum%=mod;
		ssum+=t*(t-1)/2*(cur-1-t);
		ssum%=mod;
		ssum+=t*(t-1)*(t-2)/6;
		ssum%=mod;
	}
	long long sz=vc.size();
	ssum+=(((sz*(sz-1))%mod)*(sz-2))%mod;
	ssum%=mod;
	cout<<u<<' '<<cur<<' '<<ssum<<endl;
	if (cur>3) ssum*=pw[cur-3];
	ssum%=mod;
	sum+=ssum;
	sum%=mod;
	return cur;
}
int main() {
	pw[0]=1;
	for (int i=1;i<=N;i++) {
		pw[i]=pw[i-1]*2;
		pw[i]%=mod;
	}
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>tt;
    while (tt--) {
    	adj.clear();
    	cin>>n;
    	adj.resize(n+1);
    	res=pw[n],sum=0;
    	for (int i=1;i<n;i++) {
    		int u,v;
    		cin>>u>>v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	dfs(1,0);
    	cout<<sum<<' '<<res<<' '<<((res-sum)%mod+mod)%mod<<'\n';
    }
}