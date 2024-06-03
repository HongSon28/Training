#include<bits/stdc++.h>
using namespace std;
const int N=169,M=13;
int t,x,y,z,u;
int dp[M+1][N+1][N+1][N+1];
#define get(u,i,y,z) ((i)>=(y) ? dp[u][i][y][z] : ((i)>=(z) ? dp[u][y][i][z] : dp[u][y][z][i]))
void maxi(int &x, const int &y) {
	if (x<y) x=y;
}
void precal(void) {
	for (int u=2;u<=M;++u) {
		for (int x=u;x<=N;++x) {
			for (int y=u;y<=x;++y) {
				for (int z=u;z<=y;++z) {
					int &res=dp[u][x][y][z];
					res=x*y;
					for (int a=u;a<=x/2;++a) maxi(res,get(u,a,y,z)+get(u,x-a,y,z));
					for (int b=u;b<=y/2;++b) maxi(res,get(u,b,x,z)+get(u,y-b,x,z));
					for (int c=u;c<=z/2;++c) maxi(res,get(u,c,x,y)+get(u,z-c,x,y));
				}
			}
		}
	}
}
int main(void) {
	freopen("grassjelly.inp","r",stdin);
	freopen("grassjelly.out","w",stdout);
	precal();
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin>>t;
	while (t--) {
		cin>>x>>y>>z>>u;
		if (x<y) swap(x,y);
		if (x<z) swap(x,z);
		if (y<z) swap(y,z);
		if (u==1) cout<<x*y*z<<'\n';
		else cout<<get(u,x,y,z)<<'\n';
	}
}
