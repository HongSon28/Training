#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,m;
char c[N+5][N+5];
int c1,c2,r1,r2;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool vis[N+5][N+5][3];
struct dat{
	int x,y,t;
};
queue<dat>q;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) 
    	for (int j=1;j<=m;j++)
    		cin>>c[i][j];
 	cin>>r1>>c1>>r2>>c2;
 	q.push({r1,c1,0});
 	vis[r1][c1][0]=true;
 	while (!q.empty()) {
 		dat u=q.front();
 		q.pop();
 		for (int i=0;i<4;i++) {
 			int x=u.x+dx[i];
 			int y=u.y+dy[i];
 			if (x<1||y<1||x>n||y>m) continue;
 			int t=u.t;
 			if (vis[x][y][t]||(u.x==r1&&u.y==c1)) t++;
 			if (t==1&&x==r2&&y==c2&&c[x][y]=='X') {
 				cout<<"YES";
 				return 0;
 			}
 			if (t==2&&x==r2&&y==c2&&c[x][y]=='.') {
 				cout<<"YES";
 				return 0;
 			}
 			if (t>=2||vis[x][y][t]||(t==1&&c[x][y]=='X')) continue;
 			vis[x][y][t]=true;
 			q.push({x,y,t});
 			//cout<<u.x<<' '<<u.y<<' '<<u.t<<' '<<x<<' '<<y<<' '<<t<<endl;
 		}
 	}   	
 	cout<<"NO";
}