#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int n,k,q;
int a[N+5];
int f[N+5];
vector<int>adj[N+5];
int col[N+5];
bool dfs(int u) {
	col[u]=1;
	for (auto v:adj[u]) {
		if (!col[v]) {
			if (dfs(v)) return true;
		} else if (col[v]==1) return true;
	}
	col[u]=2;
	return false;
}
bool check(int l,int r) {
	for (int i=1;i<=n;i++) {
		adj[i].clear();
		col[i]=0;
	}
	int cur=0;
	for (int i=l+1;i<=r;i++) {
		if (cur%2==0) {
			adj[a[i]].push_back(a[i-1]);
			//cout<<a[i]<<' '<<a[i-1]<<endl;
		} else {
			adj[a[i-1]].push_back(a[i]);
			//cout<<a[i-1]<<' '<<a[i]<<endl;
		}
		cur++;
	}
	for (int i=1;i<=n;i++) {
		if (col[i]==0) {
			if (dfs(i)) return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k>>q;	
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
    	int lo=i+1,hi=n;
    	f[i]=i;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		if (check(i,mid)) {
    			f[i]=mid;
    			lo=mid+1;
    		} else hi=mid-1;
    	}
    }
    while (q--) {
    	int l,r;
    	cin>>l>>r;
    	if (f[l]>=r) cout<<"YES"<<'\n';
    	else cout<<"NO"<<'\n';
    }
}