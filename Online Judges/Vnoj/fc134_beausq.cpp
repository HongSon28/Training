#include<bits/stdc++.h>
using namespace std;
const int N=2e4;
int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int st[105][N*4+5];
int n,q;
int a[N+5];
void build(int id,int l,int r) {
	if (l==r) {
		st[a[l]][id]++;
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	for (int i=0;i<25;i++) st[prime[i]][id]=st[prime[i]][id*2]+st[prime[i]][id*2+1];
}
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[val][id]++;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	for (int i=1;i<=100;i++) st[i][id]=st[i][id*2]+st[i][id*2+1];
}
int get(int i,int id,int l,int r,int u,int v) {
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return st[i][id];
	int mid=(l+r)/2;
	return get(i,id*2,l,mid,u,v)+get(i,id*2+1,mid+1,r,u,v);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	for (int j=0;j<25;j++) {
    		while (a[i]%prime[j]==0) {
    			a[i]/=prime[j];
    			update(1,1,n,i,prime[j]);
    		}
    	}
    }
    cin>>q;
    while (q--) {
    	int type;
    	cin>>type;
    	if (type==1) {
    		int l,r;
    		bool flag=true;
    		cin>>l>>r;
    		for (int i=0;i<25;i++) {
    			int temp=get(prime[i],1,1,n,l,r);
    			if (temp%2==1) {
    				flag=false;
    				break;
    			}
    		}
    		if (flag) cout<<"YES"<<'\n';
    		else cout<<"NO"<<'\n';
    	} else {
    		int i,val;
    		cin>>i>>val;
    		for (int j=0;j<25;j++) {
    			while (val%prime[j]==0) {
    				update(1,1,n,i,prime[j]);
    				val/=prime[j];
    			}
    		}
    	}
    }
}