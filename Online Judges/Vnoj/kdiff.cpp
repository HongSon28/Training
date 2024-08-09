#include<bits/stdc++.h>
using namespace std;
const int N=3e5,LG=__lg(N+5);
int n,k;
int a[N+5],b[N+5],f[N+5],mx[N+5][LG+5],mn[N+5][LG+5],res;
vector<pair<int,int>>v;
int st[N*4+5];
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]=max(st[id],val);
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id]=max(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v) {
	if (l>v||r<u||u>v) return 0;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
void build() {
	for (int i=1;i<=LG;i++) {
		for (int j=1;j<=n-(1<<i)+1;j++) {
			mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
			mn[j][i]=min(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
		}	
	}
}
int getmax(int l,int r) {
	int k=__lg(r-l+1);
	return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
int getmin(int l,int r) {
	int k=__lg(r-l+1);
	return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	mx[i][0]=mn[i][0]=a[i];
    }
    build();
    for (int i=1;i<=n;i++) {
    	int lo=i,hi=n,ans=i;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		if (getmax(i,mid)-getmin(i,mid)>k) hi=mid-1;
    		else {
    			lo=mid+1;
    			ans=mid;
    		}
    	}
    	v.push_back({i,ans});
    	b[i]=max(b[i],ans-i+1);
    }
    for (int i=n;i>=1;i--) f[i]=max(f[i+1],b[i]);
    for (auto [l,r]:v) {
    	int temp=f[r+1];
    	res=max(res,r-l+1+temp);
    }
    cout<<res;
}