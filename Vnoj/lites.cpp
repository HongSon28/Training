#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct node{
	int v0,v1,lazy;
} st[N*4+5];
int n,m;
void build(int id,int l,int r) {
	if (l==r) {
		st[id].v0=1;
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id].v0=st[id*2].v0+st[id*2+1].v0;
}
void down(int id) {
	int temp=st[id].lazy;
	if (temp==0) return;
	st[id].lazy=0;
	st[id*2].lazy^=1;
	st[id*2+1].lazy^=1;
	swap(st[id*2].v0,st[id*2].v1);
	swap(st[id*2+1].v0,st[id*2+1].v1);
}
void update(int id,int l,int r,int u,int v) {
	if (r<u||l>v) return;
	if (u<=l&&r<=v) {
		swap(st[id].v0,st[id].v1);
		st[id].lazy^=1;
		return;
	}
	int mid=(l+r)/2;
	down(id);
	update(id*2,l,mid,u,v);
	update(id*2+1,mid+1,r,u,v);
	st[id].v0=st[id*2].v0+st[id*2+1].v0;
	st[id].v1=st[id*2].v1+st[id*2+1].v1;
}
node get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return {0,0,0};
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	down(id);
	node x=get(id*2,l,mid,u,v);
	node y=get(id*2+1,mid+1,r,u,v);
	return {x.v0+y.v0,x.v1+y.v1,0};
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    build(1,1,n);
    while (m--) {
    	int type,u,v;
    	cin>>type>>u>>v;
    	if (type==0) update(1,1,n,u,v);
    	else {
    		node temp=get(1,1,n,u,v);
    		cout<<temp.v1<<'\n';
    	}
    }	
}