#include<bits/stdc++.h>
using namespace std;
const int N=1e4,M=100;
int n,q;
int w[N+5],c[N+5];
vector<int>pre[N+5][M+5],suf[N+5][M+5];
void calc(int mid,int l,int r) {
	for (int i=0;i<=M;i++) suf[mid][i].resize(mid-l+2);
	for (int i=mid;i>=l;i--) {
		for (int W=0;W<=M;W++) suf[mid][W][mid-i+1]=suf[mid][W][mid-i];
		for (int W=w[i];W<=M;W++) suf[mid][W][mid-i+1]=max(suf[mid][W][mid-i+1],suf[mid][W-w[i]][mid-i]+c[i]);
	} 
	for (int i=0;i<=M;i++) pre[mid][i].resize(r-mid+2);
	for (int i=mid+1;i<=r;i++) {
		for (int W=0;W<=M;W++) pre[mid][W][i-mid]=pre[mid][W][i-mid-1];
		for (int W=w[i];W<=M;W++) pre[mid][W][i-mid]=max(pre[mid][W][i-mid],pre[mid][W-w[i]][i-mid-1]+c[i]);
	}
}
void solve(int l,int r,int u,int v,int W) {
	int mid=(l+r)/2;
	if (v<=mid) {
		solve(l,mid,u,v,W);
		return;
	}
	if (u>mid) {
		solve(mid+1,r,u,v,W);
		return;
	}
	if (pre[mid][0].empty()) calc(mid,l,r);
	int res=0;
	for (int t=0;t<=W;t++) res=max(res,pre[mid][t][v-mid]+suf[mid][W-t][mid-u+1]);
	cout<<res<<'\n';
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>w[i]>>c[i];
    cin>>q;
    while (q--) {
    	int l,r,W;
    	cin>>l>>r>>W;
    	if (l==r) {
    		if (w[l]<=W) cout<<c[l]<<'\n';
    		else cout<<0<<'\n';
    	} else solve(1,n,l,r,W);
    }
}