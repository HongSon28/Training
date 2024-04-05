#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,l1,l2;
long long a[N+5],st[N*4+5],dp[N+5];
void update(int id,int l,int r,int pos,long long val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]=val;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id]=max(st[id*2],st[id*2+1]);
}
long long get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return -1;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>l1>>l2;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
    	int l=max(1,i-l2),r=i-l1;
    	dp[i]=a[i];
    	if (l<=r) dp[i]=max(dp[i],get(1,1,n,l,r)+a[i]);
    	update(1,1,n,i,dp[i]);
    	//cout<<l<<' '<<r<<' '<<dp[i]<<endl;
    }
    cout<<st[1];
}