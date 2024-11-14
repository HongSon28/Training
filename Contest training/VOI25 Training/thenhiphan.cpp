#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
int b[N+5],dp[N+5];
int cnt;
vector<int>v[N+5];
int st[N*4+5],inf=1e9;
void build(int id,int l,int r) {
	st[id]=inf;
	if (l==r) return;
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
}
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]=val;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id]=min(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return inf;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>b[i];
    	cnt+=(b[i]==0);
    }
    cin>>m;
    for (int i=1;i<=m;i++) {
    	int l,r;
    	cin>>l>>r;
    	v[l].push_back(r);
    }
    dp[0]=0;
    build(1,1,n);
    for (int i=1;i<=n;i++) dp[i]=inf;
    for (int i=1;i<=n;i++) {
    	for (auto r:v[i]) {
    		int x=min(dp[i-1],get(1,1,n,max(1,i-1),r));
    		if (x<dp[r]) {
    			dp[r]=x;
    			update(1,1,n,r,dp[r]);
    		}
    	}
    	int t=1;
    	if (!b[i]) t=-1;
    	dp[i]=min(dp[i],dp[i-1]+t);
    }
    cout<<dp[n]+cnt;
}