#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long c,s;
struct SegmentTree{
	long long lazy[N*4+5],st[N*4+5];
	void down(int id) {
		if (lazy[id]==0) return;
		long long t=lazy[id];
		lazy[id]=0;
		lazy[id*2]+=t,st[id*2]+=t;
		lazy[id*2+1]+=t,st[id*2+1]+=t;
	}
	void update(int id,int l,int r,int u,int v,long long val) {
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
} s1,s2;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    while (n--) {
    	cin>>c>>s;
    	if (s==1) {
    		s1.update(1,1,N,1,c,1);
    		s2.update(1,1,N,1,c,-1);
    	} else {
    		s1.update(1,1,N,1,c,-1);
    		s2.update(1,1,N,1,c,1);
    	}
    	if (s1.st[1]>=0) cout<<">"<<'\n';
    	else if (s2.st[1]>=0) cout<<"<"<<'\n';
    	else cout<<"?"<<'\n';
    }
}