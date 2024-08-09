#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,res,inf=1e9;
int a[N+5],st[N*4+5];
void build (int id,int l,int r) {
	if (l==r) {
		st[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=min(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v) {
	if (u>r||v<l) return inf;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
bool check(int l,int r) {
	int mn=get(1,1,n,l,r);
	return mn>=(1-l);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	a[i]-=i;
    }	
    build(1,1,n);
    for (int i=1;i<=n;i++) {
    	int lo=i,hi=n,r=i;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		if (check(i,mid)) {
    			r=mid;
    			lo=mid+1;
    		} else hi=mid-1;
    	}
    	res=max(res,r-i+1);
    }
    cout<<res;
}