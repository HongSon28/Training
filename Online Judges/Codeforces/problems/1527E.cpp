#include<bits/stdc++.h>
using namespace std;
const int N=4e4,K=100;
int n,k;
int a[N+5];
int nxt[N+5];
long long fi[N+5],ls[N+5];
long long dp[N+5][K+5],inf=1e18;
struct SegmentTree{
	long long st[N*4+5],lazy[N*4+5];
	void build(int id,int l,int r,int k) {
		lazy[id]=0;
		if (l==r) {
			st[id]=dp[l-1][k];
			return;
		}
		int mid=(l+r)/2;
		build(id*2,l,mid,k);
		build(id*2+1,mid+1,r,k);
		st[id]=min(st[id*2],st[id*2+1]);
	}
	void down(int id) {
		long long t=lazy[id];
		if (t==0) return;
		st[id*2]+=t,st[id*2+1]+=t;
		lazy[id*2]+=t,lazy[id*2+1]+=t;
		lazy[id]=0;
	}
	void update(int id,int l,int r,int u,int v,int val) {
		if (l>v||r<u) return;
		if (u<=l&&r<=v) {
			st[id]+=val;
			lazy[id]+=val;
			return;
		}
		down(id);
		int mid=(l+r)/2;
		update(id*2,l,mid,u,v,val);
		update(id*2+1,mid+1,r,u,v,val);
		st[id]=min(st[id*2],st[id*2+1]);
	}
	long long get(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return inf;
		if (u<=l&&r<=v) return st[id];
		int mid=(l+r)/2;
		down(id);
		return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
	}
} tree;
void calc(int k) {
	tree.build(1,1,n,k-1);
	for (int i=1;i<=n;i++) {
		if (nxt[i]!=-1) tree.update(1,1,n,1,nxt[i],i-nxt[i]);
		dp[i][k]=tree.get(1,1,n,1,i);
		//if (i==n) 
	}
} 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    memset(fi,-1,sizeof(fi));
    memset(ls,-1,sizeof(ls));
    memset(nxt,-1,sizeof(nxt));
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	dp[i][1]=dp[i-1][1];
    	if (fi[a[i]]!=-1) {
    		dp[i][1]-=ls[a[i]]-fi[a[i]];
    		nxt[i]=ls[a[i]];
    		ls[a[i]]=i;
    	} else {
    		fi[a[i]]=ls[a[i]]=i;
    	}
    	dp[i][1]+=ls[a[i]]-fi[a[i]];
    }	
    for (int i=2;i<=k;i++) {
    	calc(i);
    }
	/*
    for (int i=1;i<=k;i++) {
    	for (int j=1;j<=n;j++) cout<<dp[j][i]<<' ';
    	cout<<endl;
    }*/
    cout<<dp[n][k];
}