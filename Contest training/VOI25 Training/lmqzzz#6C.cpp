#include<bits/stdc++.h>
using namespace std;
const int N=500,M=3e5;
int n,m,q;
int a[N+5][N+5];
pair<int,int>pos[M+5];
int inf=1e9;
struct Node{
	int mnx,mny,mxx,mxy;
} st[M*4+5];
Node merge(Node x,Node y) {
	Node ans;
	ans.mnx=min(x.mnx,y.mnx);
	ans.mny=min(x.mny,y.mny);
	ans.mxx=max(x.mxx,y.mxx);
	ans.mxy=max(x.mxy,y.mxy);
	return ans;
}
void build(int id,int l,int r) {
	if (l==r) {
		st[id]={pos[l].first,pos[l].second,pos[l].first,pos[l].second};
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=merge(st[id*2],st[id*2+1]);
}
void update(int id,int l,int r,int pos,Node val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]=val;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id]=merge(st[id*2],st[id*2+1]);
}
Node get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return {inf,inf,-inf,-inf};
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			cin>>a[i][j];
			pos[a[i][j]]={i,j};
		}
	}
	build(1,0,n*m-1);
	int cur=0;
	cin>>q;
	while (q--) {
		int type;
		cin>>type;
		if (type==1) {
			int r1,c1,r2,c2;
			cin>>r1>>c1>>r2>>c2;
			update(1,0,n*m-1,a[r1][c1],{r2,c2,r2,c2});
			update(1,0,n*m-1,a[r2][c2],{r1,c1,r1,c1});
			swap(a[r1][c1],a[r2][c2]);
		} else if (type==2) {
			int w;
			cin>>w;
			cur-=w;
			if (cur<0) cur+=n*m;
		} else {
			int r1,c1,r2,c2;
			cin>>r1>>c1>>r2>>c2;
			int res=-1;
			int lo=cur,hi=n*m-1;
			while (lo<=hi) {
				int mid=(lo+hi)/2;
				Node temp=get(1,0,n*m-1,cur,mid);
				//cout<<lo<<' '<<hi<<' '<<cur<<' '<<mid<<' '<<temp.mnx<<' '<<temp.mny<<' '<<temp.mxx<<' '<<temp.mxy<<endl;
				if (temp.mnx<r1||temp.mny<c1||temp.mxx>r2||temp.mxy>c2) {
					res=mid;
					hi=mid-1;
				} else lo=mid+1;
			}
			if (res!=-1) {
				cout<<res-cur<<'\n';
				continue;
			}
			lo=0,hi=cur-1;
			while (lo<=hi) {
				int mid=(lo+hi)/2;
				Node temp=get(1,0,n*m-1,0,mid);
				if (temp.mnx<r1||temp.mny<c1||temp.mxx>r2||temp.mxy>c2) {
					res=mid;
					hi=mid-1;
				} else lo=mid+1;
			}
			if (res!=-1) {
				cout<<res-cur+(n*m)<<'\n';
				continue;
			}
			cout<<-1<<'\n';
		}
	}
}