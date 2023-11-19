#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5;
int n,q;
ll a[N+5],inf=1e18;
struct node{
	ll l,r,dp[2][2],lazy;
	node() {
		dp[0][0]=dp[1][0]=dp[0][1]=dp[1][1]=-inf;
		lazy=0;
	}
	ll get() {
		return max({dp[0][0],dp[1][0],dp[0][1],dp[1][1]});
	}
}st[N*4+5];
node mer (node x,node y) {
	node ans;
	ans.l=x.l;
	ans.r=y.r;
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			for (int k=0;k<2;k++)
				for (int l=0;l<2;l++) {
					if (x.dp[i][j]!=-inf&&y.dp[k][l]!=-inf) {
						ll temp=x.dp[i][j]+y.dp[k][l];
						if (j==0&&k==0) temp+=max(y.l-x.r,0ll);
						if (j==1&&k==1) temp+=max(x.r-y.l,0ll);	
						ans.dp[i][l]=max(ans.dp[i][l],temp);
					}	
				}
	return ans;
}
void build(int id,int l,int r) {
	if (l==r) {
		st[id].l=st[id].r=a[l];
		st[id].dp[0][0]=st[id].dp[1][1]=0;
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=mer(st[id*2],st[id*2+1]);
}
void down(int id) {
	ll temp=st[id].lazy;
	st[id].lazy=0;
	st[id*2].l+=temp;
	st[id*2].r+=temp;
	st[id*2].lazy+=temp;
	st[id*2+1].l+=temp;
	st[id*2+1].r+=temp;
	st[id*2+1].lazy+=temp;
}
void update(int id,int l,int r,int u,int v,ll val) {
	if (l>v||r<u) return;
	if (u<=l&&r<=v) {
		st[id].l+=val;
		st[id].r+=val;
		st[id].lazy+=val;
		return;
	}
	down(id);
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	st[id]=mer(st[id*2],st[id*2+1]);
}
int main() {
	freopen("RECIPE.INP","r",stdin);
	freopen("RECIPE.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while (q--) {
		int l,r,val;
		cin>>l>>r>>val;
		update(1,1,n,l,r,val);
		cout<<st[1].get()<<'\n';
	}
}