#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
pair<int,int>p[N+5];
long long res,st[N*4+5];
void update(int id,int l,int r,int pos) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]++;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos);
	update(id*2+1,mid+1,r,pos);
	st[id]=st[id*2]+st[id*2+1];
}
long long get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++) {
    	res+=get(1,1,N,p[i].first+1,N);
    	update(1,1,N,p[i].second);
    }
    cout<<res;
}