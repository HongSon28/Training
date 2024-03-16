#include<bits/stdc++.h>
using namespace std;
const int N=900;
int vis[N+5][N+5];
int a,b,c;
queue<pair<int,int>>q;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(vis,-1,sizeof(vis));
	cin>>a>>b>>c;
	vis[0][0]=0;
	q.push({0,0});
	while (!q.empty()) {
		int x=q.front().first,y=q.front().second;
		q.pop();
		if (x==c||y==c) {
			cout<<vis[x][y];
			return 0;
		}
		if (vis[a][y]==-1) {
			vis[a][y]=vis[x][y]+1;
			q.push({a,y});
		}
		if (vis[x][b]==-1) {
			vis[x][b]=vis[x][y]+1;
			q.push({x,b});
		}
		if (vis[0][y]==-1) {
			vis[0][y]=vis[x][y]+1;
			q.push({0,y});
		}
		if (vis[x][0]==-1) {
			vis[x][0]=vis[x][y]+1;
			q.push({x,0});
		}
		int t=min(a-x,y);
		if (vis[x+t][y-t]==-1) {
			vis[x+t][y-t]=vis[x][y]+1;
			q.push({x+t,y-t});
		}
		t=min(b-y,x);
		if (vis[x-t][y+t]==-1) {
			vis[x-t][y+t]=vis[x][y]+1;
			q.push({x-t,y+t});
		}
	}
	cout<<-1;
}