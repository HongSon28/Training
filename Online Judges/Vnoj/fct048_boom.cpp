#include<bits/stdc++.h>
using namespace std;
const int N=300;
int n,m,res;
int x[N+5],y[N+5],w[N+5];
int calc(int u,int v,int i) {
	int dist=max(abs(u-x[i]),abs(v-y[i]));
	return max(0,w[i]-dist);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>x[i]>>y[i]>>w[i];
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=n;j++) {
    		int cur=0;
    		for (int x=1;x<=m;x++) cur+=calc(i,j,x);
    		res=max(res,cur);
    	}
    }
    cout<<res;
}