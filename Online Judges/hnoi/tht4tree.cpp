#include<bits/stdc++.h>
using namespace std;
const int N=500,M=4e6;
int m,n,k,q;
bool p[M+5],vis[N+5][N+5],block[N+5][N+5];
vector<int>prime;
long long a[N+5][N+5],sum[N+5][N+5];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void seive() {
	memset(p,true,sizeof(p));
	for (long long i=2;i<=M;i++) {
		if (p[i]) {
			prime.push_back(i);
			for (long long j=i*i;j<=M;j+=i) p[j]=false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    cin>>m>>n>>k>>q;
    for (int i=0;i<=m+1;i++) {
    	for (int j=0;j<=n+1;j++) {
			if (i==0||j==0||i==m+1||j==n+1) vis[i][j]=true;
		}
	} 
	for (int i=1;i<=k;i++) {
		int x,y;
		cin>>x>>y;
		block[x][y]=true;
	}
	int x=1,y=1,cur=0,cnt=1,pos=0;
	if (!block[x][y]) {
		a[x][y]=2;
		pos=1;
	}
	vis[1][1]=true;
	while (true) {
		while (!vis[x+dx[cur]][y+dy[cur]]) {
			cnt++;
			x+=dx[cur];
			y+=dy[cur];
			if (!block[x][y]) {
				a[x][y]=prime[pos];
				pos++;
			}
			vis[x][y]=true;
		}
		if (cnt==n*m) break; 
		cur++;
		if (cur==4) cur-=4;
	}
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=n;j++) {
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		}
	}
	while (q--) {
		int u1,v1,u2,v2;
		cin>>u1>>v1>>u2>>v2;
		cout<<sum[u2][v2]-sum[u1-1][v2]-sum[u2][v1-1]+sum[u1-1][v1-1]<<'\n';
	}
}