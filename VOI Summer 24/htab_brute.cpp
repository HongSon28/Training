#include<bits/stdc++.h>
using namespace std;
const int N=65;
int n,m,res;
long long a[N][N],b[N][N],k;
bool check(int x,int y,int u,int v,int lx,int ly) {
	for (int i=x;i<=x+lx-1;i++) {
		for (int j=y;j<=y+ly-1;j++) {
			int temp=abs(a[i][j]-b[u+i-x][v+j-y]);
			if (temp>k) return false;
		}
	}
	//cout<<x<<' '<<y<<' '<<u<<' '<<v<<' '<<lx<<' '<<ly<<endl;
	return true;
}
int main() {
    //freopen("htab.inp","r",stdin);
    //freopen("htab.ans","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>a[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>b[i][j];
	for (int x1=1;x1<=n;x1++) {
		for (int x2=x1;x2<=n;x2++) {
			for (int y1=1;y1<=m;y1++) {
				for (int y2=y1;y2<=m;y2++) {
					int lx=x2-x1+1,ly=y2-y1+1;
					for (int u=1;u+lx-1<=n;u++) {
						for (int v=1;v+ly-1<=m;v++) {
							if (check(x1,y1,u,v,lx,ly)) res=max(res,lx*ly);
						}
					}
				}
			}
		}
	}
	cout<<res;
}
