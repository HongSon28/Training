#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long a[N+5],b[N+5],mod=1e9+7,suml[N+5],sumr[N+5],res;
vector<long long>cprs;
struct node{
	long long cnt,val;
	node operator + (const node &other) const {
		return {cnt+other.cnt,(val+other.val)%mod};
	}
} st[N*4+5];
void update(int id,int l,int r,int pos) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id].cnt++;
		st[id].val+=b[pos];
		st[id].val%=mod;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos);
	update(id*2+1,mid+1,r,pos);
	st[id]=st[id*2]+st[id*2+1];
}
node get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return {0,0};
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	cprs.push_back(a[i]);
    }
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=1;i<=n;i++) {
    	int t=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
    	b[t]=a[i];
    	a[i]=t;
    }
    for (int i=1;i<=n;i++) {
    	node t=get(1,1,n,a[i],n);
    	suml[i]+=t.val-t.cnt*b[a[i]]%mod;
    	suml[i]=(suml[i]%mod+mod)%mod;
    	t=get(1,1,n,1,a[i]-1);
    	suml[i]+=t.cnt*b[a[i]]%mod-t.val;
    	suml[i]=(suml[i]%mod+mod)%mod;
    	update(1,1,n,a[i]);
    }
    memset(st,0,sizeof(st));
    for (int i=n;i>=1;i--) {
    	node t=get(1,1,n,a[i],n);
    	sumr[i]+=t.val-t.cnt*b[a[i]]%mod;
    	sumr[i]=(sumr[i]%mod+mod)%mod;
    	t=get(1,1,n,1,a[i]-1);
    	sumr[i]+=t.cnt*b[a[i]]%mod-t.val;
    	sumr[i]=(sumr[i]%mod+mod)%mod;
    	update(1,1,n,a[i]);
    }
    for (int i=2;i<n;i++) {
    	res+=suml[i]*sumr[i]%mod;
    	res%=mod;
    }
    cout<<res;
}