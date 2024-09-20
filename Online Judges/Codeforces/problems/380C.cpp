#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,q;
string s;
struct Node {
	int mx,c1,c2;
} st[N*4+5];
Node merge(Node x,Node y) {
	Node ans;
	int t=min(x.c1,y.c2);
	ans.mx=x.mx+y.mx+t*2;
	ans.c1=x.c1+y.c1-t;
	ans.c2=x.c2+y.c2-t;
	return ans;
}
void build(int id,int l,int r) {
	if (l==r) {
		st[id]={0,s[l]=='(',s[l]==')'};
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=merge(st[id*2],st[id*2+1]);
}
Node get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return {0,0,0};
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    n=s.size();
    s=' '+s;
    build(1,1,n);
    cin>>q;
    while (q--) {
    	int l,r;
    	cin>>l>>r;
    	cout<<get(1,1,n,l,r).mx<<'\n';
    }
}