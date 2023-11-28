#include<bits/stdc++.h>
using namespace std;
const int N=1e5,M=256;
int n,k,res;
int r[N+5],g[N+5],b[N+5];
int a[M+5][M+5][M+5],c[M+5][M+5][M+5];
int get(int i,int j,int k,int d) {
	return c[i][j][k]-c[i-d-1][j][k]-c[i][j-d-1][k]-c[i][j][k-d-1]
		   +c[i-d-1][j-d-1][k]+c[i][j-d-1][k-d-1]+c[i-d-1][j][k-d-1]-c[i-d-1][j-d-1][k-d-1];
}
bool check(int d) {
	for (int i=d+1;i<=M;i++) {
		for (int j=d+1;j<=M;j++) {
			for (int p=d+1;p<=M;p++) {
				if (get(i,j,p,d)>=k) return true;
			}
		}
	}
	return false;
}
void trace(int x,int y,int z) {
	for (int i=1;i<=n;i++) {
		if (r[i]>=x&&r[i]<=x+res&&g[i]>=y&&g[i]<=y+res&&b[i]>=z&&b[i]<=z+res) {
			cout<<r[i]-1<<' '<<g[i]-1<<' '<<b[i]-1<<'\n';
			k--;
			if (k==0) return;
		}
	}
}
int main(){
	freopen("PENCILS.INP","r",stdin);
	freopen("PENCILS.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>r[i]>>g[i]>>b[i];
		r[i]++;
		g[i]++;
		b[i]++;
		a[r[i]][g[i]][b[i]]++;
	}
	for (int i=1;i<=M;i++) {
		for (int j=1;j<=M;j++) {
			for (int k=1;k<=M;k++) {
				c[i][j][k]=c[i-1][j][k]+c[i][j-1][k]+c[i][j][k-1]
						  -c[i-1][j-1][k]-c[i-1][j][k-1]-c[i][j-1][k-1]
						  +c[i-1][j-1][k-1]+a[i][j][k];
						  
			}
		}
	}
	int lo=0,hi=255;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (check(mid)) {
			res=mid;
			hi=mid-1;
		} else lo=mid+1;
	}
	cout<<res<<'\n';
	for (int i=res+1;i<=M;i++) {
		for (int j=res+1;j<=M;j++) {
			for (int p=res+1;p<=M;p++) {
				if (get(i,j,p,res)>=k) {
					trace(i-res,j-res,p-res);
					return 0;
				}
			}
		}
	}
}