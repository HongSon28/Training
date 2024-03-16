#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
long long res;
stack<int>mn,mx;
struct node {
	long long cnt,lazy;
	node operator + (const node &other) const {
		return {cnt+other.cnt,0};
	}
} st[N*4+5];
void build (int id,int l,int r) {
	if (l==r) {
		st[id]={1,0};
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=st[id*2]+st[id*2+1];
}
void down(int id,int l,int r) {
	int mid=(l+r)/2,len1=mid-l+1,len2=r-mid;
	long long t=st[id].lazy;
	st[id].lazy=0;
	st[id*2].cnt = (t%2==0 ? st[id*2].cnt : len1 - st[id*2].cnt);
	st[id*2].lazy+=t;
	st[id*2+1].cnt = (t%2==0 ? st[id*2+1].cnt : len2 - st[id*2+1].cnt);
	st[id*2+1].lazy+=t;
}
void update(int id,int l,int r,int u,int v,long long val) {
	if (l>v||r<u) return;
	if (u<=l&&r<=v) {
		st[id].cnt = (val%2==0 ? st[id].cnt : r-l+1-st[id].cnt);
		st[id].lazy+=val;
		return;
	}
	down(id,l,r);
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	st[id]=st[id*2]+st[id*2+1];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for (int i=1;i<=n;i++) {
    	while (!mn.empty()&&a[mn.top()]>a[i]) {
    		int r=mn.top();
    		mn.pop();
    		int l=(mn.empty() ? 1 : mn.top()+1);
    		update(1,1,n,l,r,a[i]-a[r]);
    	}
    	mn.push(i);
    	while (!mx.empty()&&a[mx.top()]<a[i]) {
    		int r=mx.top();
    		mx.pop();
    		int l=(mx.empty() ? 1 : mx.top()+1);
    		update(1,1,n,l,r,a[i]-a[r]);
    	}
    	mx.push(i);
    	res+=st[1].cnt-(n-i);
    }
    cout<<res;
}