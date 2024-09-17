#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m;
string s;
int a[N+5];
struct Node{
	int inc,dec,c0,c1,lazy;
} st[N*4+5];
Node merge(Node x,Node y) {
	Node ans;
	ans.lazy=0;
	ans.c0=x.c0+y.c0;
	ans.c1=x.c1+y.c1;
	ans.inc=max(x.c0+y.inc,x.inc+y.c1);
	ans.dec=max(x.dec+y.c0,x.c1+y.dec);
	return ans;
}
void down(int id) {
	if (!st[id].lazy) return;
	st[id].lazy=0;
	st[id*2].lazy^=1;
	swap(st[id*2].inc,st[id*2].dec);
	swap(st[id*2].c0,st[id*2].c1);
	st[id*2+1].lazy^=1;
	swap(st[id*2+1].inc,st[id*2+1].dec);
	swap(st[id*2+1].c0,st[id*2+1].c1);
}
void build(int id,int l,int r) {
	st[id].lazy==0;
	if (l==r) {
		if (!a[l]) {
			st[id].c0=1;
			st[id].c1=0;
		} else {
			st[id].c0=0;
			st[id].c1=1;
		}
		st[id].inc=st[id].dec=1;
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=merge(st[id*2],st[id*2+1]);
}
void update(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return;
	if (u<=l&&r<=v) {
		swap(st[id].c0,st[id].c1);
		swap(st[id].inc,st[id].dec);
		st[id].lazy^=1;
		return;
	}
	int mid=(l+r)/2;
	down(id);
	update(id*2,l,mid,u,v);
	update(id*2+1,mid+1,r,u,v);
	st[id]=merge(st[id*2],st[id*2+1]);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>s;
    for (int i=1;i<=n;i++) a[i]=(s[i-1]=='7');
    build(1,1,n);
    while (m--) {
    	string type;
    	cin>>type;
    	if (type=="count") cout<<st[1].inc<<'\n';
    	else {
    		int l,r;
    		cin>>l>>r;
    		update(1,1,n,l,r);
    	}
    }	
}