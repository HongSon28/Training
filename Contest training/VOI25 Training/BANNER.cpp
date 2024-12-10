#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
int n,q;
string s;
long long mod=1e9+7;
struct Node{
	long long c[6][6];
} st[N*4+5],emp;
Node merge(Node x,Node y){
	Node ans;
	memset(ans.c,0,sizeof(ans.c));
	for (int i=1;i<=5;i++) {
		for (int j=i;j<=5;j++) {
			ans.c[i][j]=x.c[i][j]+y.c[i][j]%mod;
			for (int k=i;k<j;k++){
				ans.c[i][j]+=x.c[i][k]*y.c[k+1][j]%mod;
				ans.c[i][j]%=mod;
			} 
		}
	}
	return ans;
}
void build(int id,int l,int r) {
	if (l==r){
		memset(st[id].c,0,sizeof(st[id].c));
		if (s[l]=='H') st[id].c[1][1]++;
		else if (s[l]=='S') st[id].c[2][2]++;
		else if (s[l]=='G') st[id].c[3][3]++;
		else if (s[l]=='2') st[id].c[4][4]++;
		else st[id].c[5][5]++;
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=merge(st[id*2],st[id*2+1]);
}
Node get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return emp;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
	freopen("BANNER.INP","r",stdin);
	freopen("BANNER.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q>>s;
    s=' '+s;
    memset(emp.c,0,sizeof(emp.c));
    build(1,1,n);
    while (q--) {
    	int l,r;
    	cin>>l>>r;
    	cout<<get(1,1,n,l,r).c[1][5]<<'\n';
    }
}