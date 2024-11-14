#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m,q;
int a[N+5][N+5],sum[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			char c;
			cin>>c;
			if (c=='1') a[i][j]=1;
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
		}
	}
	cin>>q;
	while (q--) {
		int r,c,k;
		int res=0,cur=0;
		cin>>r>>c>>k;
		int x=r,y=c,u=r,v=c;
		int last=0;
		if (a[r][c]) {
			k--;
			last++;
		}
		while (k>0) {
			cur++;
			x++;
			y++;
			u--;
			v--;
			x=min(x,n),y=min(y,m);
			u=max(u,1),v=max(v,1);
			int temp=sum[x][y]-sum[x][v-1]-sum[u-1][y]+sum[u-1][v-1];
			int t=temp-last;
			t=min(t,k);
			k-=t;
			res+=t*cur;
			last=temp;
		}
		cout<<res*2<<'\n';
	}
}