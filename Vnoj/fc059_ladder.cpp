#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int a[N+5];
int l[N+5],r[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		if (a[i]<=a[i-1]) l[i]=l[i-1]+1;
		else l[i]=1;
	}
	for (int i=n;i>=1;i--) {
		if (a[i]<=a[i+1]) r[i]=r[i+1]+1;
		else r[i]=1;
	}
	while (m--) {
		int u,v;
		cin>>u>>v;
		if (r[u]+l[v]>=v-u+1) cout<<"Yes"<<'\n';
		else cout<<"No"<<'\n';
	}
}