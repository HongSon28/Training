#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
unsigned long long mod=1e9+7;
struct SegmentTree{
	unsigned long long st[N*4+5];
	void update(int id,int l,int r,int pos,unsigned long long val) {
		if (l>pos||r<pos) return;
		if (l==r) {
			st[id]=val;
			return;
		}
		int mid=(l+r)/2;
		update(id*2,l,mid,pos,val);
		update(id*2+1,mid+1,r,pos,val);
		st[id]=(st[id*2]+st[id*2+1])%mod;
	}
	unsigned long long get(int id,int l,int r,int u,int v) {
		if (l>v||r<u||u>v) return 0;
		if (u<=l&&r<=v) return st[id];
		int mid=(l+r)/2;
		return (get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v))%mod;
	}
} tree[12];
int n,k;
int a[N+5];
unsigned long long dp[12][N+5];
int main() {
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	dp[0][i]=1;
    	tree[0].update(1,1,n,a[i],dp[0][i]);
    	for (int j=1;j<=k;j++) {
    		dp[j][i]=tree[j-1].get(1,1,n,1,a[i]-1);
    		tree[j].update(1,1,n,a[i],dp[j][i]);
    	}
    }
    cout<<tree[k].get(1,1,n,1,n);
}
