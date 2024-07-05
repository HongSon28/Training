#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,m,a,b;
int x[N+5],y[N+5],z[N+5];
int v[N+5];
int main() {
	freopen("SDC.INP","r",stdin);
	freopen("SDC.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>a>>b;
    for (int i=1;i<=m;i++) cin>>x[i]>>y[i]>>z[i];
    for (int i=1;i<=n;i++) v[i]=b;
    for (int i=1;i<n;i++) {
    	for (int j=1;j<=m;j++) {
    		if (v[y[j]]-v[x[j]]>z[j]) {
    			v[y[j]]=v[x[j]]+z[j];
    			if (v[y[j]]<a) {
    				cout<<"NO";
    				return 0;
    			}
    		}
    	}
    }
    for (int i=1;i<=m;i++) {
    	if (v[y[i]]-v[x[i]]>z[i]) {
    		cout<<"NO";
    		return 0;
    	}
    }
    cout<<"YES"<<'\n';
    for (int i=1;i<=n;i++) cout<<v[i]<<' ';
}